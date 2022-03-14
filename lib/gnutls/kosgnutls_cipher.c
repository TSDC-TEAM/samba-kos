#include <memory.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include "kosgnutls.h"


static const EVP_CIPHER *gnutls_2_openssl_cipher(gnutls_cipher_algorithm_t cipher)
{
    switch (cipher) {
        case GNUTLS_CIPHER_ARCFOUR_128: {
            return EVP_rc4();
        }
        default: {
            return NULL;
        }
    }
}

int gnutls_cipher_encrypt(gnutls_cipher_hd_t handle, void *ptext, size_t ptext_len)
{
    EVP_CIPHER_CTX *ctx = (EVP_CIPHER_CTX *)handle;

    unsigned char out[BSIZE] = {0};
    int outl;

    int res_update = EVP_EncryptUpdate(ctx, out, &outl, ptext, (int)ptext_len);
    if (1 != res_update) {
        fprintf(stderr, "CIPHER: encryption failed\n");
        return GNUTLS_E_ENCRYPTION_FAILED;
    }

    if (outl != ptext_len) {
        fprintf(stderr, "CIPHER: encryption failed\n");
        return GNUTLS_E_ENCRYPTION_FAILED;
    }

    memcpy(ptext, out, outl);

    return 0;
}

int gnutls_cipher_decrypt(gnutls_cipher_hd_t handle, void *ctext, size_t ctext_len)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return GNUTLS_E_DECRYPTION_FAILED;
}

unsigned gnutls_cipher_get_tag_size(gnutls_cipher_algorithm_t algorithm)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return 0;
}

unsigned gnutls_cipher_get_iv_size(gnutls_cipher_algorithm_t algorithm)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return 0;
}

size_t gnutls_cipher_get_key_size(gnutls_cipher_algorithm_t algorithm)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return 0;
}

int gnutls_cipher_init(gnutls_cipher_hd_t *handle,
                       gnutls_cipher_algorithm_t cipher,
                       const gnutls_datum_t *key, const gnutls_datum_t *iv)
{
    const EVP_CIPHER *cphr = gnutls_2_openssl_cipher(cipher);
    if (!cphr) {
        fprintf(stderr, "CIPHER: unknown algorithm\n");
        return GNUTLS_E_UNKNOWN_CIPHER_TYPE;
    }

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);

    int res_init = EVP_EncryptInit_ex(ctx, EVP_rc4(), NULL, NULL, NULL);
    if (!res_init) {
        fprintf(stderr, "CIPHER: initialization failed\n");
        EVP_CIPHER_CTX_free(ctx);
        return GNUTLS_E_CRYPTO_INIT_FAILED;
    }

    EVP_CIPHER_CTX_set_key_length(ctx, (int)key->size);

    res_init = EVP_EncryptInit_ex(ctx, NULL, NULL, (const unsigned char *)key->data, NULL);
    if (!res_init) {
        fprintf(stderr, "CIPHER: initialization failed\n");
        EVP_CIPHER_CTX_free(ctx);
        return GNUTLS_E_CRYPTO_INIT_FAILED;
    }

    *handle = (gnutls_cipher_hd_t)ctx;

    return 0;
}

void gnutls_cipher_deinit(gnutls_cipher_hd_t handle)
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
        fprintf(stderr, "CIPHER: final failed\n");
    } else {
        if (0 != outl) {
            fprintf(stderr, "CIPHER: some data remains\n");
        }
    }

    EVP_CIPHER_CTX_free(ctx);
}