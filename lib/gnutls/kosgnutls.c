#include "kosgnutls.h"
#include <openssl/rand.h>


int gnutls_rnd(gnutls_rnd_level_t level, void *data, size_t len)
{
    RAND_bytes(data, (int)len);
    return 0;
}

int gnutls_aead_cipher_encrypt(gnutls_aead_cipher_hd_t handle,
                               const void *nonce, size_t nonce_len,
                               const void *auth, size_t auth_len,
                               size_t tag_size,
                               const void *ptext, size_t ptext_len,
                               void *ctext, size_t *ctext_len)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return -1;
}

int gnutls_aead_cipher_encryptv2(gnutls_aead_cipher_hd_t handle,
                                 const void *nonce, size_t nonce_len,
                                 const giovec_t *auth_iov, int auth_iovcnt,
                                 const giovec_t *iov, int iovcnt,
                                 void *tag, size_t *tag_size)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return -1;
}

int gnutls_aead_cipher_decrypt(gnutls_aead_cipher_hd_t handle,
                               const void *nonce, size_t nonce_len,
                               const void *auth, size_t auth_len,
                               size_t tag_size,
                               const void *ctext, size_t ctext_len,
                               void *ptext, size_t *ptext_len)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return -1;
}

int gnutls_aead_cipher_decryptv2(gnutls_aead_cipher_hd_t handle,
                                 const void *nonce, size_t nonce_len,
                                 const giovec_t *auth_iov, int auth_iovcnt,
                                 const giovec_t *iov, int iovcnt,
                                 void *tag, size_t tag_size)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return -1;
}

int gnutls_aead_cipher_init(gnutls_aead_cipher_hd_t *handle,
                            gnutls_cipher_algorithm_t cipher,
                            const gnutls_datum_t *key)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return -1;
}

void gnutls_aead_cipher_deinit(gnutls_aead_cipher_hd_t handle)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    (void)handle;
}

int gnutls_global_init(void)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return -1;
}