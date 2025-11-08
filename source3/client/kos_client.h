#ifndef SAMBA_KOS_CLIENT_H
#define SAMBA_KOS_CLIENT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct kos_client_ls_stat_s {
    char *name;
    size_t size;
    int is_dir;
    struct kos_client_ls_stat_s *next;
} kos_client_ls_stat_t;

/**
 * @brief Connect to the Samba server.
 *
 * @param[in]   address         ip-address of the Samba server
 * @param[in]   port            port of the Samba server
 * @param[in]   user            user name
 * @param[in]   password        user password
 *
 * @return                      0 on success, 1 on failure.
 */
int kos_client_connect(const char *address, int port, const char *user, const char *password);

/**
 * @brief Disconnect from the Samba server.
 */
void kos_client_disconnect();

/**
 * @brief Copy a file from the Samba server to a local machine.
 *
 * @param[in]   remote_name     path to the file on the Samba server
 * @param[in]   local_name      path to the file on a local machine
 *
 * @return                      0 on success, 1 on failure.
 */
int kos_client_get_file(const char *remote_name, const char *local_name);

/**
 * @brief Copy a file from a local machine to the Samba server.
 *
 * @param[in]   remote_name     path to the file on the Samba server
 * @param[in]   local_name      path to the file on a local machine
 *
 * @return                      0 on success, 1 on failure.
 */
int kos_client_put_file(const char *remote_name, const char *local_name);

/**
 * @brief Get contents of a directory on the Samba server.
 *
 * @note `kos_client_ls_stat_free` should be called to free allocated memory.
 *
 * @param[in]   mask            mask used to get the contents of the directory on the Samba server
 * @param[out]  stat            pointer to a structure that will store information
 *                              about the contents of the directory
 *
 * @return                      0 on success, 1 on failure.
 */
int kos_client_ls(const char *mask, kos_client_ls_stat_t **stat);

/**
 * @brief Frees memory previously allocated by `kos_client_ls` for `kos_client_ls_stat_t`.
 *
 * @param[in]   stat            pointer to a structure that `kos_client_ls` return
 */
void kos_client_ls_stat_free(kos_client_ls_stat_t *stat);

/**
 * @brief Delete files on the Samba server.
 *
 * @param[in]   mask            mask used to delete files on the Samba server
 *
 * @return                      0 on success, 1 on failure.
 */
int kos_client_rm(const char *mask);

/**
 * @brief Create a directory on the Samba server.
 *
 * @param[in]   remote_name     path to the directory on the Samba server
 *
 * @return                      0 on success, 1 on failure.
 */
int kos_client_mkdir(const char *remote_name);

/**
 * @brief Delete directories on the Samba server.
 *
 * @param[in]   mask            mask used to delete directories on the Samba server
 *
 * @return                      0 on success, 1 on failure.
 */
int kos_client_rmdir(const char *mask);

#ifdef __cplusplus
}
#endif

#endif
