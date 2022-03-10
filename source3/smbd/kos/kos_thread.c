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


struct kos_thread_data {
    pthread_t *thread;
    struct kos_conn_data *local_data;
    atomic_int done;
    struct kos_thread_data *next;
};

pthread_mutex_t g_mutex;
#undef sprintf

void *thread_proc(void *tmp) {
    struct kos_thread_data *data = (struct kos_thread_data *)tmp;

    struct tevent_context *child_ev = NULL;
    struct messaging_context *child_msg_ctx = NULL;

    pthread_mutex_lock(&g_mutex);

    static int i = 0;
    char b[8] = {0};
    sprintf(b, "%d", ++i);
    TALLOC_CTX *ctx = talloc_named_const(NULL, 0, b);
    child_ev = tevent_context_init(ctx);
    child_msg_ctx = messaging_init(ctx, child_ev);
    messaging_reinit(child_msg_ctx);

    pthread_mutex_unlock(&g_mutex);

    smbd_process(child_ev, child_msg_ctx, data->local_data->dce_ctx, data->local_data->fd, false);

    data->done = 1;

    // @todo: free ctx and ev

    return NULL;
}

static struct kos_thread_data *head = NULL;

int kos_run_conn(struct kos_conn_data data) {
    static int first_run = 1;
    if (first_run) {
        pthread_mutex_init(&g_mutex, NULL);
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
    new_one->next = NULL;

    struct kos_thread_data *it = head;
    if (it) {
        while (it->next) {
            it = it->next;
        }
        it->next = new_one;
    } else {
        head = new_one;
    }

    pthread_create(thread, NULL, thread_proc, new_one);

    it = head;
    do {
        if (it && it->next && it->next->done) {
            pthread_join(*it->next->thread, NULL);
            free(it->next->thread);
            free(it->next->local_data);
            void *for_free = it->next;
            it->next = it->next->next;
            free(for_free);
            it = head;
            continue;
        } else if (it && it->done) {
            pthread_join(*it->thread, NULL);
            free(it->thread);
            free(it->local_data);
            head = it->next;
            free(it);
            it = head;
            continue;
        }
        it = it->next;
    } while (it);

    return 0;
}

#endif