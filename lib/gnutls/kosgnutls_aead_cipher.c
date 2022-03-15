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
    ssize_t ret;
    uint8_t *p;
    size_t len;
    ssize_t blocksize = 16;
    struct iov_iter_st iter;
    size_t _tag_size;

    if (tag_size == NULL || *tag_size == 0) {
        _tag_size = 16;
    } else {
        _tag_size = *tag_size;
    }

    EVP_CIPHER_CTX *ctx = (EVP_CIPHER_CTX *)handle;

    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, nonce_len, NULL)) {
        fprintf(stderr, "AEAD: initialization failed\n");
        return GNUTLS_E_CRYPTO_INIT_FAILED;
    }

    if (1 != EVP_EncryptInit_ex(ctx, NULL, NULL, NULL, nonce)) {
        fprintf(stderr, "AEAD: initialization failed\n");
        return GNUTLS_E_CRYPTO_INIT_FAILED;
    }

    ret = gnutls_iov_iter_init(&iter, auth_iov, auth_iovcnt, blocksize);
    if (ret < 0) {
        fprintf(stderr, "AEAD: iov iter initialization failed\n");
        return GNUTLS_E_CRYPTO_INIT_FAILED;
    }

    while (1) {
        ret = gnutls_iov_iter_next(&iter, &p);
        if (ret < 0) {
            fprintf(stderr, "AEAD: encryption failed while getting iov iter next\n");
            return GNUTLS_E_ENCRYPTION_FAILED;
        }
        if (ret == 0) {
            break;
        }
        EVP_EncryptUpdate(ctx, NULL, &len, p, ret);
        if (ret < 0) {
            fprintf(stderr, "AEAD: encryption failed\n");
            return GNUTLS_E_ENCRYPTION_FAILED;
        }
    }

    ret = gnutls_iov_iter_init(&iter, iov, iovcnt, blocksize);
    if (ret < 0) {
        fprintf(stderr, "AEAD: iov iter initialization failed\n");
        return GNUTLS_E_CRYPTO_INIT_FAILED;
    }

    while (1) {
        ret = gnutls_iov_iter_next(&iter, &p);
        if (ret < 0) {
            fprintf(stderr, "AEAD: encryption failed while getting iov iter next\n");
            return GNUTLS_E_ENCRYPTION_FAILED;
        }
        if (ret == 0) {
            break;
        }

        len = ret;
        ret = gnutls_cipher_encrypt(handle, p, len);
        if (ret < 0) {
            fprintf(stderr, "AEAD: encryption failed\n");
            return GNUTLS_E_ENCRYPTION_FAILED;
        }

        ret = gnutls_iov_iter_sync(&iter, p, len);
        if (ret < 0) {
            fprintf(stderr, "AEAD: encryption failed while iov iter was synced\n");
            return GNUTLS_E_ENCRYPTION_FAILED;
        }
    }

    if (tag != NULL) {
        int unused;
        EVP_EncryptFinal_ex(ctx, NULL, &unused);
        if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, 16, tag)) {
            fprintf(stderr, "AEAD: finalize encryption failed\n");
            return GNUTLS_E_ENCRYPTION_FAILED;
        }
    }

    if (tag_size != NULL) {
        *tag_size = _tag_size;
    }

    return 0;
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

    int res_init = EVP_EncryptInit_ex(ctx, cphr, NULL, NULL, NULL);
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

    *handle = (gnutls_aead_cipher_hd_t)ctx;

    return 0;
}

void gnutls_aead_cipher_deinit(gnutls_aead_cipher_hd_t handle)
{
    EVP_CIPHER_CTX *ctx = (EVP_CIPHER_CTX *)handle;
    if (!ctx) {
        return;
    }

    unsigned char out[BSIZE];
    int outl;

    // @todo: temporary checking, remove after debug
    int res_fin = EVP_EncryptFinal_ex(ctx, out, &outl);
    if (1 != res_fin) {
        fprintf(stderr, "AEAD: final failed\n");
    } else {
        if (0 != outl) {
            fprintf(stderr, "AEAD: some data remains\n");
        }
    }

    EVP_CIPHER_CTX_free(ctx);
}