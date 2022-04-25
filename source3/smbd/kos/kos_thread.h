#ifndef KOS_THREAD
#define KOS_THREAD

#define KOS_NO_FORK

#ifdef KOS_NO_FORK

struct kos_conn_data {
    struct dcesrv_context *dce_ctx;
    int fd;
};

struct smbXsrv_client;

int kos_run_conn(struct kos_conn_data data);
void kos_unreg_thread();
void kos_lock_poll_mtx();
void kos_unlock_poll_mtx();
void kos_reg_global_smbXsrv_client(struct smbXsrv_client *global_smbXsrv_client);
struct smbXsrv_client *kos_get_global_smbXsrv_client();

#endif

#endif