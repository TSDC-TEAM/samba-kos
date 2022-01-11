#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include "kosgnutls.h"


int gnutls_hmac(gnutls_hmac_hd_t handle, const void *ptext, size_t ptext_len)
{
    HMAC_CTX *ctx = (HMAC_CTX *)handle;
    int res_update = HMAC_Update(ctx, ptext, ptext_len);
    if (!res_update) {
        fprintf(stderr, "HMAC Update failed\n");
        exit(1);
    }

    return 0;
}

void gnutls_hmac_output(gnutls_hmac_hd_t handle, void *digest)
{
    HMAC_CTX *ctx = handle;

    unsigned int resultlen = 0;
    int res_fin = HMAC_Final(ctx, digest, &resultlen);
    if (!res_fin) {
        fprintf(stderr, "HMAC Fin failed\n");
        exit(1);
    }

    assert(resultlen != 0);

    int res_init = HMAC_Init_ex(ctx, NULL, NULL, NULL, NULL);
    if (!res_init) {
        fprintf(stderr, "Reinit failed\n");
        exit(1);
    }
}

int gnutls_hmac_fast(gnutls_mac_algorithm_t algorithm,
                     const void *key, size_t keylen,
                     const void *ptext, size_t ptext_len, void *digest)
{
    if (algorithm != GNUTLS_MAC_MD5) {
        fprintf(stderr, "Unknown algo HMAC fast\n");
        exit(1);
    }

    unsigned int resultlen = 0;
    digest = HMAC(EVP_md5(), key, (int)keylen, ptext, ptext_len, digest, &resultlen);
    if (!digest) {
        fprintf(stderr, "HMAC fast failed\n");
        exit(1);
    }

    return 0;
}

int gnutls_hmac_init(gnutls_hmac_hd_t * dig,
                 gnutls_mac_algorithm_t algorithm,
                 const void *key, size_t keylen)
{
    HMAC_CTX *ctx = HMAC_CTX_new();
    int res = 0;

    switch (algorithm) {
        case GNUTLS_MAC_MD5: {
            res = HMAC_Init_ex(ctx, key, (int)keylen, EVP_md5(), NULL);
            break;
        }
        case GNUTLS_MAC_SHA256: {
            res = HMAC_Init_ex(ctx, key, (int)keylen, EVP_sha256(), NULL);
            break;
        }
        default: {
            assert(0 && "HASH unknown algo");
        }
    }

    assert(res == 1 && "Init failed");

    *dig = ctx;

    return 0;
}

void gnutls_hmac_deinit(gnutls_hmac_hd_t handle, void *digest)
{
    HMAC_CTX *ctx = (HMAC_CTX *)handle;

    if (!digest) {
        HMAC_CTX_free(ctx);
        return;
    }

    unsigned int resultlen = 0;
    int res_fin = HMAC_Final(ctx, digest, &resultlen);
    if (!res_fin) {
        fprintf(stderr, "HMAC Fin failed\n");
        exit(1);
    }

    if (resultlen != 16) {
        fprintf(stderr, "HMAC Fin failed 16 != 16\n");
        exit(1);
    }

    HMAC_CTX_free(ctx);
}