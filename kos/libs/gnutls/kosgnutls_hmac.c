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
    (void)handle;
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
    if (algorithm != GNUTLS_MAC_MD5) {
        fprintf(stderr, "Unknown HMAC algo\n");
        exit(1);
    }

    HMAC_CTX *ctx = HMAC_CTX_new();
    int res_init = HMAC_Init_ex(ctx, key, (int)keylen, EVP_md5(), NULL);
    if (!res_init) {
        fprintf(stderr, "HMAC Init failed\n");
        exit(1);
    }

    *dig = ctx;

    return 0;
//
//    return _gnutls_mac_init(((mac_hd_st *) * dig),
//                            mac_to_entry(algorithm), key, keylen);
}

void gnutls_hmac_deinit(gnutls_hmac_hd_t handle, void *digest)
{
    HMAC_CTX *ctx = (HMAC_CTX *)handle;
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