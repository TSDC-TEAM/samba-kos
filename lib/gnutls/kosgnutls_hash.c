#include "kosgnutls.h"
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <openssl/sha.h>


static const EVP_MD *gnutls_2_openssl_digest(gnutls_digest_algorithm_t algorithm)
{
    switch (algorithm) {
        case GNUTLS_DIG_MD5: {
            return EVP_md5();
        }
        case GNUTLS_DIG_SHA512: {
            return EVP_sha512();
        }
        default: {
            return NULL;
        }
    }
}

int gnutls_hash(gnutls_hash_hd_t handle, const void *ptext, size_t ptext_len)
{
    EVP_MD_CTX *ctx = (EVP_MD_CTX *)handle;

    int res = EVP_DigestUpdate(ctx, ptext, ptext_len);
    if (1 != res) {
        fprintf(stderr, "HASH: failed\n");
        return GNUTLS_E_HASH_FAILED;
    }

    return 0;
}

void gnutls_hash_output(gnutls_hash_hd_t handle, void *digest)
{
    EVP_MD_CTX *ctx = (EVP_MD_CTX *)handle;
    const EVP_MD *algo = EVP_MD_CTX_md(ctx);

    unsigned int s = 0;
    int res = EVP_DigestFinal_ex(ctx, digest, &s);
    if (1 != res) {
        fprintf(stderr, "HASH: output failed\n");
    }

    EVP_DigestInit(ctx, algo);
}

int gnutls_hash_fast(gnutls_digest_algorithm_t algorithm,
                     const void *ptext, size_t ptext_len, void *digest)
{
    fprintf(stderr, "%s: function not implemented\n", __func__);
    return GNUTLS_E_HASH_FAILED;
}


unsigned gnutls_hash_get_len(gnutls_digest_algorithm_t algorithm)
{
    switch (algorithm) {
        case GNUTLS_DIG_MD5:
            return MD5_DIGEST_LENGTH;
        case GNUTLS_DIG_SHA256:
            return SHA256_DIGEST_LENGTH;
        default:
            fprintf(stderr, "HASH: unknown algo len request\n");
            return GNUTLS_E_UNKNOWN_HASH_ALGORITHM;
    }
}

int gnutls_hash_init(gnutls_hash_hd_t *dig, gnutls_digest_algorithm_t algorithm)
{
    const EVP_MD *algo = gnutls_2_openssl_digest(algorithm);
    if (!algo) {
        fprintf(stderr, "HASH: unknown algorithm\n");
        return GNUTLS_E_UNKNOWN_HASH_ALGORITHM;
    }

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();

    int res = EVP_DigestInit(ctx, algo);
    if (1 != res) {
        EVP_MD_CTX_free(ctx);
        fprintf(stderr, "HASH: initialization failed\n");
        return GNUTLS_E_CRYPTO_INIT_FAILED;
    }

    *dig = (gnutls_hash_hd_t)ctx;

    return 0;
}

void gnutls_hash_deinit(gnutls_hash_hd_t handle, void *digest)
{
    EVP_MD_CTX *ctx = (EVP_MD_CTX *)handle;

    if (!ctx) {
        return;
    }

    if (!digest) {
        EVP_MD_CTX_free(ctx);
        return;
    }

    unsigned int s = 0;
    int res_fin = EVP_DigestFinal(ctx, digest, &s);
    if (1 != res_fin) {
        fprintf(stderr, "HASH: final failed\n");
    }

    EVP_MD_CTX_free(ctx);
}