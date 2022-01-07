#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include "kosgnutls.h"


int gnutls_cipher_init(gnutls_cipher_hd_t * handle,
                       gnutls_cipher_algorithm_t cipher,
                       const gnutls_datum_t * key, const gnutls_datum_t * iv)
{
    if (cipher != GNUTLS_CIPHER_ARCFOUR_128) {
        fprintf(stderr, "CIPHER unknown\n");
        exit(1);
    }

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);

    int res_init = EVP_EncryptInit_ex(ctx, EVP_rc4(), NULL, NULL, NULL);
    if (!res_init) {
        fprintf(stderr, "CIPHER Init 1 failed\n");
        exit(1);
    }

    EVP_CIPHER_CTX_set_key_length(ctx, (int)key->size);

    res_init = EVP_EncryptInit_ex(ctx, NULL, NULL, (const unsigned char *)key, NULL);
    if (!res_init) {
        fprintf(stderr, "CIPHER Init 2 failed\n");
        exit(1);
    }

    *handle = ctx;

    return 0;
}

void gnutls_cipher_deinit(gnutls_cipher_hd_t handle)
{
    unsigned char out[1028] = {0};
    int outl;

    EVP_CIPHER_CTX *ctx = handle;
    int res_fin = EVP_EncryptFinal_ex(ctx, out, &outl);
    if (!res_fin) {
        fprintf(stderr, "Fin failed\n");
        exit(1);
    }

    if (0 != outl) {
        fprintf(stderr, "CIPHER fin failed\n");
        exit(1);
    }

    EVP_CIPHER_CTX_free(ctx);
}

int gnutls_cipher_encrypt(gnutls_cipher_hd_t handle, void *ptext,
                          size_t ptext_len)
{
    EVP_CIPHER_CTX *ctx = handle;

    unsigned char out[1028] = {0};
    int outl;
    int res_update = EVP_EncryptUpdate(ctx, out, &outl, ptext, (int)ptext_len);
    if (!res_update) {
        fprintf(stderr, "CIPHER Update failed\n");
        exit(1);
    }

    if (outl != ptext_len) {
        fprintf(stderr, "CIPHER res len failed\n");
        exit(1);
    }

    memcpy(ptext, out, outl);

    return 0;
}

int gnutls_cipher_decrypt(gnutls_cipher_hd_t handle, void *ctext,
                          size_t ctext_len)
{
    return -1;
}

unsigned gnutls_cipher_get_tag_size(gnutls_cipher_algorithm_t algorithm)
{
    return 0;
}

unsigned gnutls_cipher_get_iv_size(gnutls_cipher_algorithm_t algorithm)
{
    return 0;
}

size_t gnutls_cipher_get_key_size(gnutls_cipher_algorithm_t algorithm)
{
    return 0;
}