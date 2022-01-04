#include <malloc.h>
#include <assert.h>
#include <memory.h>

#include <openssl/evp.h>
#include <openssl/hmac.h>

#include "kosgnutls.h"


#define MAC_OID_SHA1 "1.2.840.113549.2.7"
#define MAC_OID_SHA224 "1.2.840.113549.2.8"
#define MAC_OID_SHA256 "1.2.840.113549.2.9"
#define MAC_OID_SHA384 "1.2.840.113549.2.10"
#define MAC_OID_SHA512 "1.2.840.113549.2.11"
#define MAC_OID_GOST_R_3411_94 "1.2.643.2.2.10"
#define MAC_OID_STREEBOG_256 "1.2.643.7.1.1.4.1"
#define MAC_OID_STREEBOG_512 "1.2.643.7.1.1.4.2"

#define HASH_OID_SHA1 "1.3.14.3.2.26"
#define HASH_OID_MD5 "1.2.840.113549.2.5"
#define HASH_OID_MD2 "1.2.840.113549.2.2"
#define HASH_OID_RMD160 "1.3.36.3.2.1"
#define HASH_OID_SHA224 "2.16.840.1.101.3.4.2.4"
#define HASH_OID_SHA256 "2.16.840.1.101.3.4.2.1"
#define HASH_OID_SHA384 "2.16.840.1.101.3.4.2.2"
#define HASH_OID_SHA512 "2.16.840.1.101.3.4.2.3"
#define HASH_OID_SHA3_224 "2.16.840.1.101.3.4.2.7"
#define HASH_OID_SHA3_256 "2.16.840.1.101.3.4.2.8"
#define HASH_OID_SHA3_384 "2.16.840.1.101.3.4.2.9"
#define HASH_OID_SHA3_512 "2.16.840.1.101.3.4.2.10"
#define HASH_OID_SHAKE_128 "2.16.840.1.101.3.4.2.11"
#define HASH_OID_SHAKE_256 "2.16.840.1.101.3.4.2.12"
#define HASH_OID_GOST_R_3411_94 "1.2.643.2.2.9"
#define HASH_OID_STREEBOG_256 "1.2.643.7.1.1.2.2"
#define HASH_OID_STREEBOG_512 "1.2.643.7.1.1.2.3"

#define HASH_OID_GOST_R_3411_94_CRYPTOPRO_PARAMS "1.2.643.2.2.30.1"

typedef struct mac_entry_st {
    const char *name;
    const char *oid;	/* OID of the hash - if it is a hash */
    const char *mac_oid;    /* OID of the MAC algorithm - if it is a MAC */
    gnutls_mac_algorithm_t id;
    unsigned output_size;
    unsigned key_size;
    unsigned nonce_size;
    unsigned placeholder;	/* if set, then not a real MAC */
    unsigned block_size;	/* internal block size for HMAC */
    unsigned flags;
} mac_entry_st;

static mac_entry_st hash_algorithms[] = {
        {.name = "SHA1",
                .oid = HASH_OID_SHA1,
                .mac_oid = MAC_OID_SHA1,
                .id = GNUTLS_MAC_SHA1,
                .output_size = 20,
                .key_size = 20,
                .block_size = 64},
        {.name = "MD5+SHA1",
                .id = GNUTLS_MAC_MD5_SHA1,
                .output_size = 36,
                .key_size = 36,
                .flags = GNUTLS_MAC_FLAG_PREIMAGE_INSECURE,
                .block_size = 64},
        {.name = "SHA256",
                .oid = HASH_OID_SHA256,
                .mac_oid = MAC_OID_SHA256,
                .id = GNUTLS_MAC_SHA256,
                .output_size = 32,
                .key_size = 32,
                .block_size = 64},
        {.name = "SHA384",
                .oid = HASH_OID_SHA384,
                .mac_oid = MAC_OID_SHA384,
                .id = GNUTLS_MAC_SHA384,
                .output_size = 48,
                .key_size = 48,
                .block_size = 128},
        {.name = "SHA512",
                .oid = HASH_OID_SHA512,
                .mac_oid = MAC_OID_SHA512,
                .id = GNUTLS_MAC_SHA512,
                .output_size = 64,
                .key_size = 64,
                .block_size = 128},
        {.name = "SHA224",
                .oid = HASH_OID_SHA224,
                .mac_oid = MAC_OID_SHA224,
                .id = GNUTLS_MAC_SHA224,
                .output_size = 28,
                .key_size = 28,
                .block_size = 64},
        {.name = "SHA3-256",
                .oid = HASH_OID_SHA3_256,
                .id = GNUTLS_MAC_SHA3_256,
                .output_size = 32,
                .key_size = 32,
                .block_size = 136},
        {.name = "SHA3-384",
                .oid = HASH_OID_SHA3_384,
                .id = GNUTLS_MAC_SHA3_384,
                .output_size = 48,
                .key_size = 48,
                .block_size = 104},
        {.name = "SHA3-512",
                .oid = HASH_OID_SHA3_512,
                .id = GNUTLS_MAC_SHA3_512,
                .output_size = 64,
                .key_size = 64,
                .block_size = 72},
        {.name = "SHA3-224",
                .oid = HASH_OID_SHA3_224,
                .id = GNUTLS_MAC_SHA3_224,
                .output_size = 28,
                .key_size = 28,
                .block_size = 144},
        {.name = "UMAC-96",
                .id = GNUTLS_MAC_UMAC_96,
                .output_size = 12,
                .key_size = 16,
                .nonce_size = 8},
        {.name = "UMAC-128",
                .id = GNUTLS_MAC_UMAC_128,
                .output_size = 16,
                .key_size = 16,
                .nonce_size = 8},
        {.name = "AEAD",
                .id = GNUTLS_MAC_AEAD,
                .placeholder = 1},
        {.name = "MD5",
                .oid = HASH_OID_MD5,
                .id = GNUTLS_MAC_MD5,
                .output_size = 16,
                .key_size = 16,
                .flags = GNUTLS_MAC_FLAG_PREIMAGE_INSECURE,
                .block_size = 64},
        {.name = "MD2",
                .oid = HASH_OID_MD2,
                .flags = GNUTLS_MAC_FLAG_PREIMAGE_INSECURE,
                .id = GNUTLS_MAC_MD2},
        {.name = "RIPEMD160",
                .oid = HASH_OID_RMD160,
                .id = GNUTLS_MAC_RMD160,
                .output_size = 20,
                .key_size = 20,
                .block_size = 64
        },
        {.name = "GOSTR341194",
                .oid = HASH_OID_GOST_R_3411_94,
                .mac_oid = MAC_OID_GOST_R_3411_94,
                .id = GNUTLS_MAC_GOSTR_94,
                .output_size = 32,
                .key_size = 32,
                .block_size = 32,
                .flags = GNUTLS_MAC_FLAG_PREIMAGE_INSECURE
        },
        {.name = "STREEBOG-256",
                .oid = HASH_OID_STREEBOG_256,
                .mac_oid = MAC_OID_STREEBOG_256,
                .id = GNUTLS_MAC_STREEBOG_256,
                .output_size = 32,
                .key_size = 32,
                .block_size = 64},
        {.name = "STREEBOG-512",
                .oid = HASH_OID_STREEBOG_512,
                .mac_oid = MAC_OID_STREEBOG_512,
                .id = GNUTLS_MAC_STREEBOG_512,
                .output_size = 64,
                .key_size = 64,
                .block_size = 64},
        {.name = "AES-CMAC-128",
                .id = GNUTLS_MAC_AES_CMAC_128,
                .output_size = 16,
                .key_size = 16,},
        {.name = "AES-CMAC-256",
                .id = GNUTLS_MAC_AES_CMAC_256,
                .output_size = 16,
                .key_size = 32},
        {.name = "AES-GMAC-128",
                .id = GNUTLS_MAC_AES_GMAC_128,
                .output_size = 16,
                .key_size = 16,
                .nonce_size = 12},
        {.name = "AES-GMAC-192",
                .id = GNUTLS_MAC_AES_GMAC_192,
                .output_size = 16,
                .key_size = 24,
                .nonce_size = 12},
        {.name = "AES-GMAC-256",
                .id = GNUTLS_MAC_AES_GMAC_256,
                .output_size = 16,
                .key_size = 32,
                .nonce_size = 12},
        {.name = "GOST28147-TC26Z-IMIT",
                .id = GNUTLS_MAC_GOST28147_TC26Z_IMIT,
                .output_size = 4,
                .key_size = 32,
                .block_size = 8,
                .flags = GNUTLS_MAC_FLAG_CONTINUOUS_MAC},
        {.name = "SHAKE-128",
                .oid = HASH_OID_SHAKE_128,
                .id = GNUTLS_MAC_SHAKE_128,
                .block_size = 168},
        {.name = "SHAKE-256",
                .oid = HASH_OID_SHAKE_256,
                .id = GNUTLS_MAC_SHAKE_256,
                .block_size = 136},
//        {.name = "OMAC-MAGMA",
//                .id = GNUTLS_MAC_MAGMA_OMAC,
//                .output_size = 8,
//                .key_size = 32,
//                .block_size = 8},
//        {.name = "OMAC-KUZNYECHIK",
//                .id = GNUTLS_MAC_KUZNYECHIK_OMAC,
//                .output_size = 16,
//                .key_size = 32,
//                .block_size = 16},
        {.name = "MAC-NULL",
                .id = GNUTLS_MAC_NULL},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

typedef int (*hash_func) (void *handle, const void *text, size_t size);
typedef int (*nonce_func) (void *handle, const void *text, size_t size);
typedef int (*output_func) (void *src_ctx, void *digest,
                            size_t digestsize);
typedef void (*hash_deinit_func) (void *handle);
typedef void *(*copy_func) (const void *handle);
typedef int (*setkey_func) (void *handle, const void *key, size_t keysize);

typedef int (*gnutls_mac_init_func) (gnutls_mac_algorithm_t, void **ctx);
typedef int (*gnutls_mac_setkey_func) (void *ctx, const void *key, size_t keysize);
typedef int (*gnutls_mac_setnonce_func) (void *ctx, const void *nonce, size_t noncesize);
typedef int (*gnutls_mac_hash_func) (void *ctx, const void *text, size_t textsize);
typedef int (*gnutls_mac_output_func) (void *src_ctx, void *digest, size_t digestsize);
typedef void (*gnutls_mac_deinit_func) (void *ctx);
typedef int (*gnutls_mac_fast_func) (gnutls_mac_algorithm_t, const void *nonce,
                                     size_t nonce_size, const void *key, size_t keysize,
                                     const void *text, size_t textsize, void *digest);
typedef void *(*gnutls_mac_copy_func) (const void *ctx);

typedef struct {
    const mac_entry_st *e;
    int mac_len;

    hash_func hash;
    nonce_func setnonce;
    output_func output;
    hash_deinit_func deinit;
    copy_func copy;
    setkey_func setkey;

    void *handle;
} mac_hd_st;

typedef struct {
    gnutls_mac_init_func init;
    gnutls_mac_setkey_func setkey;
    gnutls_mac_setnonce_func setnonce;
    gnutls_mac_hash_func hash;
    gnutls_mac_output_func output;
    gnutls_mac_deinit_func deinit;
    gnutls_mac_fast_func fast;
    gnutls_mac_copy_func copy;

    /* Not needed for registered on run-time. Only included
     * should define it. */
    int (*exists) (gnutls_mac_algorithm_t);
} gnutls_crypto_mac_st;

inline static int _gnutls_mac(mac_hd_st * handle, const void *text, size_t textlen)
{
    HMAC_CTX *ctx = (HMAC_CTX *)handle;
    int res_update = HMAC_Update(ctx, text, textlen);
    if (!res_update) {
        fprintf(stderr, "HMAC Update failed\n");
        exit(1);
    }

    return 0;

//    if (textlen > 0) {
//        return handle->hash(handle->handle, text, textlen);
//    }
    return 0;
}

int gnutls_hmac(gnutls_hmac_hd_t handle, const void *ptext, size_t ptext_len)
{
    return _gnutls_mac((mac_hd_st *) handle, ptext, ptext_len);
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
        return -1;
    }

    return 0;
}

inline static size_t _gnutls_mac_get_algo_len(const mac_entry_st * e)
{
    if (unlikely(e == NULL))
        return 0;
    else
        return e->output_size;
}

typedef struct algo_list {
    int algorithm;
    int priority;
    void *alg_data;
    int free_alg_data;
    struct algo_list *next;
} algo_list;

#define mac_list algo_list

static mac_list glob_ml = { GNUTLS_MAC_NULL, 0, NULL, 0, NULL };

static const void *_get_algo(algo_list * al, int algo)
{
//    cipher_list *cl;
//
//    /* look if there is any cipher with lowest priority. In that case do not add.
//     */
//    cl = al;
//    while (cl && cl->alg_data) {
//        if (cl->algorithm == algo) {
//            return cl->alg_data;
//        }
//        cl = cl->next;
//    }

    return NULL;
}

const gnutls_crypto_mac_st *_gnutls_get_crypto_mac(gnutls_mac_algorithm_t
                                                   algo)
{
    return _get_algo(&glob_ml, algo);
}

#define MD5_DIGEST_SIZE 16
#define MD5_BLOCK_SIZE 64
/* For backwards compatibility */
#define MD5_DATA_SIZE MD5_BLOCK_SIZE

/* Digest is kept internally as 4 32-bit words. */
#define _MD5_DIGEST_LENGTH 4

struct md5_ctx
{
    uint32_t state[_MD5_DIGEST_LENGTH];
    uint64_t count;               /* Block count */
    unsigned index;               /* Into buffer */
    uint8_t block[MD5_BLOCK_SIZE]; /* Block buffer */
};

#define HMAC_CTX(type) \
{ type outer; type inner; type state; }

#define HMAC_SET_KEY(ctx, hash, length, key)			\
  hmac_set_key( &(ctx)->outer, &(ctx)->inner, &(ctx)->state,	\
                (hash), (length), (key) )

#define HMAC_DIGEST(ctx, hash, length, digest)			\
  hmac_digest( &(ctx)->outer, &(ctx)->inner, &(ctx)->state,	\
               (hash), (length), (digest) )

struct hmac_md5_ctx HMAC_CTX(struct md5_ctx);

typedef void (*update_func) (void *, size_t, const uint8_t *);
static void update_func_real(void *d, size_t s, const uint8_t *k) {
    (void)d;
}

typedef void (*digest_func) (void *, size_t, uint8_t *);
static void digest_func_real(void *d, size_t s, uint8_t *k) {

}

typedef void (*set_key_func) (void *, size_t, const uint8_t *);
static void set_key_func_real(void *d, size_t s, const uint8_t *k) {
//    DumpHex(k, s);
    (void)d;
}

typedef void (*set_nonce_func) (void *, size_t, const uint8_t *);

struct nettle_mac_ctx {
    union {
        struct hmac_md5_ctx md5;
//        struct hmac_sha224_ctx sha224;
//        struct hmac_sha256_ctx sha256;
//        struct hmac_sha384_ctx sha384;
//        struct hmac_sha512_ctx sha512;
//        struct hmac_sha1_ctx sha1;
//#if ENABLE_GOST
//        struct hmac_gosthash94cp_ctx gosthash94cp;
//		struct hmac_streebog256_ctx streebog256;
//		struct hmac_streebog512_ctx streebog512;
//		struct gost28147_imit_ctx gost28147_imit;
//		struct cmac_magma_ctx magma;
//		struct cmac_kuznyechik_ctx kuznyechik;
//#endif
//        struct umac96_ctx umac96;
//        struct umac128_ctx umac128;
//        struct cmac_aes128_ctx cmac128;
//        struct cmac_aes256_ctx cmac256;
//        struct gmac_ctx gmac;
    } ctx;

    void *ctx_ptr;
    gnutls_mac_algorithm_t algo;
    size_t length;
    update_func update;
    digest_func digest;
    set_key_func set_key;
    set_nonce_func set_nonce;
};

static int _mac_ctx_init(gnutls_mac_algorithm_t algo,
                         struct nettle_mac_ctx *ctx)
{
    /* Any FIPS140-2 related enforcement is performed on
     * gnutls_hash_init() and gnutls_hmac_init() */

    ctx->set_nonce = NULL;
    switch (algo) {
        case GNUTLS_MAC_MD5:
            ctx->update = (update_func) update_func_real;
            ctx->digest = (digest_func) digest_func_real;
            ctx->set_key = (set_key_func) set_key_func_real;
            ctx->ctx_ptr = &ctx->ctx.md5;
            ctx->length = MD5_DIGEST_SIZE;
            break;
//        case GNUTLS_MAC_SHA1:
//            ctx->update = (update_func) hmac_sha1_update;
//            ctx->digest = (digest_func) hmac_sha1_digest;
//            ctx->set_key = (set_key_func) hmac_sha1_set_key;
//            ctx->ctx_ptr = &ctx->ctx.sha1;
//            ctx->length = SHA1_DIGEST_SIZE;
//            break;
//        case GNUTLS_MAC_SHA224:
//            ctx->update = (update_func) hmac_sha224_update;
//            ctx->digest = (digest_func) hmac_sha224_digest;
//            ctx->set_key = (set_key_func) hmac_sha224_set_key;
//            ctx->ctx_ptr = &ctx->ctx.sha224;
//            ctx->length = SHA224_DIGEST_SIZE;
//            break;
//        case GNUTLS_MAC_SHA256:
//            ctx->update = (update_func) hmac_sha256_update;
//            ctx->digest = (digest_func) hmac_sha256_digest;
//            ctx->set_key = (set_key_func) hmac_sha256_set_key;
//            ctx->ctx_ptr = &ctx->ctx.sha256;
//            ctx->length = SHA256_DIGEST_SIZE;
//            break;
//        case GNUTLS_MAC_SHA384:
//            ctx->update = (update_func) hmac_sha384_update;
//            ctx->digest = (digest_func) hmac_sha384_digest;
//            ctx->set_key = (set_key_func) hmac_sha384_set_key;
//            ctx->ctx_ptr = &ctx->ctx.sha384;
//            ctx->length = SHA384_DIGEST_SIZE;
//            break;
//        case GNUTLS_MAC_SHA512:
//            ctx->update = (update_func) hmac_sha512_update;
//            ctx->digest = (digest_func) hmac_sha512_digest;
//            ctx->set_key = (set_key_func) hmac_sha512_set_key;
//            ctx->ctx_ptr = &ctx->ctx.sha512;
//            ctx->length = SHA512_DIGEST_SIZE;
//            break;
//#if ENABLE_GOST
//            case GNUTLS_MAC_GOSTR_94:
//		ctx->update = (update_func) hmac_gosthash94cp_update;
//		ctx->digest = (digest_func) hmac_gosthash94cp_digest;
//		ctx->set_key = (set_key_func) hmac_gosthash94cp_set_key;
//		ctx->ctx_ptr = &ctx->ctx.gosthash94cp;
//		ctx->length = GOSTHASH94CP_DIGEST_SIZE;
//		break;
//	case GNUTLS_MAC_STREEBOG_256:
//		ctx->update = (update_func) hmac_streebog256_update;
//		ctx->digest = (digest_func) hmac_streebog256_digest;
//		ctx->set_key = (set_key_func) hmac_streebog256_set_key;
//		ctx->ctx_ptr = &ctx->ctx.streebog256;
//		ctx->length = STREEBOG256_DIGEST_SIZE;
//		break;
//	case GNUTLS_MAC_STREEBOG_512:
//		ctx->update = (update_func) hmac_streebog512_update;
//		ctx->digest = (digest_func) hmac_streebog512_digest;
//		ctx->set_key = (set_key_func) hmac_streebog512_set_key;
//		ctx->ctx_ptr = &ctx->ctx.streebog512;
//		ctx->length = STREEBOG512_DIGEST_SIZE;
//		break;
//	case GNUTLS_MAC_GOST28147_TC26Z_IMIT:
//		ctx->update = (update_func) gost28147_imit_update;
//		ctx->digest = (digest_func) gost28147_imit_digest;
//		ctx->set_key = _wrap_gost28147_imit_set_key_tc26z;
//		ctx->ctx_ptr = &ctx->ctx.gost28147_imit;
//		ctx->length = GOST28147_IMIT_DIGEST_SIZE;
//		break;
//	case GNUTLS_MAC_MAGMA_OMAC:
//		ctx->update = (update_func) cmac_magma_update;
//		ctx->digest = (digest_func) cmac_magma_digest;
//		ctx->set_key = _wrap_cmac_magma_set_key;
//		ctx->ctx_ptr = &ctx->ctx.magma;
//		ctx->length = CMAC64_DIGEST_SIZE;
//		break;
//	case GNUTLS_MAC_KUZNYECHIK_OMAC:
//		ctx->update = (update_func) cmac_kuznyechik_update;
//		ctx->digest = (digest_func) cmac_kuznyechik_digest;
//		ctx->set_key = _wrap_cmac_kuznyechik_set_key;
//		ctx->ctx_ptr = &ctx->ctx.kuznyechik;
//		ctx->length = CMAC128_DIGEST_SIZE;
//		break;
//#endif
//        case GNUTLS_MAC_UMAC_96:
//            ctx->update = (update_func) umac96_update;
//            ctx->digest = (digest_func) umac96_digest;
//            ctx->set_key = _wrap_umac96_set_key;
//            ctx->set_nonce = (set_nonce_func) umac96_set_nonce;
//            ctx->ctx_ptr = &ctx->ctx.umac96;
//            ctx->length = 12;
//            break;
//        case GNUTLS_MAC_UMAC_128:
//            ctx->update = (update_func) umac128_update;
//            ctx->digest = (digest_func) umac128_digest;
//            ctx->set_key = _wrap_umac128_set_key;
//            ctx->set_nonce = (set_nonce_func) umac128_set_nonce;
//            ctx->ctx_ptr = &ctx->ctx.umac128;
//            ctx->length = 16;
//            break;
//        case GNUTLS_MAC_AES_CMAC_128:
//            ctx->update = (update_func) cmac_aes128_update;
//            ctx->digest = (digest_func) cmac_aes128_digest;
//            ctx->set_key = _wrap_cmac128_set_key;
//            ctx->ctx_ptr = &ctx->ctx.cmac128;
//            ctx->length = CMAC128_DIGEST_SIZE;
//            break;
//        case GNUTLS_MAC_AES_CMAC_256:
//            ctx->update = (update_func) cmac_aes256_update;
//            ctx->digest = (digest_func) cmac_aes256_digest;
//            ctx->set_key = _wrap_cmac256_set_key;
//            ctx->ctx_ptr = &ctx->ctx.cmac256;
//            ctx->length = CMAC128_DIGEST_SIZE;
//            break;
//        case GNUTLS_MAC_AES_GMAC_128:
//            ctx->set_key = _wrap_gmac_aes128_set_key;
//            ctx->set_nonce = _wrap_gmac_set_nonce;
//            ctx->update = _wrap_gmac_update;
//            ctx->digest = _wrap_gmac_digest;
//            ctx->ctx_ptr = &ctx->ctx.gmac;
//            ctx->length = GCM_DIGEST_SIZE;
//            ctx->ctx.gmac.encrypt = (nettle_cipher_func *)aes128_encrypt;
//            break;
//        case GNUTLS_MAC_AES_GMAC_192:
//            ctx->set_key = _wrap_gmac_aes192_set_key;
//            ctx->set_nonce = _wrap_gmac_set_nonce;
//            ctx->update = _wrap_gmac_update;
//            ctx->digest = _wrap_gmac_digest;
//            ctx->ctx_ptr = &ctx->ctx.gmac;
//            ctx->length = GCM_DIGEST_SIZE;
//            ctx->ctx.gmac.encrypt = (nettle_cipher_func *)aes192_encrypt;
//            break;
//        case GNUTLS_MAC_AES_GMAC_256:
//            ctx->set_key = _wrap_gmac_aes256_set_key;
//            ctx->set_nonce = _wrap_gmac_set_nonce;
//            ctx->update = _wrap_gmac_update;
//            ctx->digest = _wrap_gmac_digest;
//            ctx->ctx_ptr = &ctx->ctx.gmac;
//            ctx->length = GCM_DIGEST_SIZE;
//            ctx->ctx.gmac.encrypt = (nettle_cipher_func *)aes256_encrypt;
//            break;
        default:
            assert(0);
            gnutls_assert();
            return GNUTLS_E_INVALID_REQUEST;
    }

    return 0;
}

static int wrap_nettle_mac_init(gnutls_mac_algorithm_t algo, void **_ctx)
{
    struct nettle_mac_ctx *ctx;
    int ret;

    ctx = calloc(1, sizeof(struct nettle_mac_ctx));
    if (ctx == NULL) {
        gnutls_assert();
        return GNUTLS_E_MEMORY_ERROR;
    }

    ctx->algo = algo;

    ret = _mac_ctx_init(algo, ctx);
    if (ret < 0) {
        free(ctx);
        return gnutls_assert_val(ret);
    }

    *_ctx = ctx;

    return 0;
}

static int
wrap_nettle_mac_set_key(void *_ctx, const void *key, size_t keylen)
{
    struct nettle_mac_ctx *ctx = _ctx;

    ctx->set_key(ctx->ctx_ptr, keylen, key);
    return 0;
}

static int
wrap_nettle_mac_set_nonce(void *_ctx, const void *nonce, size_t noncelen)
{
    struct nettle_mac_ctx *ctx = _ctx;

    if (ctx->set_nonce == NULL)
        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

    if (nonce == NULL || noncelen == 0)
        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

    ctx->set_nonce(ctx->ctx_ptr, noncelen, nonce);

    return GNUTLS_E_SUCCESS;
}

static int
wrap_nettle_mac_update(void *_ctx, const void *text, size_t textsize)
{
    struct nettle_mac_ctx *ctx = _ctx;

    ctx->update(ctx->ctx_ptr, textsize, text);

    return GNUTLS_E_SUCCESS;
}

static int
wrap_nettle_mac_output(void *src_ctx, void *digest, size_t digestsize)
{
    struct nettle_mac_ctx *ctx;
    ctx = src_ctx;

    if (digestsize < ctx->length) {
        gnutls_assert();
        return GNUTLS_E_SHORT_MEMORY_BUFFER;
    }

    ctx->digest(ctx->ctx_ptr, digestsize, digest);

    return 0;
}

static void wrap_nettle_mac_deinit(void *hd)
{
    struct nettle_mac_ctx *ctx = hd;

    memset(ctx, 0, sizeof(*ctx));
    free(ctx);
}


static int wrap_nettle_mac_fast(gnutls_mac_algorithm_t algo,
                                const void *nonce, size_t nonce_size,
                                const void *key, size_t key_size,
                                const void *text, size_t text_size,
                                void *digest)
{
    struct nettle_mac_ctx ctx;
    int ret;

    ret = _mac_ctx_init(algo, &ctx);
    if (ret < 0)
        return gnutls_assert_val(ret);

    ctx.set_key(&ctx, key_size, key);
    if (ctx.set_nonce) {
        if (nonce == NULL || nonce_size == 0)
            return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

        ctx.set_nonce(&ctx, nonce_size, nonce);
    }
    ctx.update(&ctx, text_size, text);
    ctx.digest(&ctx, ctx.length, digest);

    memset(&ctx, 0, sizeof(ctx));

    return 0;
}

static int wrap_nettle_mac_exists(gnutls_mac_algorithm_t algo)
{
    switch (algo) {
        case GNUTLS_MAC_MD5:
            return 1;
        case GNUTLS_MAC_SHA1:
        case GNUTLS_MAC_SHA224:
        case GNUTLS_MAC_SHA256:
        case GNUTLS_MAC_SHA384:
        case GNUTLS_MAC_SHA512:
        case GNUTLS_MAC_UMAC_96:
        case GNUTLS_MAC_UMAC_128:
        case GNUTLS_MAC_AES_CMAC_128:
        case GNUTLS_MAC_AES_CMAC_256:
        case GNUTLS_MAC_AES_GMAC_128:
        case GNUTLS_MAC_AES_GMAC_192:
        case GNUTLS_MAC_AES_GMAC_256:
#if ENABLE_GOST
            case GNUTLS_MAC_GOSTR_94:
	case GNUTLS_MAC_STREEBOG_256:
	case GNUTLS_MAC_STREEBOG_512:
	case GNUTLS_MAC_GOST28147_TC26Z_IMIT:
	case GNUTLS_MAC_MAGMA_OMAC:
	case GNUTLS_MAC_KUZNYECHIK_OMAC:
#endif
            assert(0);
            return 1;
        default:
            return 0;
    }
}

static void *wrap_nettle_mac_copy(const void *_ctx)
{
    const struct nettle_mac_ctx *ctx = _ctx;
    struct nettle_mac_ctx *new_ctx;
    ptrdiff_t off = (uint8_t *)ctx->ctx_ptr - (uint8_t *)(&ctx->ctx);

    new_ctx = calloc(1, sizeof(struct nettle_mac_ctx));
    if (new_ctx == NULL)
        return NULL;

    memcpy(new_ctx, ctx, sizeof(*ctx));
    new_ctx->ctx_ptr = (uint8_t *)&new_ctx->ctx + off;

    return new_ctx;
}

gnutls_crypto_mac_st _gnutls_mac_ops = {
        .init = wrap_nettle_mac_init,
        .setkey = wrap_nettle_mac_set_key,
        .setnonce = wrap_nettle_mac_set_nonce,
        .hash = wrap_nettle_mac_update,
        .output = wrap_nettle_mac_output,
        .deinit = wrap_nettle_mac_deinit,
        .fast = wrap_nettle_mac_fast,
        .exists = wrap_nettle_mac_exists,
        .copy = wrap_nettle_mac_copy,
};

int
_gnutls_mac_init(mac_hd_st * mac, const mac_entry_st * e,
                 const void *key, int keylen)
{
    int result;
    const gnutls_crypto_mac_st *cc = NULL;

//    FAIL_IF_LIB_ERROR;

    if (unlikely(e == NULL || e->id == GNUTLS_MAC_NULL))
        return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

    mac->e = e;
    mac->mac_len = _gnutls_mac_get_algo_len(e);

    /* check if a digest has been registered
     */
    cc = _gnutls_get_crypto_mac(e->id);
    if (cc != NULL && cc->init != NULL) {
        if (cc->init(e->id, &mac->handle) < 0) {
            gnutls_assert();
            return GNUTLS_E_HASH_FAILED;
        }

        if (cc->setkey(mac->handle, key, keylen) < 0) {
            gnutls_assert();
            cc->deinit(mac->handle);
            return GNUTLS_E_HASH_FAILED;
        }

        mac->hash = cc->hash;
        mac->setnonce = cc->setnonce;
        mac->output = cc->output;
        mac->deinit = cc->deinit;
        mac->copy = cc->copy;
        mac->setkey = cc->setkey;

        return 0;
    }

    result = _gnutls_mac_ops.init(e->id, &mac->handle);
    if (result < 0) {
        gnutls_assert();
        return result;
    }

    mac->hash = _gnutls_mac_ops.hash;
    mac->setnonce = _gnutls_mac_ops.setnonce;
    mac->output = _gnutls_mac_ops.output;
    mac->deinit = _gnutls_mac_ops.deinit;
    mac->copy = _gnutls_mac_ops.copy;
    mac->setkey = _gnutls_mac_ops.setkey;

    if (_gnutls_mac_ops.setkey(mac->handle, key, keylen) < 0) {
        gnutls_assert();
        mac->deinit(mac->handle);
        return GNUTLS_E_HASH_FAILED;
    }

    return 0;
}

const mac_entry_st *_gnutls_mac_to_entry(gnutls_mac_algorithm_t c);

#define GNUTLS_HASH_LOOP(b) \
	const mac_entry_st *p; \
		for(p = hash_algorithms; p->name != NULL; p++) { b ; }

#define GNUTLS_HASH_ALG_LOOP(a) \
			GNUTLS_HASH_LOOP( if(p->id == algorithm) { a; break; } )

const mac_entry_st *_gnutls_mac_to_entry(gnutls_mac_algorithm_t c)
{
    GNUTLS_HASH_LOOP(if (c == p->id) return p);

    return NULL;
}

#define mac_to_entry(x) _gnutls_mac_to_entry(x)

int gnutls_hmac_init(gnutls_hmac_hd_t * dig,
                 gnutls_mac_algorithm_t algorithm,
                 const void *key, size_t keylen)
{
    /* MD5 is only allowed internally for TLS */
    if (is_mac_algo_forbidden(algorithm))
        return gnutls_assert_val(GNUTLS_E_UNWANTED_ALGORITHM);

//    *dig = malloc(sizeof(mac_hd_st));
//    if (*dig == NULL) {
//        gnutls_assert();
//        return GNUTLS_E_MEMORY_ERROR;
//    }

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