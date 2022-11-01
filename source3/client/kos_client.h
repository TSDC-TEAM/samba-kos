#ifndef SAMBA_KOS_CLIENT_H
#define SAMBA_KOS_CLIENT_H

typedef struct kos_client_ls_stat_s {
    char *name;
    size_t size;
    int is_dir;
    struct kos_client_ls_stat_s *next;
} kos_client_ls_stat_t;

int kos_client_connect(const char *address, int port, const char *user, const char *password);
void kos_client_disconnect();
int kos_client_get_file(const char *remote_name, const char *local_name);
int kos_client_put_file(const char *remote_name, const char *local_name);
int kos_client_ls(const char *mask, kos_client_ls_stat_t **stat);
void kos_client_ls_stat_free(kos_client_ls_stat_t *stat);
int kos_client_mkdir(const char *remote_name);
int kos_client_rm(const char *mask);
int kos_client_rmdir(const char *mask);

#endif
