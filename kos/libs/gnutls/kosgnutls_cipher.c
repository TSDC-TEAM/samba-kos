#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include "kosgnutls.h"

#define GNUTLS_CIPHER_AES_192_GCM GNUTLS_CIPHER_AES_128_GCM

struct nettle_cipher_ctx;
struct nettle_cipher_st;

typedef void (*encrypt_func) (struct nettle_cipher_ctx*,
                              size_t length,
                              uint8_t * dst,
                              const uint8_t * src);

void encrypt_func_real(struct nettle_cipher_ctx* ctx,
                              size_t length,
                              uint8_t * dst,
                              const uint8_t * src) {

}
typedef void (*decrypt_func) (struct nettle_cipher_ctx* ctx,
                              size_t length, uint8_t *dst,
                              const uint8_t *src);

void decrypt_func_real(struct nettle_cipher_ctx* ctx,
                              size_t length, uint8_t *dst,
                              const uint8_t *src) {

}

typedef void (*aead_encrypt_func) (struct nettle_cipher_ctx*,
                                   size_t nonce_size, const void *nonce,
                                   size_t auth_size, const void *auth,
                                   size_t tag_size,
                                   size_t length, uint8_t * dst,
                                   const uint8_t * src);
typedef int (*aead_decrypt_func) (struct nettle_cipher_ctx*,
                                  size_t nonce_size, const void *nonce,
                                  size_t auth_size, const void *auth,
                                  size_t tag_size,
                                  size_t length, uint8_t * dst,
                                  const uint8_t * src);

typedef void (*gen_setkey_func) (void *ctx, size_t length, const uint8_t *);

void gen_setkey_func_real(void *ctx, size_t length, const uint8_t *data) {

}

static const cipher_entry_st algorithms[] = {
        { .name = "AES-256-CBC",
                .id = GNUTLS_CIPHER_AES_256_CBC,
                .blocksize = 16,
                .keysize = 32,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "AES-192-CBC",
                .id = GNUTLS_CIPHER_AES_192_CBC,
                .blocksize = 16,
                .keysize = 24,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "AES-128-CBC",
                .id = GNUTLS_CIPHER_AES_128_CBC,
                .blocksize = 16,
                .keysize = 16,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "AES-128-GCM",
                .id = GNUTLS_CIPHER_AES_128_GCM,
                .blocksize = 16,
                .keysize = 16,
                .type = CIPHER_AEAD,
                .implicit_iv = 4,
                .explicit_iv = 8,
                .cipher_iv = 12,
                .tagsize = 16},
        { .name = "AES-192-GCM",
                .id = GNUTLS_CIPHER_AES_192_GCM,
                .blocksize = 16,
                .keysize = 24,
                .type = CIPHER_AEAD,
                .implicit_iv = 4,
                .explicit_iv = 8,
                .cipher_iv = 12,
                .tagsize = 16},
        { .name = "AES-256-GCM",
                .id = GNUTLS_CIPHER_AES_256_GCM,
                .blocksize = 16,
                .keysize = 32,
                .type = CIPHER_AEAD,
                .implicit_iv = 4,
                .explicit_iv = 8,
                .cipher_iv = 12,
                .tagsize = 16},
        { .name = "AES-128-CCM",
                .id = GNUTLS_CIPHER_AES_128_CCM,
                .blocksize = 16,
                .keysize = 16,
                .type = CIPHER_AEAD,
                .implicit_iv = 4,
                .explicit_iv = 8,
                .cipher_iv = 12,
                .flags = GNUTLS_CIPHER_FLAG_ONLY_AEAD,
                .tagsize = 16},
        { .name = "AES-256-CCM",
                .id = GNUTLS_CIPHER_AES_256_CCM,
                .blocksize = 16,
                .keysize = 32,
                .type = CIPHER_AEAD,
                .implicit_iv = 4,
                .explicit_iv = 8,
                .cipher_iv = 12,
                .flags = GNUTLS_CIPHER_FLAG_ONLY_AEAD,
                .tagsize = 16},
        { .name = "AES-128-CCM-8",
                .id = GNUTLS_CIPHER_AES_128_CCM_8,
                .blocksize = 16,
                .keysize = 16,
                .type = CIPHER_AEAD,
                .implicit_iv = 4,
                .explicit_iv = 8,
                .cipher_iv = 12,
                .flags = GNUTLS_CIPHER_FLAG_ONLY_AEAD,
                .tagsize = 8},
        { .name = "AES-256-CCM-8",
                .id = GNUTLS_CIPHER_AES_256_CCM_8,
                .blocksize = 16,
                .keysize = 32,
                .type = CIPHER_AEAD,
                .implicit_iv = 4,
                .explicit_iv = 8,
                .cipher_iv = 12,
                .flags = GNUTLS_CIPHER_FLAG_ONLY_AEAD,
                .tagsize = 8},
        { .name = "ARCFOUR-128",
                .id = GNUTLS_CIPHER_ARCFOUR_128,
                .blocksize = 1,
                .keysize = 16,
                .type = CIPHER_STREAM,
                                       0, 0, 0, 0},
        { .name = "ESTREAM-SALSA20-256",
                .id = GNUTLS_CIPHER_ESTREAM_SALSA20_256,
                .blocksize = 64,
                .keysize = 32,
                .type = CIPHER_STREAM, 0, 0, 8, 0},
        { .name = "SALSA20-256",
                .id = GNUTLS_CIPHER_SALSA20_256,
                .blocksize = 64,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .explicit_iv = 0,
                .cipher_iv = 8},
        { .name = "CHACHA20-32",
                .id = GNUTLS_CIPHER_CHACHA20_32,
                .blocksize = 64,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .explicit_iv = 0,
                /* IV includes counter */
                .cipher_iv = 16},
        { .name = "CHACHA20-64",
                .id = GNUTLS_CIPHER_CHACHA20_64,
                .blocksize = 64,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .explicit_iv = 0,
                /* IV includes counter */
                .cipher_iv = 16},
        { .name = "CAMELLIA-256-CBC",
                .id = GNUTLS_CIPHER_CAMELLIA_256_CBC,
                .blocksize = 16,
                .keysize = 32,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "CAMELLIA-192-CBC",
                .id = GNUTLS_CIPHER_CAMELLIA_192_CBC,
                .blocksize = 16,
                .keysize = 24,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "CAMELLIA-128-CBC",
                .id = GNUTLS_CIPHER_CAMELLIA_128_CBC,
                .blocksize = 16,
                .keysize = 16,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "CHACHA20-POLY1305",
                .id = GNUTLS_CIPHER_CHACHA20_POLY1305,
                .blocksize = 64,
                .keysize = 32,
                .type = CIPHER_AEAD,
                .implicit_iv = 12,
                .explicit_iv = 0,
                /* in chacha20 we don't need a rekey after 2^24 messages */
                .flags = GNUTLS_CIPHER_FLAG_XOR_NONCE | GNUTLS_CIPHER_FLAG_NO_REKEY,
                .cipher_iv = 12,
                .tagsize = 16
        },
        { .name = "CAMELLIA-128-GCM",
                .id = GNUTLS_CIPHER_CAMELLIA_128_GCM,
                .blocksize = 16,
                .keysize = 16,
                .type = CIPHER_AEAD, 4, 8, 12, 16},
        { .name = "CAMELLIA-256-GCM",
                .id = GNUTLS_CIPHER_CAMELLIA_256_GCM,
                .blocksize = 16,
                .keysize = 32,
                .type = CIPHER_AEAD,
                .implicit_iv = 4,
                .explicit_iv = 8,
                .cipher_iv = 12,
                .tagsize = 16},
        { .name = "GOST28147-TC26Z-CFB",
                .id = GNUTLS_CIPHER_GOST28147_TC26Z_CFB,
                .blocksize = 8,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .implicit_iv = 8,
                .cipher_iv = 8},
        { .name = "GOST28147-CPA-CFB",
                .id = GNUTLS_CIPHER_GOST28147_CPA_CFB,
                .blocksize = 8,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .implicit_iv = 8,
                .cipher_iv = 8},
        { .name = "GOST28147-CPB-CFB",
                .id = GNUTLS_CIPHER_GOST28147_CPB_CFB,
                .blocksize = 8,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .implicit_iv = 8,
                .cipher_iv = 8},
        { .name = "GOST28147-CPC-CFB",
                .id = GNUTLS_CIPHER_GOST28147_CPC_CFB,
                .blocksize = 8,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .implicit_iv = 8,
                .cipher_iv = 8},
        { .name = "GOST28147-CPD-CFB",
                .id = GNUTLS_CIPHER_GOST28147_CPD_CFB,
                .blocksize = 8,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .implicit_iv = 8,
                .cipher_iv = 8},

        { .name = "AES-128-CFB8",
                .id = GNUTLS_CIPHER_AES_128_CFB8,
                .blocksize = 16,
                .keysize = 16,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "AES-192-CFB8",
                .id = GNUTLS_CIPHER_AES_192_CFB8,
                .blocksize = 16,
                .keysize = 24,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "AES-256-CFB8",
                .id = GNUTLS_CIPHER_AES_256_CFB8,
                .blocksize = 16,
                .keysize = 32,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "AES-128-XTS",
                .id = GNUTLS_CIPHER_AES_128_XTS,
                .blocksize = 16,
                .keysize = 32,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "AES-256-XTS",
                .id = GNUTLS_CIPHER_AES_256_XTS,
                .blocksize = 16,
                .keysize = 64,
                .type = CIPHER_BLOCK,
                .explicit_iv = 16,
                .cipher_iv = 16},
        { .name = "AES-128-SIV",
                .id = GNUTLS_CIPHER_AES_128_SIV,
                .blocksize = 16,
                .keysize = 32,
                .type = CIPHER_AEAD,
                .explicit_iv = 16,
                .cipher_iv = 16,
                .flags = GNUTLS_CIPHER_FLAG_ONLY_AEAD,
                .tagsize = 16},
        { .name = "AES-256-SIV",
                .id = GNUTLS_CIPHER_AES_256_SIV,
                .blocksize = 16,
                .keysize = 64,
                .type = CIPHER_AEAD,
                .explicit_iv = 16,
                .cipher_iv = 16,
                .flags = GNUTLS_CIPHER_FLAG_ONLY_AEAD,
                .tagsize = 16},
        { .name = "GOST28147-TC26Z-CNT",
                .id = GNUTLS_CIPHER_GOST28147_TC26Z_CNT,
                .blocksize = 8,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .implicit_iv = 8,
                .cipher_iv = 8},
        { .name = "MAGMA-CTR-ACPKM",
                .id = GNUTLS_CIPHER_MAGMA_CTR_ACPKM,
                .blocksize = 8,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .implicit_iv = 4,
                .cipher_iv = 8},
        { .name = "KUZNYECHIK-CTR-ACPKM",
                .id = GNUTLS_CIPHER_KUZNYECHIK_CTR_ACPKM,
                .blocksize = 16,
                .keysize = 32,
                .type = CIPHER_STREAM,
                .implicit_iv = 8,
                .cipher_iv = 16},
        { .name = "3DES-CBC",
                .id = GNUTLS_CIPHER_3DES_CBC,
                .blocksize = 8,
                .keysize = 24,
                .type = CIPHER_BLOCK,
                .explicit_iv = 8,
                .cipher_iv = 8},
        { .name = "DES-CBC",
                .id = GNUTLS_CIPHER_DES_CBC,
                .blocksize = 8,
                .keysize = 8,
                .type = CIPHER_BLOCK,
                .explicit_iv = 8,
                .cipher_iv = 8},
        { .name = "ARCFOUR-40",
                .id = GNUTLS_CIPHER_ARCFOUR_40,
                .blocksize = 1,
                .keysize = 5,
                .type = CIPHER_STREAM},
        { .name = "RC2-40",
                .id = GNUTLS_CIPHER_RC2_40_CBC,
                .blocksize = 8,
                .keysize = 5,
                .type = CIPHER_BLOCK,
                .explicit_iv = 8,
                .cipher_iv = 8},
        { .name = "NULL",
                .id = GNUTLS_CIPHER_NULL,
                .blocksize = 1,
                .keysize = 0,
                .type = CIPHER_STREAM
        },
        {0, 0, 0, 0, 0, 0, 0}
};

#define GNUTLS_CIPHER_LOOP(b) \
	const cipher_entry_st *p; \
		for(p = algorithms; p->name != NULL; p++) { b ; }

#define GNUTLS_ALG_LOOP(a) \
			GNUTLS_CIPHER_LOOP( if(p->id == algorithm) { a; break; } )

#define SR_FB(x, cleanup) ret=(x); if ( ret<0 ) { \
  if (ret == GNUTLS_E_NEED_FALLBACK) { \
    if (handle->handle) \
	handle->deinit(handle->handle); \
    goto fallback; \
  } \
  gnutls_assert(); \
  ret = GNUTLS_E_INTERNAL_ERROR; \
  goto cleanup; \
  }

#define SR(x, cleanup) if ( (x)<0 ) { \
  gnutls_assert(); \
  ret = GNUTLS_E_INTERNAL_ERROR; \
  goto cleanup; \
  }

typedef void *(*gnutls_calloc_function) (size_t, size_t);

typedef struct algo_list {
    int algorithm;
    int priority;
    void *alg_data;
    int free_alg_data;
    struct algo_list *next;
} algo_list;

#define cipher_list algo_list

static cipher_list glob_cl = { GNUTLS_CIPHER_NULL, 0, NULL, 0, NULL };

static const void *_get_algo(algo_list * al, int algo)
{
    cipher_list *cl;

    /* look if there is any cipher with lowest priority. In that case do not add.
     */
    cl = al;
    while (cl && cl->alg_data) {
        if (cl->algorithm == algo) {
            return cl->alg_data;
        }
        cl = cl->next;
    }

    return NULL;
}

#define AES_BLOCK_SIZE 16

#define AES128_KEY_SIZE 16
#define AES192_KEY_SIZE 24
#define AES256_KEY_SIZE 32
#define _AES128_ROUNDS 10
#define _AES192_ROUNDS 12
#define _AES256_ROUNDS 14

typedef void nettle_cipher_func(const void *ctx,
                                size_t length, uint8_t *dst,
                                const uint8_t *src);

void arcfour_crypt(const void *ctx, size_t length, uint8_t *dst, const uint8_t *src) {

}

void aes128_decrypt(const void *ctx, size_t length, uint8_t *dst, const uint8_t *src) {

}

typedef void nettle_set_key_func(void *ctx, const uint8_t *key);

void arcfour128_set_key(void *ctx, const uint8_t *key) {

}

void gcm_aes128_get_key(void *ctx, const uint8_t *key) {

}

typedef void nettle_hash_digest_func(void *ctx, size_t length, uint8_t *dst);

void gcm_aes128_digest(void *ctx, size_t length, uint8_t *dst) {

}

typedef void nettle_hash_update_func(void *ctx, size_t length, const uint8_t *src);

void gcm_aes128_update(void *ctx, size_t length, const uint8_t *src) {

}

typedef void (*setiv_func) (void *ctx, size_t length, const uint8_t *);

void gcm_aes128_set_iv(void *ctx, size_t length, const uint8_t *data) {

}

#define GCM_BLOCK_SIZE 16
#define GCM_IV_SIZE (GCM_BLOCK_SIZE - 4)
#define GCM_DIGEST_SIZE 16
#define GCM_TABLE_BITS 8

union nettle_block16
{
    uint8_t b[16];
    unsigned long w[16 / sizeof(unsigned long)];
    uint64_t u64[2];
};

struct gcm_key
{
    union nettle_block16 h[1 << GCM_TABLE_BITS];
};

struct gcm_ctx {
    /* Original counter block */
    union nettle_block16 iv;
    /* Updated for each block. */
    union nettle_block16 ctr;
    /* Hashing state */
    union nettle_block16 x;
    uint64_t auth_size;
    uint64_t data_size;
};

struct aes128_ctx
{
    uint32_t keys[4 * (_AES128_ROUNDS + 1)];
};

#define GCM_CTX(type) \
  { struct gcm_key key; struct gcm_ctx gcm; type cipher; }

struct gcm_aes128_ctx GCM_CTX(struct aes128_ctx);

static void
_gcm_encrypt(struct nettle_cipher_ctx *ctx, size_t length, uint8_t * dst,
             const uint8_t * src)
{
//    gcm_encrypt(GCM_CTX_GET_CTX(ctx->ctx_ptr), GCM_CTX_GET_KEY(ctx->ctx_ptr),
//                GCM_CTX_GET_CIPHER(ctx->ctx_ptr), ctx->cipher->encrypt_block,
//                length, dst, src);
}

static void
_gcm_decrypt(struct nettle_cipher_ctx *ctx, size_t length, uint8_t * dst,
             const uint8_t * src)
{
//    gcm_decrypt(GCM_CTX_GET_CTX(ctx->ctx_ptr), GCM_CTX_GET_KEY(ctx->ctx_ptr),
//                GCM_CTX_GET_CIPHER(ctx->ctx_ptr), ctx->cipher->encrypt_block,
//                length, dst, src);
}

struct arcfour_ctx
{
    uint8_t S[256];
    uint8_t i;
    uint8_t j;
};

#define MAX_CIPHER_BLOCK_SIZE 64 /* CHACHA20 */

struct nettle_cipher_ctx {
    const struct nettle_cipher_st *cipher;
    void *ctx_ptr; /* always 16-aligned */
    uint8_t iv[MAX_CIPHER_BLOCK_SIZE];
    unsigned iv_size;

    bool enc;
};

struct nettle_cipher_st {
    gnutls_cipher_algorithm_t algo;
    unsigned ctx_size;
    nettle_cipher_func *encrypt_block;
    nettle_cipher_func *decrypt_block;
    unsigned block_size;
    unsigned key_size;
    unsigned max_iv_size;

    encrypt_func encrypt;
    decrypt_func decrypt;
    aead_encrypt_func aead_encrypt;
    aead_decrypt_func aead_decrypt;
    nettle_hash_update_func* auth;
    nettle_hash_digest_func* tag;
    nettle_set_key_func* set_encrypt_key;
    nettle_set_key_func* set_decrypt_key;
    gen_setkey_func gen_set_key; /* for arcfour which has variable key size */
    setiv_func set_iv;
};

static void _stream_encrypt(struct nettle_cipher_ctx *ctx, size_t length, uint8_t * dst,
                const uint8_t * src)
{
    ctx->cipher->encrypt_block(ctx->ctx_ptr, length, dst, src);
}

static const struct nettle_cipher_st builtin_ciphers[] = {
        {  .algo = GNUTLS_CIPHER_ARCFOUR_128,
                .block_size = 1,
                .key_size = 0,
                .encrypt_block = (nettle_cipher_func*)arcfour_crypt,
                .decrypt_block = (nettle_cipher_func*)arcfour_crypt,

                .ctx_size = sizeof(struct arcfour_ctx),
                .encrypt = _stream_encrypt,
                .decrypt = _stream_encrypt,
                .gen_set_key = (gen_setkey_func)gen_setkey_func_real,
                .set_encrypt_key = (nettle_set_key_func*)arcfour128_set_key,
                .set_decrypt_key = (nettle_set_key_func*)arcfour128_set_key,
        }
};

static const gnutls_crypto_cipher_st *_gnutls_get_crypto_cipher(gnutls_cipher_algorithm_t algo)
{
    return _get_algo(&glob_cl, algo);
}

static int wrap_nettle_cipher_init(gnutls_cipher_algorithm_t algo, void **_ctx, int enc)
{
    struct nettle_cipher_ctx *ctx;
    ptrdiff_t cur_alignment;
    int idx = -1;
    unsigned i;
    uint8_t *ctx_ptr;

    for (i=0;i<sizeof(builtin_ciphers)/sizeof(builtin_ciphers[0]);i++) {
        if (algo == builtin_ciphers[i].algo) {
            idx = i;
            break;
        }
    }

    if (idx == -1)
        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

    ctx = calloc(1, sizeof(*ctx)+builtin_ciphers[idx].ctx_size+16);
    if (ctx == NULL) {
        gnutls_assert();
        return GNUTLS_E_MEMORY_ERROR;
    }

    ctx->enc = enc;
    ctx_ptr = ((uint8_t*)ctx) + sizeof(*ctx);

    cur_alignment = ((ptrdiff_t)ctx_ptr) % 16;
    if (cur_alignment > 0)
        ctx_ptr += 16 - cur_alignment;

    ctx->ctx_ptr = ctx_ptr;
    ctx->cipher = &builtin_ciphers[idx];

    *_ctx = ctx;

    return 0;
}


static int wrap_nettle_cipher_exists(gnutls_cipher_algorithm_t algo)
{
    unsigned i;
    for (i=0;i<sizeof(builtin_ciphers)/sizeof(builtin_ciphers[0]);i++) {
        if (algo == builtin_ciphers[i].algo) {
            return 1;
        }
    }
    return 0;
}

static int
wrap_nettle_cipher_setiv(void *_ctx, const void *iv, size_t iv_size)
{
    struct nettle_cipher_ctx *ctx = _ctx;
    unsigned max_iv;

    switch (ctx->cipher->algo) {
        case GNUTLS_CIPHER_AES_128_GCM:
//        case GNUTLS_CIPHER_AES_192_GCM:
        case GNUTLS_CIPHER_AES_256_GCM:
//            FIPS_RULE(iv_size < GCM_IV_SIZE, GNUTLS_E_INVALID_REQUEST, "access to short GCM nonce size\n");
            break;
        case GNUTLS_CIPHER_SALSA20_256:
        case GNUTLS_CIPHER_ESTREAM_SALSA20_256:
//            if (iv_size != SALSA20_IV_SIZE)
                return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);
            break;
        default:
            break;
    }

    max_iv = ctx->cipher->max_iv_size;
    if (max_iv == 0)
        max_iv = MAX_CIPHER_BLOCK_SIZE;

    if (iv_size > max_iv)
        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

    if (ctx->cipher->set_iv) {
        ctx->cipher->set_iv(ctx->ctx_ptr, iv_size, iv);
    } else {
        if (iv)
            memcpy(ctx->iv, iv, iv_size);
        ctx->iv_size = iv_size;
    }

    return 0;
}

static int
wrap_nettle_cipher_getiv(void *_ctx, void *iv, size_t iv_size)
{
    struct nettle_cipher_ctx *ctx = _ctx;

    if (iv_size < ctx->iv_size)
        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

    memcpy(iv, ctx->iv, ctx->iv_size);

    return (int) ctx->iv_size;
}

static int
wrap_nettle_cipher_setkey(void *_ctx, const void *key, size_t keysize)
{
    struct nettle_cipher_ctx *ctx = _ctx;

    if (ctx->cipher->key_size > 0 && unlikely(keysize != ctx->cipher->key_size)) {
        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);
    } else if (ctx->cipher->key_size == 0) {
        ctx->cipher->gen_set_key(ctx->ctx_ptr, keysize, key);
        return 0;
    }

    if (ctx->enc)
        ctx->cipher->set_encrypt_key(ctx->ctx_ptr, key);
    else
        ctx->cipher->set_decrypt_key(ctx->ctx_ptr, key);

    return 0;
}

static int
wrap_nettle_cipher_encrypt(void *_ctx, const void *plain, size_t plain_size,
                           void *encr, size_t encr_size)
{
    struct nettle_cipher_ctx *ctx = _ctx;

    if (unlikely(ctx->cipher->encrypt == NULL))
        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

    ctx->cipher->encrypt(ctx, plain_size, encr, plain);

    return 0;
}

static int
wrap_nettle_cipher_decrypt(void *_ctx, const void *encr, size_t encr_size,
                           void *plain, size_t plain_size)
{
    struct nettle_cipher_ctx *ctx = _ctx;

    if (unlikely(ctx->cipher->decrypt == NULL))
        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

    ctx->cipher->decrypt(ctx, encr_size, plain, encr);

    return 0;
}

static int
wrap_nettle_cipher_aead_encrypt(void *_ctx,
                                const void *nonce, size_t nonce_size,
                                const void *auth, size_t auth_size,
                                size_t tag_size,
                                const void *plain, size_t plain_size,
                                void *encr, size_t encr_size)
{
    struct nettle_cipher_ctx *ctx = _ctx;

    if (ctx->cipher->aead_encrypt == NULL) {
        /* proper AEAD cipher */
        if (encr_size < plain_size + tag_size)
            return gnutls_assert_val(GNUTLS_E_SHORT_MEMORY_BUFFER);

        ctx->cipher->set_iv(ctx->ctx_ptr, nonce_size, nonce);
        ctx->cipher->auth(ctx->ctx_ptr, auth_size, auth);

        ctx->cipher->encrypt(ctx, plain_size, encr, plain);

        ctx->cipher->tag(ctx->ctx_ptr, tag_size, ((uint8_t*)encr) + plain_size);
    } else {
        /* CCM-style cipher */
        ctx->cipher->aead_encrypt(ctx,
                                  nonce_size, nonce,
                                  auth_size, auth,
                                  tag_size,
                                  tag_size+plain_size, encr,
                                  plain);
    }
    return 0;
}

static int
wrap_nettle_cipher_aead_decrypt(void *_ctx,
                                const void *nonce, size_t nonce_size,
                                const void *auth, size_t auth_size,
                                size_t tag_size,
                                const void *encr, size_t encr_size,
                                void *plain, size_t plain_size)
{
    struct nettle_cipher_ctx *ctx = _ctx;
    int ret;

    if (unlikely(encr_size < tag_size))
        return gnutls_assert_val(GNUTLS_E_DECRYPTION_FAILED);

    if (ctx->cipher->aead_decrypt == NULL) {
        /* proper AEAD cipher */
        uint8_t tag[64]; // @todo: 64 or not???

        ctx->cipher->set_iv(ctx->ctx_ptr, nonce_size, nonce);
        ctx->cipher->auth(ctx->ctx_ptr, auth_size, auth);

        encr_size -= tag_size;

        if (unlikely(plain_size < encr_size))
            return gnutls_assert_val(GNUTLS_E_SHORT_MEMORY_BUFFER);

        ctx->cipher->decrypt(ctx, encr_size, plain, encr);

        ctx->cipher->tag(ctx->ctx_ptr, tag_size, tag);

        if (memcmp(((uint8_t*)encr)+encr_size, tag, tag_size) != 0)
            return gnutls_assert_val(GNUTLS_E_DECRYPTION_FAILED);
    } else {
        /* CCM-style cipher */
        encr_size -= tag_size;

        if (unlikely(plain_size < encr_size))
            return gnutls_assert_val(GNUTLS_E_SHORT_MEMORY_BUFFER);

        ret = ctx->cipher->aead_decrypt(ctx,
                                        nonce_size, nonce,
                                        auth_size, auth,
                                        tag_size,
                                        encr_size, plain,
                                        encr);
        if (unlikely(ret == 0))
            return gnutls_assert_val(GNUTLS_E_DECRYPTION_FAILED);
    }
    return 0;
}

static void wrap_nettle_cipher_close(void *_ctx)
{
    struct nettle_cipher_ctx *ctx = _ctx;

    memset(ctx->ctx_ptr, 0, ctx->cipher->ctx_size);
    free(ctx);
}

static int
wrap_nettle_cipher_auth(void *_ctx, const void *plain, size_t plain_size)
{
    struct nettle_cipher_ctx *ctx = _ctx;

    ctx->cipher->auth(ctx->ctx_ptr, plain_size, plain);

    return 0;
}

static void wrap_nettle_cipher_tag(void *_ctx, void *tag, size_t tag_size)
{
    struct nettle_cipher_ctx *ctx = _ctx;

    ctx->cipher->tag(ctx->ctx_ptr, tag_size, tag);

}

gnutls_crypto_cipher_st _gnutls_cipher_ops = {
        .init = wrap_nettle_cipher_init,
        .exists = wrap_nettle_cipher_exists,
        .setiv = wrap_nettle_cipher_setiv,
        .getiv = wrap_nettle_cipher_getiv,
        .setkey = wrap_nettle_cipher_setkey,
        .encrypt = wrap_nettle_cipher_encrypt,
        .decrypt = wrap_nettle_cipher_decrypt,
        .aead_encrypt = wrap_nettle_cipher_aead_encrypt,
        .aead_decrypt = wrap_nettle_cipher_aead_decrypt,
        .deinit = wrap_nettle_cipher_close,
        .auth = wrap_nettle_cipher_auth,
        .tag = wrap_nettle_cipher_tag,
};

static int _gnutls_cipher_init(cipher_hd_st *handle, const cipher_entry_st *e,
                               const gnutls_datum_t *key, const gnutls_datum_t *iv,
                               int enc)
{
    int ret = GNUTLS_E_INTERNAL_ERROR;
    const gnutls_crypto_cipher_st *cc = NULL;

    if (unlikely(e == NULL || e->id == GNUTLS_CIPHER_NULL))
        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

    // FAIL_IF_LIB_ERROR;

    handle->e = e;
    handle->handle = NULL;

    /* check if a cipher has been registered
     */
    cc = _gnutls_get_crypto_cipher(e->id);
    if (cc != NULL) {
        handle->encrypt = cc->encrypt;
        handle->decrypt = cc->decrypt;
        handle->aead_encrypt = cc->aead_encrypt;
        handle->aead_decrypt = cc->aead_decrypt;
        handle->deinit = cc->deinit;
        handle->auth = cc->auth;
        handle->tag = cc->tag;
        handle->setiv = cc->setiv;
        handle->getiv = cc->getiv;
        handle->setkey = cc->setkey;

        /* if cc->init() returns GNUTLS_E_NEED_FALLBACK we
         * use the default ciphers */
        SR_FB(cc->init(e->id, &handle->handle, enc), cc_cleanup);
        SR_FB(cc->setkey(handle->handle, key->data, key->size),
              cc_cleanup);
        if (iv) {
            /* the API doesn't accept IV */
            if (unlikely(cc->setiv == NULL)) {
                if (cc->aead_encrypt) {
                    if (handle->handle)
                        handle->deinit(handle->handle);
                    goto fallback;
                }
                return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);
            }
            SR(cc->setiv(handle->handle, iv->data, iv->size),
               cc_cleanup);
        }

        return 0;
    }

fallback:
    handle->encrypt = _gnutls_cipher_ops.encrypt;
    handle->decrypt = _gnutls_cipher_ops.decrypt;
    handle->aead_encrypt = _gnutls_cipher_ops.aead_encrypt;
    handle->aead_decrypt = _gnutls_cipher_ops.aead_decrypt;
    handle->deinit = _gnutls_cipher_ops.deinit;
    handle->auth = _gnutls_cipher_ops.auth;
    handle->tag = _gnutls_cipher_ops.tag;
    handle->setiv = _gnutls_cipher_ops.setiv;
    handle->getiv = _gnutls_cipher_ops.getiv;
    handle->setkey = _gnutls_cipher_ops.setkey;

    /* otherwise use generic cipher interface
     */
    ret = _gnutls_cipher_ops.init(e->id, &handle->handle, enc);
    if (ret < 0) {
        gnutls_assert();
        return ret;
    }

    ret = _gnutls_cipher_ops.setkey(handle->handle, key->data,
                                      key->size);
    if (ret < 0) {
        gnutls_assert();
        goto cc_cleanup;
    }

    if (iv) {
        ret = _gnutls_cipher_ops.setiv(handle->handle, iv->data,
                                         iv->size);
        if (ret < 0) {
            gnutls_assert();
            goto cc_cleanup;
        }
    }

    return 0;

cc_cleanup:

    if (handle->handle)
        handle->deinit(handle->handle);

    return ret;
}

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

    api_cipher_hd_st *h;
    int ret;
    const cipher_entry_st* e;

    if (is_cipher_algo_forbidden(cipher)) {
        assert(0);
    }
//        return gnutls_assert_val(GNUTLS_E_UNWANTED_ALGORITHM);

    e = cipher_to_entry(cipher);
    if (e == NULL || (e->flags & GNUTLS_CIPHER_FLAG_ONLY_AEAD)) {
        assert(0);
    }
//        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

    h = calloc(1, sizeof(api_cipher_hd_st));
    if (h == NULL) {
        assert(0);
//        gnutls_assert();
        return GNUTLS_E_MEMORY_ERROR;
    }

    ret = _gnutls_cipher_init(&h->ctx_enc, e, key,
                                iv, 1);
    if (ret < 0) {
//        gnutls_free(h);
        free(h);
        return ret;
    }

    if (_gnutls_cipher_type(e) == CIPHER_BLOCK) {
        ret =
                _gnutls_cipher_init(&h->ctx_dec, e, key, iv, 0);
        if (ret < 0) {
            free(h);
//            gnutls_free(h);
            return ret;
        }
    }

    *handle = h;

    return ret;
}

#define GNUTLS_CIPHER_LOOP(b) \
	const cipher_entry_st *p; \
		for(p = algorithms; p->name != NULL; p++) { b ; }

#define GNUTLS_ALG_LOOP(a) \
			GNUTLS_CIPHER_LOOP( if(p->id == algorithm) { a; break; } )

/* CIPHER functions */

const cipher_entry_st *_gnutls_cipher_to_entry(gnutls_cipher_algorithm_t c)
{
    GNUTLS_CIPHER_LOOP(if (c == p->id) return p);

    return NULL;
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
    DumpHex(ptext, ptext_len);
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