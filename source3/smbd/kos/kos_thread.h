#ifndef KOS_THREAD
#define KOS_THREAD

#define KOS_NO_FORK

#ifdef KOS_NO_FORK

struct kos_conn_data {
    struct dcesrv_context *dce_ctx;
    int fd;
};

struct smbXsrv_client;
struct smbXsrv_session;
struct smbd_server_connection;
struct file_id;
struct smbXsrv_connection;
struct smbXsrv_channel_global0;
struct share_mode_data;

int kos_run_conn(struct kos_conn_data data);
void kos_unreg_thread();
void kos_lock_poll_mtx();
void kos_unlock_poll_mtx();
void kos_reg_global_smbXsrv_client(struct smbXsrv_client *global_smbXsrv_client);
struct smbXsrv_client *kos_get_global_smbXsrv_client();
void kos_reg_smbXsrv_session(struct smbXsrv_session *session);
struct smbXsrv_session *kos_get_smbXsrv_session(unsigned long long old_session_wire_id);
void kos_reg_smbd_server_connection(struct smbd_server_connection *sconn);
struct files_struct *kos_get_files_struct(struct smbd_server_connection *sconn, struct file_id id,
                                          unsigned long file_id);
int kos_smbXsrv_session_find_channel(const struct smbXsrv_session *session,
                                     const struct smbXsrv_connection *conn,
                                     struct smbXsrv_channel_global0 **_c);
void kos_reg_share_mode_data(struct share_mode_data *p);
struct share_mode_data *kos_get_share_mode_data();
void kos_set_share_mode_data_refcount(int mode_data_refcount);
int kos_get_share_mode_data_refcount();

#endif

#endif