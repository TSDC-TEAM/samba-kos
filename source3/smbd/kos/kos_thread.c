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
    struct tevent_context *child_ev;
    struct messaging_context *child_msg_ctx;
    atomic_int done;
    pid_t thread_id;
    struct smbXsrv_client *global_smbXsrv_client;
    struct smbXsrv_session *session;
    struct smbd_server_connection *sconn;
    struct share_mode_data *mode_data;
    int share_mode_data_refcount;
    unsigned char share_mode_lock_key_data[sizeof(struct file_id)];
    struct TDB_DATA share_mode_lock_key;
    int share_mode_lock_key_refcount;
    char *LastDir;
};

KHASH_MAP_INIT_INT(m32, struct kos_thread_data *)
pthread_mutex_t g_hash_kos_thread_mutex;
khash_t(m32) *g_hash_kos_thread_map;

pthread_mutex_t g_init_mutex;
pthread_mutex_t g_poll_mutex;
#undef sprintf

void kos_lock_poll_mtx() {
    pthread_mutex_lock(&g_poll_mutex);
}

void kos_unlock_poll_mtx() {
    pthread_mutex_unlock(&g_poll_mutex);
}

void kos_reg_global_smbXsrv_client(struct smbXsrv_client *global_smbXsrv_client) {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    p->global_smbXsrv_client = global_smbXsrv_client;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);
}

struct smbXsrv_client *kos_get_global_smbXsrv_client() {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    struct smbXsrv_client *ret = p->global_smbXsrv_client;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return ret;
}

void kos_reg_share_mode_data(struct share_mode_data *p_in) {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    p->mode_data = p_in;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);
}

struct share_mode_data *kos_get_share_mode_data() {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    struct share_mode_data *ret = p->mode_data;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return ret;
}

void kos_set_share_mode_data_refcount(int mode_data_refcount) {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    p->share_mode_data_refcount = mode_data_refcount;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);
}

int kos_get_share_mode_data_refcount() {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    int ret = p->share_mode_data_refcount;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return ret;
}

void kos_set_share_mode_lock_key_refcount(int share_mode_lock_key_refcount) {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    p->share_mode_lock_key_refcount = share_mode_lock_key_refcount;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);
}

int kos_get_share_mode_lock_key_refcount() {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    int ret = p->share_mode_lock_key_refcount;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return ret;
}

void kos_set_last_dir(char *last_dir) {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    p->LastDir = last_dir;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);
}

char *kos_get_last_dir() {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    char *ret = p->LastDir;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return ret;
}

struct TDB_DATA kos_get_share_mode_lock_key() {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    struct TDB_DATA ret = p->share_mode_lock_key;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return ret;
}

unsigned char *kos_get_share_mode_lock_key_data() {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    unsigned char *ret = p->share_mode_lock_key_data;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return ret;
}

void kos_reg_smbXsrv_session(struct smbXsrv_session *session) {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    p->session = session;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);
}

struct smbXsrv_session *kos_get_smbXsrv_session(unsigned long long old_session_wire_id) {
    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    for (khint_t k = kh_begin(g_hash_kos_thread_map); k != kh_end(g_hash_kos_thread_map); ++k) {
        if (kh_exist(g_hash_kos_thread_map, k)) {
            struct kos_thread_data *t = kh_value(g_hash_kos_thread_map, k);
            if (t->session->local_id == old_session_wire_id) {
                struct smbXsrv_session *ret = t->session;
                pthread_mutex_unlock(&g_hash_kos_thread_mutex);
                return ret;
            }
        }
    }

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return NULL;
}

void kos_reg_smbd_server_connection(struct smbd_server_connection *sconn) {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    p->sconn = sconn;

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);
}

struct files_struct *kos_get_files_struct(struct smbd_server_connection *sconn, struct file_id id,
                                          unsigned long file_id) {
    // @todo: TMP
    return NULL;

    int count=0;
    files_struct *fsp;
    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    for (khint_t k = kh_begin(g_hash_kos_thread_map); k != kh_end(g_hash_kos_thread_map); ++k) {
        if (kh_exist(g_hash_kos_thread_map, k)) {
            struct kos_thread_data *t = kh_value(g_hash_kos_thread_map, k);
            sconn = t->sconn;
            if (sconn == NULL) {
                continue;
            }
            for (fsp = sconn->files; fsp; fsp = fsp->next,count++) {
                if (!file_id_equal(&fsp->file_id, &id)) {
                    continue;
                }
                if (!fsp->fsp_flags.is_fsa) {
                    continue;
                }
                if (fh_get_gen_id(fsp->fh) != file_id) {
                    continue;
                }
                if (count > 10) {
                    DLIST_PROMOTE(sconn->files, fsp);
                }
                if ((fsp_get_pathref_fd(fsp) == -1) &&
                    (fsp->oplock_type != NO_OPLOCK &&
                     fsp->oplock_type != LEASE_OPLOCK))
                {
                    struct file_id_buf idbuf;

                    DBG_ERR("file %s file_id = "
                            "%s, gen = %u oplock_type = %u is a "
                            "stat open with oplock type !\n",
                            fsp_str_dbg(fsp),
                            file_id_str_buf(fsp->file_id, &idbuf),
                            (unsigned int)fh_get_gen_id(fsp->fh),
                            (unsigned int)fsp->oplock_type);
                    smb_panic("file_find_dif");
                }
                struct files_struct *ret = fsp;
                pthread_mutex_unlock(&g_hash_kos_thread_mutex);
                return ret;
            }
        }
    }

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return NULL;
}

int kos_smbXsrv_session_find_channel(const struct smbXsrv_session *session,
                                     const struct smbXsrv_connection *conn,
                                     struct smbXsrv_channel_global0 **_c)
{
    uint32_t i;

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    for (khint_t k = kh_begin(g_hash_kos_thread_map); k != kh_end(g_hash_kos_thread_map); ++k) {
        if (kh_exist(g_hash_kos_thread_map, k)) {
            struct kos_thread_data *t = kh_value(g_hash_kos_thread_map, k);
            session = t->session;
            if (session == NULL ||  session->global == NULL) {
                continue;
            }
            for (i=0; i < session->global->num_channels; i++) {
                struct smbXsrv_channel_global0 *c = &session->global->channels[i];

                if (c->channel_id != conn->channel_id) {
                    continue;
                }

                if (c->connection != conn) {
                    continue;
                }

                *_c = c;
                pthread_mutex_unlock(&g_hash_kos_thread_mutex);
                return 0;
            }
        }
    }

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    return 1;
}

static void reg_thread(struct kos_thread_data *data) {
    int ret;
    pid_t my_id = gettid();
    data->thread_id = my_id;

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_put(m32, g_hash_kos_thread_map, my_id, &ret);
    if (ret > 0) {
        kh_value(g_hash_kos_thread_map, k) = data;
    } else {
        assert(0);
    }

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);
}

void kos_unreg_thread() {
    pid_t my_id = gettid();

    pthread_mutex_lock(&g_hash_kos_thread_mutex);

    khint_t k = kh_get(m32, g_hash_kos_thread_map, my_id);
    int miss = (kh_end(g_hash_kos_thread_map) == k);
    if (miss) {
        assert(0);
    }
    struct kos_thread_data *p = kh_val(g_hash_kos_thread_map, k);
    p->done = true;
    p->sconn = NULL;
    p->mode_data = NULL;
    close(p->local_data->fd);

    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    kos_unreg_ts();
    kos_unlock_poll_mtx();
}

static void *thread_proc(void *tmp) {
    struct kos_thread_data *data = (struct kos_thread_data *)tmp;

    reg_thread(data);

    pthread_mutex_lock(&g_init_mutex);

    data->child_ev = tevent_context_init(NULL);
    data->child_msg_ctx = messaging_init(NULL, data->child_ev);
    messaging_reinit(data->child_msg_ctx);
    data->sconn = NULL;
    data->session = NULL;
    data->global_smbXsrv_client = NULL;
    data->mode_data = NULL;
    data->share_mode_data_refcount = 0;
    data->share_mode_lock_key.dptr = data->share_mode_lock_key_data;
    data->share_mode_lock_key.dsize = sizeof(data->share_mode_lock_key_data);
    data->share_mode_lock_key_refcount = 0;
    data->LastDir = NULL;

    pthread_mutex_unlock(&g_init_mutex);

    smbd_process(data->child_ev, data->child_msg_ctx, data->local_data->dce_ctx, data->local_data->fd, false);

    data->done = true;

    return NULL;
}

int kos_run_conn(struct kos_conn_data data) {
    static int first_run = 1;
    if (first_run) {
        pthread_mutex_init(&g_init_mutex, NULL);
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&g_poll_mutex, &attr);
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
    new_one->done = false;

    pthread_mutex_lock(&g_hash_kos_thread_mutex);
    for (khint_t k = kh_begin(g_hash_kos_thread_map); k != kh_end(g_hash_kos_thread_map); ++k) {
        if (kh_exist(g_hash_kos_thread_map, k)) {
            struct kos_thread_data *t = kh_value(g_hash_kos_thread_map, k);
            if (t->done) {
                pthread_join(*t->thread, NULL);
                free(t->thread);
                free(t->local_data);
                messaging_cleanup(t->child_msg_ctx, 0);
                free(t);
                kh_del_m32(g_hash_kos_thread_map, k);
                k = kh_begin(g_hash_kos_thread_map);
            }
        }
    }
    pthread_mutex_unlock(&g_hash_kos_thread_mutex);

    pthread_create(thread, NULL, thread_proc, new_one);

    return 0;
}

#endif