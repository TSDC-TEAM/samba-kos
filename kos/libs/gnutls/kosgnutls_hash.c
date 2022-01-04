#include "kosgnutls.h"
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <assert.h>


int gnutls_hash(gnutls_hash_hd_t handle, const void *ptext, size_t ptext_len)
{
    EVP_MD_CTX *ctx = handle;
    int res = EVP_DigestUpdate(ctx, ptext, ptext_len);
    assert(res == 1 && "HASH Update");

    return 0;
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
    if (algorithm != GNUTLS_DIG_MD5) {
        assert(0 && "HASH unknown algo");
    }

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    int res = EVP_DigestInit(ctx, EVP_md5());
    assert(res == 1 && "HASH Init");

    *dig = ctx;

    return 0;
}

void gnutls_hash_deinit(gnutls_hash_hd_t handle, void *digest)
{
    EVP_MD_CTX *ctx = handle;
    unsigned int s = 0;

    int res = EVP_DigestFinal(ctx, digest, &s);
    assert(res == 1 && "HASH Fin");
    assert(s == 16 && "HASH 16 != 16");

    EVP_MD_CTX_free(ctx);
}