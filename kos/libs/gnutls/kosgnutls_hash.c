#include "kosgnutls.h"
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <assert.h>


int gnutls_hash(gnutls_hash_hd_t handle, const void *ptext, size_t ptext_len)
{
    EVP_MD_CTX *ctx = handle;

    if (EVP_sha512() == EVP_MD_CTX_md(ctx)) {
        ;
    } else if (EVP_md5() == EVP_MD_CTX_md(ctx)) {
        ;
    } else {
        assert(0 && "Unknown cipher");
    }

    int res = EVP_DigestUpdate(ctx, ptext, ptext_len);
    assert(res == 1 && "HASH Update");

    return 0;
}

void gnutls_hash_output(gnutls_hash_hd_t handle, void *digest)
{
    EVP_MD_CTX *ctx = handle;

    unsigned int s = 0;
    int res = EVP_DigestFinal_ex(ctx, digest, &s);
    assert(res == 1 && "Final failed");
    fprintf(stderr, "Res of final: %u\n", s);

    // @todo: rework
    EVP_DigestInit(ctx, EVP_sha512());
}

int gnutls_hash_fast(gnutls_digest_algorithm_t algorithm,
                     const void *ptext, size_t ptext_len, void *digest)
{
    return -1;
}


unsigned gnutls_hash_get_len(gnutls_digest_algorithm_t algorithm)
{
    if (algorithm == GNUTLS_MAC_SHA256) {
        // @todo: magic number
        return 32;
    }
    return 0;
}

int gnutls_hash_init(gnutls_hash_hd_t * dig, gnutls_digest_algorithm_t algorithm)
{
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    int res = 0;

    switch (algorithm) {
        case GNUTLS_DIG_MD5: {
            res = EVP_DigestInit(ctx, EVP_md5());
            break;
        }
        case GNUTLS_DIG_SHA512: {
            res = EVP_DigestInit(ctx, EVP_sha512());
            break;
        }
        default: {
            EVP_MD_CTX_free(ctx);
            assert(0 && "HASH unknown algo");
        }
    }

    assert(res == 1 && "Init failed");

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