#ifndef KOSGNUTLS_H
#define KOSGNUTLS_H

#include <bits/stdint-uintn.h>
#include <stddef.h>
#include <sys/uio.h>


typedef enum gnutls_cipher_algorithm {
    GNUTLS_CIPHER_UNKNOWN = 0,
    GNUTLS_CIPHER_NULL = 1,
    GNUTLS_CIPHER_ARCFOUR_128 = 2,
    GNUTLS_CIPHER_3DES_CBC = 3,
    GNUTLS_CIPHER_AES_128_CBC = 4,
    GNUTLS_CIPHER_AES_256_CBC = 5,
    GNUTLS_CIPHER_ARCFOUR_40 = 6,
    GNUTLS_CIPHER_CAMELLIA_128_CBC = 7,
    GNUTLS_CIPHER_CAMELLIA_256_CBC = 8,
    GNUTLS_CIPHER_AES_192_CBC = 9,
    GNUTLS_CIPHER_AES_128_GCM = 10,
    GNUTLS_CIPHER_AES_256_GCM = 11,
    GNUTLS_CIPHER_CAMELLIA_192_CBC = 12,
    GNUTLS_CIPHER_SALSA20_256 = 13,
    GNUTLS_CIPHER_ESTREAM_SALSA20_256 = 14,
    GNUTLS_CIPHER_CAMELLIA_128_GCM = 15,
    GNUTLS_CIPHER_CAMELLIA_256_GCM = 16,
    GNUTLS_CIPHER_RC2_40_CBC = 17,
    GNUTLS_CIPHER_DES_CBC = 18,
    GNUTLS_CIPHER_AES_128_CCM = 19,
    GNUTLS_CIPHER_AES_256_CCM = 20,
    GNUTLS_CIPHER_AES_128_CCM_8 = 21,
    GNUTLS_CIPHER_AES_256_CCM_8 = 22,
    GNUTLS_CIPHER_CHACHA20_POLY1305 = 23,
    GNUTLS_CIPHER_GOST28147_TC26Z_CFB = 24,
    GNUTLS_CIPHER_GOST28147_CPA_CFB = 25,
    GNUTLS_CIPHER_GOST28147_CPB_CFB = 26,
    GNUTLS_CIPHER_GOST28147_CPC_CFB = 27,
    GNUTLS_CIPHER_GOST28147_CPD_CFB = 28,
    GNUTLS_CIPHER_AES_128_CFB8 = 29,
    GNUTLS_CIPHER_AES_192_CFB8 = 30,
    GNUTLS_CIPHER_AES_256_CFB8 = 31,
    GNUTLS_CIPHER_AES_128_XTS = 32,
    GNUTLS_CIPHER_AES_256_XTS = 33,
    GNUTLS_CIPHER_GOST28147_TC26Z_CNT = 34,
    GNUTLS_CIPHER_CHACHA20_64 = 35,
    GNUTLS_CIPHER_CHACHA20_32 = 36,

    /* used only for PGP internals. Ignored in TLS/SSL
     */
    GNUTLS_CIPHER_IDEA_PGP_CFB = 200,
    GNUTLS_CIPHER_3DES_PGP_CFB = 201,
    GNUTLS_CIPHER_CAST5_PGP_CFB = 202,
    GNUTLS_CIPHER_BLOWFISH_PGP_CFB = 203,
    GNUTLS_CIPHER_SAFER_SK128_PGP_CFB = 204,
    GNUTLS_CIPHER_AES128_PGP_CFB = 205,
    GNUTLS_CIPHER_AES192_PGP_CFB = 206,
    GNUTLS_CIPHER_AES256_PGP_CFB = 207,
    GNUTLS_CIPHER_TWOFISH_PGP_CFB = 208
} gnutls_cipher_algorithm_t;

typedef enum { CIPHER_STREAM, CIPHER_BLOCK, CIPHER_AEAD } cipher_type_t;

typedef struct cipher_entry_st {
    const char *name;
    gnutls_cipher_algorithm_t id;
    uint16_t blocksize;
    uint16_t keysize;
    cipher_type_t type;
    uint16_t implicit_iv;	/* the size of implicit IV - the IV generated but not sent */
    uint16_t explicit_iv;	/* the size of explicit IV - the IV stored in record */
    uint16_t cipher_iv;	/* the size of IV needed by the cipher */
    uint16_t tagsize;
    unsigned flags;
} cipher_entry_st;

typedef int (*cipher_encrypt_func) (void *hd, const void *plaintext,
                                    size_t, void *ciphertext, size_t);
typedef int (*cipher_decrypt_func) (void *hd, const void *ciphertext,
                                    size_t, void *plaintext, size_t);

typedef int (*aead_cipher_encrypt_func) (void *hd,
                                         const void *nonce, size_t,
                                         const void *auth, size_t,
                                         size_t tag,
                                         const void *plaintext, size_t,
                                         void *ciphertext, size_t);
typedef int (*aead_cipher_decrypt_func) (void *hd,
                                         const void *nonce, size_t,
                                         const void *auth, size_t,
                                         size_t tag,
                                         const void *ciphertext, size_t,
                                         void *plaintext, size_t);

typedef int (*cipher_auth_func) (void *hd, const void *data, size_t);
typedef int (*cipher_setiv_func) (void *hd, const void *iv, size_t);
typedef int (*cipher_getiv_func) (void *hd, void *iv, size_t);

typedef int (*cipher_setkey_func) (void *hd, const void *key, size_t keysize);

typedef void (*cipher_tag_func) (void *hd, void *tag, size_t);

typedef void (*cipher_deinit_func) (void *hd);

typedef struct {
    void *handle;
    const cipher_entry_st *e;
    cipher_encrypt_func encrypt;
    cipher_decrypt_func decrypt;
    aead_cipher_encrypt_func aead_encrypt;
    aead_cipher_decrypt_func aead_decrypt;
    cipher_auth_func auth;
    cipher_tag_func tag;
    cipher_setiv_func setiv;
    cipher_getiv_func getiv;
    cipher_setkey_func setkey;
    cipher_deinit_func deinit;
} cipher_hd_st;

typedef struct api_cipher_hd_st {
    cipher_hd_st ctx_enc;
    cipher_hd_st ctx_dec;
} api_cipher_hd_st;

typedef struct {
    unsigned char *data;
    unsigned int size;
} gnutls_datum_t;

typedef struct api_cipher_hd_st *gnutls_cipher_hd_t;

typedef struct hash_hd_st *gnutls_hash_hd_t;
typedef struct hmac_hd_st *gnutls_hmac_hd_t;

typedef enum {
    GNUTLS_MAC_UNKNOWN = 0,
    GNUTLS_MAC_NULL = 1,
    GNUTLS_MAC_MD5 = 2,
    GNUTLS_MAC_SHA1 = 3,
    GNUTLS_MAC_RMD160 = 4,
    GNUTLS_MAC_MD2 = 5,
    GNUTLS_MAC_SHA256 = 6,
    GNUTLS_MAC_SHA384 = 7,
    GNUTLS_MAC_SHA512 = 8,
    GNUTLS_MAC_SHA224 = 9,
    GNUTLS_MAC_SHA3_224 = 10, /* reserved: no implementation */
    GNUTLS_MAC_SHA3_256 = 11, /* reserved: no implementation */
    GNUTLS_MAC_SHA3_384 = 12, /* reserved: no implementation */
    GNUTLS_MAC_SHA3_512 = 13, /* reserved: no implementation */
    GNUTLS_MAC_MD5_SHA1 = 14, /* reserved: no implementation */
    GNUTLS_MAC_GOSTR_94 = 15,
    GNUTLS_MAC_STREEBOG_256 = 16,
    GNUTLS_MAC_STREEBOG_512 = 17,
    /* If you add anything here, make sure you align with
       gnutls_digest_algorithm_t. */
    GNUTLS_MAC_AEAD = 200,	/* indicates that MAC is on the cipher */
    GNUTLS_MAC_UMAC_96 = 201,
    GNUTLS_MAC_UMAC_128 = 202,
    GNUTLS_MAC_AES_CMAC_128 = 203,
    GNUTLS_MAC_AES_CMAC_256 = 204,
    GNUTLS_MAC_AES_GMAC_128 = 205,
    GNUTLS_MAC_AES_GMAC_192 = 206,
    GNUTLS_MAC_AES_GMAC_256 = 207,
    GNUTLS_MAC_GOST28147_TC26Z_IMIT = 208,
    GNUTLS_MAC_SHAKE_128 = 209,
    GNUTLS_MAC_SHAKE_256 = 210
} gnutls_mac_algorithm_t;

typedef enum {
    GNUTLS_DIG_UNKNOWN = GNUTLS_MAC_UNKNOWN,
    GNUTLS_DIG_NULL = GNUTLS_MAC_NULL,
    GNUTLS_DIG_MD5 = GNUTLS_MAC_MD5,
    GNUTLS_DIG_SHA1 = GNUTLS_MAC_SHA1,
    GNUTLS_DIG_RMD160 = GNUTLS_MAC_RMD160,
    GNUTLS_DIG_MD2 = GNUTLS_MAC_MD2,
    GNUTLS_DIG_SHA256 = GNUTLS_MAC_SHA256,
    GNUTLS_DIG_SHA384 = GNUTLS_MAC_SHA384,
    GNUTLS_DIG_SHA512 = GNUTLS_MAC_SHA512,
    GNUTLS_DIG_SHA224 = GNUTLS_MAC_SHA224,
    GNUTLS_DIG_SHA3_224 = GNUTLS_MAC_SHA3_224,
    GNUTLS_DIG_SHA3_256 = GNUTLS_MAC_SHA3_256,
    GNUTLS_DIG_SHA3_384 = GNUTLS_MAC_SHA3_384,
    GNUTLS_DIG_SHA3_512 = GNUTLS_MAC_SHA3_512,
    GNUTLS_DIG_MD5_SHA1 = GNUTLS_MAC_MD5_SHA1,
    GNUTLS_DIG_GOSTR_94 = GNUTLS_MAC_GOSTR_94,
    GNUTLS_DIG_STREEBOG_256 = GNUTLS_MAC_STREEBOG_256,
    GNUTLS_DIG_STREEBOG_512 = GNUTLS_MAC_STREEBOG_512,
    GNUTLS_DIG_SHAKE_128 = GNUTLS_MAC_SHAKE_128,
    GNUTLS_DIG_SHAKE_256 = GNUTLS_MAC_SHAKE_256
    /* If you add anything here, make sure you align with
       gnutls_mac_algorithm_t. */
} gnutls_digest_algorithm_t;

typedef enum gnutls_rnd_level {
    GNUTLS_RND_NONCE = 0,
    GNUTLS_RND_RANDOM = 1,
    GNUTLS_RND_KEY = 2
} gnutls_rnd_level_t;

typedef struct api_aead_cipher_hd_st {
    cipher_hd_st ctx_enc;
} api_aead_cipher_hd_st;

typedef struct api_aead_cipher_hd_st *gnutls_aead_cipher_hd_t;

typedef struct iovec giovec_t;

const char *gnutls_strerror(int error);
const char *gnutls_strerror_name(int error);

int gnutls_cipher_encrypt(gnutls_cipher_hd_t handle, void *ptext,
                          size_t ptext_len);
int gnutls_cipher_decrypt(gnutls_cipher_hd_t handle, void *ctext,
                          size_t ctext_len);
int gnutls_cipher_init(gnutls_cipher_hd_t * handle,
                       gnutls_cipher_algorithm_t cipher,
                       const gnutls_datum_t * key, const gnutls_datum_t * iv);
void gnutls_cipher_deinit(gnutls_cipher_hd_t handle);

unsigned gnutls_cipher_get_tag_size(gnutls_cipher_algorithm_t algorithm);
unsigned gnutls_cipher_get_iv_size(gnutls_cipher_algorithm_t algorithm);
size_t gnutls_cipher_get_key_size(gnutls_cipher_algorithm_t algorithm);
int gnutls_hash(gnutls_hash_hd_t handle, const void *ptext, size_t ptext_len);
void gnutls_hash_output(gnutls_hash_hd_t handle, void *digest);
int gnutls_hash_fast(gnutls_digest_algorithm_t algorithm,
                     const void *ptext, size_t ptext_len, void *digest);
unsigned gnutls_hash_get_len(gnutls_digest_algorithm_t algorithm);
int gnutls_hash_init(gnutls_hash_hd_t * dig, gnutls_digest_algorithm_t algorithm);
void gnutls_hash_deinit(gnutls_hash_hd_t handle, void *digest);

int gnutls_hmac(gnutls_hmac_hd_t handle, const void *ptext, size_t ptext_len);
void gnutls_hmac_output(gnutls_hmac_hd_t handle, void *digest);
int gnutls_hmac_fast(gnutls_mac_algorithm_t algorithm,
                     const void *key, size_t keylen,
                     const void *ptext, size_t ptext_len, void *digest);
int gnutls_hmac_init(gnutls_hmac_hd_t * dig,
                     gnutls_mac_algorithm_t algorithm,
                     const void *key, size_t keylen);
void gnutls_hmac_deinit(gnutls_hmac_hd_t handle, void *digest);

int gnutls_rnd(gnutls_rnd_level_t level, void *data, size_t len);

int gnutls_aead_cipher_encrypt(gnutls_aead_cipher_hd_t handle,
                               const void *nonce, size_t nonce_len,
                               const void *auth, size_t auth_len,
                               size_t tag_size,
                               const void *ptext, size_t ptext_len,
                               void *ctext, size_t *ctext_len);
int gnutls_aead_cipher_encryptv2(gnutls_aead_cipher_hd_t handle,
                                 const void *nonce, size_t nonce_len,
                                 const giovec_t *auth_iov, int auth_iovcnt,
                                 const giovec_t *iov, int iovcnt,
                                 void *tag, size_t *tag_size);
int gnutls_aead_cipher_decrypt(gnutls_aead_cipher_hd_t handle,
                               const void *nonce, size_t nonce_len,
                               const void *auth, size_t auth_len,
                               size_t tag_size,
                               const void *ctext, size_t ctext_len,
                               void *ptext, size_t *ptext_len);
int gnutls_aead_cipher_decryptv2(gnutls_aead_cipher_hd_t handle,
                                 const void *nonce, size_t nonce_len,
                                 const giovec_t *auth_iov, int auth_iovcnt,
                                 const giovec_t *iov, int iovcnt,
                                 void *tag, size_t tag_size);
int gnutls_aead_cipher_init(gnutls_aead_cipher_hd_t *handle,
                            gnutls_cipher_algorithm_t cipher,
                            const gnutls_datum_t *key);
void gnutls_aead_cipher_deinit(gnutls_aead_cipher_hd_t handle);

int gnutls_global_init(void);

#endif // KOSGNUTLS_H