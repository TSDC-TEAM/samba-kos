#include "kosgnutls.h"
#include "kosgnutls_private.h"

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
    const EVP_CIPHER *cphr = gnutls_2_openssl_cipher(cipher);
    if (!cphr) {
        fprintf(stderr, "AEAD: unknown algorithm\n");
        return GNUTLS_E_UNKNOWN_CIPHER_TYPE;
    }

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);

    int res_init = EVP_EncryptInit_ex(ctx, EVP_rc4(), NULL, NULL, NULL);
    if (!res_init) {
        fprintf(stderr, "AEAD: initialization failed\n");
        EVP_CIPHER_CTX_free(ctx);
        return GNUTLS_E_CRYPTO_INIT_FAILED;
    }

    EVP_CIPHER_CTX_set_key_length(ctx, (int)key->size);

    res_init = EVP_EncryptInit_ex(ctx, NULL, NULL, (const unsigned char *)key->data, NULL);
    if (!res_init) {
        fprintf(stderr, "AEAD: initialization failed\n");
        EVP_CIPHER_CTX_free(ctx);
        return GNUTLS_E_CRYPTO_INIT_FAILED;
    }

    *handle = (gnutls_cipher_hd_t)ctx;

    return 0;
}

void gnutls_aead_cipher_deinit(gnutls_aead_cipher_hd_t handle)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    (void)handle;
}