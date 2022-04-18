#include "kos_thread.h"

#ifdef KOS_NO_FORK

#include <pthread.h>

#include "includes.h"
#include "smbd/smbd.h"
#include "libcli/auth/schannel.h"
#include "rpc_server/rpc_service_setup.h"
#include "passdb.h"
#include "messages.h"
#include "lib/id_cache.h"
#include "lib/smbd_shim.h"
#include "lib/util/sys_rw.h"
#include "cleanupdb.h"
#include <stdatomic.h>
#include <lib/klib/khash.h>


struct kos_thread_data {
    pthread_t *thread;
    struct kos_conn_data *local_data;
    atomic_int done;
};

KHASH_MAP_INIT_INT(m32, struct kos_thread_data *)
pthread_mutex_t g_hash_kos_thread_mutex;
khash_t(m32) *g_hash_kos_thread_map;

pthread_mutex_t g_init_mutex;
#undef sprintf

static void reg_thread(struct kos_thread_data *data) {
    int ret;
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_put(m32, g_hash_kos_thread_map, my_id, &ret);
    if (ret > 0) {
        kh_value(g_hash_kos_thread_map, k) = data;
    } else {
        assert(0);
    }

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);
}

static void *thread_proc(void *tmp) {
    struct kos_thread_data *data = (struct kos_thread_data *)tmp;

    reg_thread(data);

    struct tevent_context *child_ev = NULL;
    struct messaging_context *child_msg_ctx = NULL;

    pthread_mutex_lock(&g_init_mutex);

    static int i = 0;
    char b[8] = {0};
    sprintf(b, "%d", ++i);
    TALLOC_CTX *ctx = talloc_named_const(NULL, 0, b);
    child_ev = tevent_context_init(ctx);
    child_msg_ctx = messaging_init(ctx, child_ev);
    messaging_reinit(child_msg_ctx);

    pthread_mutex_unlock(&g_init_mutex);

    smbd_process(child_ev, child_msg_ctx, data->local_data->dce_ctx, data->local_data->fd, false);

    data->done = 1;

    // @todo: free ctx and ev

    return NULL;
}

int kos_run_conn(struct kos_conn_data data) {
    static int first_run = 1;
    if (first_run) {
        pthread_mutex_init(&g_init_mutex, NULL);
        pthread_mutex_init(&g_hash_kos_thread_mutex, NULL);
        g_hash_kos_thread_map = kh_init(m32);
        first_run = 0;
    }

    pthread_t *thread = (pthread_t *)malloc(sizeof(pthread_t));

    struct kos_conn_data *local_data = (struct kos_conn_data *)malloc(sizeof(struct kos_conn_data));
    local_data->dce_ctx = data.dce_ctx;
    local_data->fd = data.fd;

    struct kos_thread_data *new_one = (struct kos_thread_data *)malloc(sizeof(struct kos_thread_data));
    new_one->local_data = local_data;
    new_one->thread = thread;
    new_one->done = 0;

    pthread_create(thread, NULL, thread_proc, new_one);

    pthread_mutex_lock(&g_hash_kos_thread_mutex);
    for (khint_t k = kh_begin(h); k != kh_end(g_hash_kos_thread_map); ++k) {
        if (kh_exist(g_hash_kos_thread_map, k)) {
            struct kos_thread_data *t = kh_value(g_hash_kos_thread_map, k);
            if (t->done) {
                kh_del_m32(g_hash_kos_thread_map, k);
                k = kh_begin(h);
            }
        }
    }
    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return 0;
}

#endif