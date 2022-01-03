#include "kosgnutls.h"
#include <openssl/rand.h>


int gnutls_hash(gnutls_hash_hd_t handle, const void *ptext, size_t ptext_len)
{
    return -1;
}

void gnutls_hash_output(gnutls_hash_hd_t handle, void *digest)
{
    (void)handle;
}

int gnutls_hash_fast(gnutls_digest_algorithm_t algorithm,
                     const void *ptext, size_t ptext_len, void *digest)
{
    return -1;
}


unsigned gnutls_hash_get_len(gnutls_digest_algorithm_t algorithm)
{
    return 0;
}

int gnutls_hash_init(gnutls_hash_hd_t * dig, gnutls_digest_algorithm_t algorithm)
{
    return -1;
}

void gnutls_hash_deinit(gnutls_hash_hd_t handle, void *digest)
{
    (void)handle;
}

int gnutls_rnd(gnutls_rnd_level_t level, void *data, size_t len)
{
    return -1;
}

int gnutls_aead_cipher_encrypt(gnutls_aead_cipher_hd_t handle,
                               const void *nonce, size_t nonce_len,
                               const void *auth, size_t auth_len,
                               size_t tag_size,
                               const void *ptext, size_t ptext_len,
                               void *ctext, size_t *ctext_len)
{
    return -1;
}

int gnutls_aead_cipher_encryptv2(gnutls_aead_cipher_hd_t handle,
                                 const void *nonce, size_t nonce_len,
                                 const giovec_t *auth_iov, int auth_iovcnt,
                                 const giovec_t *iov, int iovcnt,
                                 void *tag, size_t *tag_size)
{
    return -1;
}

int gnutls_aead_cipher_decrypt(gnutls_aead_cipher_hd_t handle,
                               const void *nonce, size_t nonce_len,
                               const void *auth, size_t auth_len,
                               size_t tag_size,
                               const void *ctext, size_t ctext_len,
                               void *ptext, size_t *ptext_len)
{
    return -1;
}

int gnutls_aead_cipher_decryptv2(gnutls_aead_cipher_hd_t handle,
                                 const void *nonce, size_t nonce_len,
                                 const giovec_t *auth_iov, int auth_iovcnt,
                                 const giovec_t *iov, int iovcnt,
                                 void *tag, size_t tag_size)
{
    return -1;
}

int gnutls_aead_cipher_init(gnutls_aead_cipher_hd_t *handle,
                            gnutls_cipher_algorithm_t cipher,
                            const gnutls_datum_t *key)
{
    return -1;
}

void gnutls_aead_cipher_deinit(gnutls_aead_cipher_hd_t handle)
{
    (void)handle;
}

int gnutls_global_init(void)
{
    return -1;
}