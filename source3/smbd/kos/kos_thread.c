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

void *thread_proc(void *tmp) {
    struct kos_thread_data *data = (struct kos_thread_data *)tmp;

    struct tevent_context *child_ev = NULL;
    struct messaging_context *child_msg_ctx = NULL;

    child_ev = samba_tevent_context_init(NULL);
    tevent_re_initialise(child_ev);
    child_msg_ctx = messaging_init(NULL, child_ev);
    messaging_reinit(child_msg_ctx);

    smbd_process(child_ev, child_msg_ctx, data->local_data->dce_ctx, data->local_data->fd, false);

    data->done = 1;

    // @todo: free ctx and ev

    return NULL;
}

static struct kos_thread_data *head = NULL;

int kos_run_conn(struct kos_conn_data data) {
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