#include <memory.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/cmac.h>
#include "kosgnutls.h"


static const EVP_MD *gnutls_2_openssl_digest(gnutls_mac_algorithm_t algorithm)
{
    switch (algorithm) {
        case GNUTLS_MAC_MD5: {
            return EVP_md5();
        }
        case GNUTLS_MAC_SHA256: {
            return EVP_sha256();
        }
        default: {
            return NULL;
        }
    }
}

static const EVP_CIPHER *gnutls_2_openssl_cmac(gnutls_mac_algorithm_t algorithm)
{
    switch (algorithm) {
        case GNUTLS_MAC_AES_CMAC_128:
            return EVP_aes_128_cbc();
        default: {
            return NULL;
        }
    }
}

int gnutls_hmac(gnutls_hmac_hd_t handle, const void *ptext, size_t ptext_len)
{
    HMAC_CTX *ctx = (HMAC_CTX *)handle;

    const EVP_MD *check = HMAC_CTX_get_md(ctx);
    if (check == EVP_md5() || check == EVP_sha256()) {
        int res_update = HMAC_Update(ctx, ptext, ptext_len);
        if (1 != res_update) {
            fprintf(stderr, "HMAC: update failed\n");
            return GNUTLS_E_HASH_FAILED;
        }

        return 0;
    } else {
        int res_update = CMAC_Update(ctx, ptext, ptext_len);
        if (1 != res_update) {
            fprintf(stderr, "CMAC: update failed\n");
            return GNUTLS_E_HASH_FAILED;
        }

        return 0;
    }
}

void gnutls_hmac_output(gnutls_hmac_hd_t handle, void *digest)
{
    HMAC_CTX *ctx = (HMAC_CTX *)handle;

    const EVP_MD *check = HMAC_CTX_get_md(ctx);
    if (check == EVP_md5() || check == EVP_sha256()) {
        unsigned int resultlen = 0;
        int res_fin = HMAC_Final(ctx, digest, &resultlen);
        if (1 != res_fin || 0 == resultlen) {
            fprintf(stderr, "HMAC: output failed\n");
        }

        int res_init = HMAC_Init_ex(ctx, NULL, NULL, NULL, NULL);
        if (!res_init) {
            fprintf(stderr, "HMAC: reinitialization failed\n");
        }
    } else {
        unsigned int resultlen = 0;
        int res_fin = CMAC_Final(ctx, digest, &resultlen);
        if (1 != res_fin || 0 == resultlen) {
            fprintf(stderr, "CMAC: output failed\n");
        }
        int res_init = CMAC_Init(ctx, NULL, 0, NULL, NULL);
        if (!res_init) {
            fprintf(stderr, "CMAC: reinitialization failed\n");
        }
    }
}

int gnutls_hmac_fast(gnutls_mac_algorithm_t algorithm,
                     const void *key, size_t keylen,
                     const void *ptext, size_t ptext_len, void *digest)
{
    const EVP_MD *algo = gnutls_2_openssl_digest(algorithm);
    if (!algo) {
        fprintf(stderr, "HMAC: unknown algorithm\n");
        return GNUTLS_E_UNKNOWN_HASH_ALGORITHM;
    }

    unsigned int resultlen = 0;
    digest = HMAC(algo, key, (int)keylen, ptext, ptext_len, digest, &resultlen);
    if (!digest || 0 == resultlen) {
        fprintf(stderr, "HMAC: fast failed\n");
        return GNUTLS_E_HASH_FAILED;
    }

    return 0;
}

int gnutls_hmac_init(gnutls_hmac_hd_t * dig,
                     gnutls_mac_algorithm_t algorithm,
                     const void *key, size_t keylen)
{
    const EVP_MD *algo = gnutls_2_openssl_digest(algorithm);
    if (!algo) {
        const EVP_CIPHER *c = gnutls_2_openssl_cmac(algorithm);
        if (!c) {
            fprintf(stderr, "HMAC: unknown algorithm\n");
            return GNUTLS_E_UNKNOWN_HASH_ALGORITHM;
        }

        CMAC_CTX *ctx = CMAC_CTX_new();
        int res_cmac = CMAC_Init(ctx, key, keylen, c, NULL);
        if (1 != res_cmac) {
            CMAC_CTX_free(ctx);
            fprintf(stderr, "CMAC: initialization failed\n");
            return GNUTLS_E_CRYPTO_INIT_FAILED;
        }
        *dig = (gnutls_hmac_hd_t)ctx;
        return 0;
    }

    HMAC_CTX *ctx = HMAC_CTX_new();

    int res = HMAC_Init_ex(ctx, key, (int)keylen, algo, NULL);
    if (1 != res) {
        HMAC_CTX_free(ctx);
        fprintf(stderr, "HMAC: initialization failed\n");
        return GNUTLS_E_CRYPTO_INIT_FAILED;
    }

    *dig = (gnutls_hmac_hd_t)ctx;

    return 0;
}

void gnutls_hmac_deinit(gnutls_hmac_hd_t handle, void *digest)
{
    HMAC_CTX *ctx = (HMAC_CTX *)handle;
    if (!ctx) {
        return;
    }

    if (!digest) {
        HMAC_CTX_free(ctx);
        return;
    }

    unsigned int resultlen = 0;
    int res_fin = HMAC_Final(ctx, digest, &resultlen);
    if (1 != res_fin) {
        fprintf(stderr, "HMAC: final failed\n");
    }

    HMAC_CTX_free(ctx);
}