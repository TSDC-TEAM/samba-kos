#ifndef KOSGNUTLS_H
#define KOSGNUTLS_H

#ifndef __KOS__
#include <bits/stdint-uintn.h>
#endif
#include <stddef.h>
#include <sys/uio.h>
#include <stdio.h>


static void DumpHex(const void* data, size_t size) {
    char ascii[17];
    size_t i, j;
    ascii[16] = '\0';
    for (i = 0; i < size; ++i) {
        printf("%02X ", ((unsigned char*)data)[i]);
        if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
            ascii[i % 16] = ((unsigned char*)data)[i];
        } else {
            ascii[i % 16] = '.';
        }
        if ((i+1) % 8 == 0 || i+1 == size) {
            printf(" ");
            if ((i+1) % 16 == 0) {
                printf("|  %s \n", ascii);
            } else if (i+1 == size) {
                ascii[(i+1) % 16] = '\0';
                if ((i+1) % 16 <= 8) {
                    printf(" ");
                }
                for (j = (i+1) % 16; j < 16; ++j) {
                    printf("   ");
                }
                printf("|  %s \n", ascii);
            }
        }
    }
    fflush(stdout);
}

#define BSIZE 1028

#undef unlikely
#define unlikely(x) (x)

#define GNUTLS_E_SUCCESS 0
#define	GNUTLS_E_UNKNOWN_COMPRESSION_ALGORITHM -3
#define	GNUTLS_E_UNKNOWN_CIPHER_TYPE -6
#define	GNUTLS_E_LARGE_PACKET -7
#define GNUTLS_E_UNSUPPORTED_VERSION_PACKET -8	/* GNUTLS_A_PROTOCOL_VERSION */
#define GNUTLS_E_TLS_PACKET_DECODING_ERROR GNUTLS_E_UNEXPECTED_PACKET_LENGTH
#define GNUTLS_E_UNEXPECTED_PACKET_LENGTH -9	/* GNUTLS_A_DECODE_ERROR */
#define GNUTLS_E_INVALID_SESSION -10
#define GNUTLS_E_FATAL_ALERT_RECEIVED -12
#define GNUTLS_E_UNEXPECTED_PACKET -15	/* GNUTLS_A_UNEXPECTED_MESSAGE */
#define GNUTLS_E_WARNING_ALERT_RECEIVED -16
#define GNUTLS_E_ERROR_IN_FINISHED_PACKET -18
#define GNUTLS_E_UNEXPECTED_HANDSHAKE_PACKET -19
#define	GNUTLS_E_UNKNOWN_CIPHER_SUITE -21	/* GNUTLS_A_HANDSHAKE_FAILURE */
#define	GNUTLS_E_UNWANTED_ALGORITHM -22
#define	GNUTLS_E_MPI_SCAN_FAILED -23
#define GNUTLS_E_DECRYPTION_FAILED -24	/* GNUTLS_A_DECRYPTION_FAILED, GNUTLS_A_BAD_RECORD_MAC */
#define GNUTLS_E_MEMORY_ERROR -25
#define GNUTLS_E_DECOMPRESSION_FAILED -26	/* GNUTLS_A_DECOMPRESSION_FAILURE */
#define GNUTLS_E_COMPRESSION_FAILED -27
#define GNUTLS_E_AGAIN -28
#define GNUTLS_E_EXPIRED -29
#define GNUTLS_E_DB_ERROR -30
#define GNUTLS_E_SRP_PWD_ERROR GNUTLS_E_KEYFILE_ERROR
#define GNUTLS_E_KEYFILE_ERROR -31
#define GNUTLS_E_INSUFFICIENT_CREDENTIALS -32
#define GNUTLS_E_INSUFICIENT_CREDENTIALS GNUTLS_E_INSUFFICIENT_CREDENTIALS	/* for backwards compatibility only */
#define GNUTLS_E_INSUFFICIENT_CRED GNUTLS_E_INSUFFICIENT_CREDENTIALS
#define GNUTLS_E_INSUFICIENT_CRED GNUTLS_E_INSUFFICIENT_CREDENTIALS	/* for backwards compatibility only */

#define GNUTLS_E_HASH_FAILED -33
#define GNUTLS_E_BASE64_DECODING_ERROR -34

#define	GNUTLS_E_MPI_PRINT_FAILED -35
#define GNUTLS_E_REHANDSHAKE -37	/* GNUTLS_A_NO_RENEGOTIATION */
#define GNUTLS_E_GOT_APPLICATION_DATA -38
#define GNUTLS_E_RECORD_LIMIT_REACHED -39
#define GNUTLS_E_ENCRYPTION_FAILED -40

#define GNUTLS_E_PK_ENCRYPTION_FAILED -44
#define GNUTLS_E_PK_DECRYPTION_FAILED -45
#define GNUTLS_E_PK_SIGN_FAILED -46
#define GNUTLS_E_X509_UNSUPPORTED_CRITICAL_EXTENSION -47
#define GNUTLS_E_KEY_USAGE_VIOLATION -48
#define GNUTLS_E_NO_CERTIFICATE_FOUND -49	/* GNUTLS_A_BAD_CERTIFICATE */
#define GNUTLS_E_INVALID_REQUEST -50
#define GNUTLS_E_SHORT_MEMORY_BUFFER -51
#define GNUTLS_E_INTERRUPTED -52
#define GNUTLS_E_PUSH_ERROR -53
#define GNUTLS_E_PULL_ERROR -54
#define GNUTLS_E_RECEIVED_ILLEGAL_PARAMETER -55	/* GNUTLS_A_ILLEGAL_PARAMETER */
#define GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE -56
#define GNUTLS_E_PKCS1_WRONG_PAD -57
#define GNUTLS_E_RECEIVED_ILLEGAL_EXTENSION -58
#define GNUTLS_E_INTERNAL_ERROR -59
#define GNUTLS_E_DH_PRIME_UNACCEPTABLE -63
#define GNUTLS_E_FILE_ERROR -64
#define GNUTLS_E_TOO_MANY_EMPTY_PACKETS -78
#define GNUTLS_E_UNKNOWN_PK_ALGORITHM -80
#define GNUTLS_E_TOO_MANY_HANDSHAKE_PACKETS -81
#define GNUTLS_E_RECEIVED_DISALLOWED_NAME -82 /* GNUTLS_A_ILLEGAL_PARAMETER */
#define GNUTLS_E_CERTIFICATE_REQUIRED -112 /* GNUTLS_A_CERTIFICATE_REQUIRED */

/* returned if you need to generate temporary RSA
 * parameters. These are needed for export cipher suites.
 */
#define GNUTLS_E_NO_TEMPORARY_RSA_PARAMS -84

#define GNUTLS_E_NO_COMPRESSION_ALGORITHMS -86
#define GNUTLS_E_NO_CIPHER_SUITES -87

#define GNUTLS_E_OPENPGP_GETKEY_FAILED -88
#define GNUTLS_E_PK_SIG_VERIFY_FAILED -89

#define GNUTLS_E_ILLEGAL_SRP_USERNAME -90
#define GNUTLS_E_SRP_PWD_PARSING_ERROR GNUTLS_E_KEYFILE_PARSING_ERROR
#define GNUTLS_E_KEYFILE_PARSING_ERROR -91
#define GNUTLS_E_NO_TEMPORARY_DH_PARAMS -93

/* For certificate and key stuff
 */
#define GNUTLS_E_ASN1_ELEMENT_NOT_FOUND -67
#define GNUTLS_E_ASN1_IDENTIFIER_NOT_FOUND -68
#define GNUTLS_E_ASN1_DER_ERROR -69
#define GNUTLS_E_ASN1_VALUE_NOT_FOUND -70
#define GNUTLS_E_ASN1_GENERIC_ERROR -71
#define GNUTLS_E_ASN1_VALUE_NOT_VALID -72
#define GNUTLS_E_ASN1_TAG_ERROR -73
#define GNUTLS_E_ASN1_TAG_IMPLICIT -74
#define GNUTLS_E_ASN1_TYPE_ANY_ERROR -75
#define GNUTLS_E_ASN1_SYNTAX_ERROR -76
#define GNUTLS_E_ASN1_DER_OVERFLOW -77
#define GNUTLS_E_OPENPGP_UID_REVOKED -79
#define GNUTLS_E_CERTIFICATE_ERROR -43
#define GNUTLS_E_X509_CERTIFICATE_ERROR GNUTLS_E_CERTIFICATE_ERROR
#define GNUTLS_E_CERTIFICATE_KEY_MISMATCH -60
#define GNUTLS_E_UNSUPPORTED_CERTIFICATE_TYPE -61	/* GNUTLS_A_UNSUPPORTED_CERTIFICATE */
#define GNUTLS_E_X509_UNKNOWN_SAN -62
#define GNUTLS_E_OPENPGP_FINGERPRINT_UNSUPPORTED -94
#define GNUTLS_E_X509_UNSUPPORTED_ATTRIBUTE -95
#define GNUTLS_E_UNKNOWN_HASH_ALGORITHM -96
#define GNUTLS_E_UNKNOWN_PKCS_CONTENT_TYPE -97
#define GNUTLS_E_UNKNOWN_PKCS_BAG_TYPE -98
#define GNUTLS_E_INVALID_PASSWORD -99
#define GNUTLS_E_MAC_VERIFY_FAILED -100	/* for PKCS #12 MAC */
#define GNUTLS_E_CONSTRAINT_ERROR -101

#define GNUTLS_E_WARNING_IA_IPHF_RECEIVED -102
#define GNUTLS_E_WARNING_IA_FPHF_RECEIVED -103

#define GNUTLS_E_IA_VERIFY_FAILED -104
#define GNUTLS_E_UNKNOWN_ALGORITHM -105
#define GNUTLS_E_UNSUPPORTED_SIGNATURE_ALGORITHM -106
#define GNUTLS_E_SAFE_RENEGOTIATION_FAILED -107
#define GNUTLS_E_UNSAFE_RENEGOTIATION_DENIED -108
#define GNUTLS_E_UNKNOWN_SRP_USERNAME -109
#define GNUTLS_E_PREMATURE_TERMINATION -110

#define GNUTLS_E_MALFORMED_CIDR -111

#define GNUTLS_E_BASE64_ENCODING_ERROR -201
#define GNUTLS_E_INCOMPATIBLE_GCRYPT_LIBRARY -202	/* obsolete */
#define GNUTLS_E_INCOMPATIBLE_CRYPTO_LIBRARY -202
#define GNUTLS_E_INCOMPATIBLE_LIBTASN1_LIBRARY -203

#define GNUTLS_E_OPENPGP_KEYRING_ERROR -204
#define GNUTLS_E_X509_UNSUPPORTED_OID -205

#define GNUTLS_E_RANDOM_FAILED -206
#define GNUTLS_E_BASE64_UNEXPECTED_HEADER_ERROR -207

#define GNUTLS_E_OPENPGP_SUBKEY_ERROR -208

#define GNUTLS_E_CRYPTO_ALREADY_REGISTERED GNUTLS_E_ALREADY_REGISTERED
#define GNUTLS_E_ALREADY_REGISTERED -209

#define GNUTLS_E_HANDSHAKE_TOO_LARGE -210

#define GNUTLS_E_CRYPTODEV_IOCTL_ERROR -211
#define GNUTLS_E_CRYPTODEV_DEVICE_ERROR -212

#define GNUTLS_E_CHANNEL_BINDING_NOT_AVAILABLE -213
#define GNUTLS_E_BAD_COOKIE -214
#define GNUTLS_E_OPENPGP_PREFERRED_KEY_ERROR -215
#define GNUTLS_E_INCOMPAT_DSA_KEY_WITH_TLS_PROTOCOL -216
#define GNUTLS_E_INSUFFICIENT_SECURITY -217

#define GNUTLS_E_HEARTBEAT_PONG_RECEIVED -292
#define GNUTLS_E_HEARTBEAT_PING_RECEIVED -293

#define GNUTLS_E_UNRECOGNIZED_NAME -294

/* PKCS11 related */
#define GNUTLS_E_PKCS11_ERROR -300
#define GNUTLS_E_PKCS11_LOAD_ERROR -301
#define GNUTLS_E_PARSING_ERROR -302
#define GNUTLS_E_PKCS11_PIN_ERROR -303

#define GNUTLS_E_PKCS11_SLOT_ERROR -305
#define GNUTLS_E_LOCKING_ERROR -306
#define GNUTLS_E_PKCS11_ATTRIBUTE_ERROR -307
#define GNUTLS_E_PKCS11_DEVICE_ERROR -308
#define GNUTLS_E_PKCS11_DATA_ERROR -309
#define GNUTLS_E_PKCS11_UNSUPPORTED_FEATURE_ERROR -310
#define GNUTLS_E_PKCS11_KEY_ERROR -311
#define GNUTLS_E_PKCS11_PIN_EXPIRED -312
#define GNUTLS_E_PKCS11_PIN_LOCKED -313
#define GNUTLS_E_PKCS11_SESSION_ERROR -314
#define GNUTLS_E_PKCS11_SIGNATURE_ERROR -315
#define GNUTLS_E_PKCS11_TOKEN_ERROR -316
#define GNUTLS_E_PKCS11_USER_ERROR -317

#define GNUTLS_E_CRYPTO_INIT_FAILED -318
#define GNUTLS_E_TIMEDOUT -319
#define GNUTLS_E_USER_ERROR -320
#define GNUTLS_E_ECC_NO_SUPPORTED_CURVES -321
#define GNUTLS_E_ECC_UNSUPPORTED_CURVE -322
#define GNUTLS_E_PKCS11_REQUESTED_OBJECT_NOT_AVAILBLE -323
#define GNUTLS_E_CERTIFICATE_LIST_UNSORTED -324
#define GNUTLS_E_ILLEGAL_PARAMETER -325 /* GNUTLS_A_ILLEGAL_PARAMETER */
#define GNUTLS_E_NO_PRIORITIES_WERE_SET -326
#define GNUTLS_E_X509_UNSUPPORTED_EXTENSION -327
#define GNUTLS_E_SESSION_EOF -328

#define GNUTLS_E_TPM_ERROR -329
#define GNUTLS_E_TPM_KEY_PASSWORD_ERROR -330
#define GNUTLS_E_TPM_SRK_PASSWORD_ERROR -331
#define GNUTLS_E_TPM_SESSION_ERROR -332
#define GNUTLS_E_TPM_KEY_NOT_FOUND -333
#define GNUTLS_E_TPM_UNINITIALIZED -334
#define GNUTLS_E_TPM_NO_LIB -335

#define GNUTLS_E_NO_CERTIFICATE_STATUS -340
#define GNUTLS_E_OCSP_RESPONSE_ERROR -341
#define GNUTLS_E_RANDOM_DEVICE_ERROR -342
#define GNUTLS_E_AUTH_ERROR -343
#define GNUTLS_E_NO_APPLICATION_PROTOCOL -344
#define GNUTLS_E_SOCKETS_INIT_ERROR -345
#define GNUTLS_E_KEY_IMPORT_FAILED -346
#define GNUTLS_E_INAPPROPRIATE_FALLBACK -347 /*GNUTLS_A_INAPPROPRIATE_FALLBACK*/
#define GNUTLS_E_CERTIFICATE_VERIFICATION_ERROR -348
#define GNUTLS_E_PRIVKEY_VERIFICATION_ERROR -349
#define GNUTLS_E_UNEXPECTED_EXTENSIONS_LENGTH -350 /*GNUTLS_A_DECODE_ERROR*/
#define GNUTLS_E_ASN1_EMBEDDED_NULL_IN_STRING -351

#define GNUTLS_E_SELF_TEST_ERROR -400
#define GNUTLS_E_NO_SELF_TEST -401
#define GNUTLS_E_LIB_IN_ERROR_STATE -402
#define GNUTLS_E_PK_GENERATION_ERROR -403
#define GNUTLS_E_IDNA_ERROR -404

#define GNUTLS_E_NEED_FALLBACK -405
#define GNUTLS_E_SESSION_USER_ID_CHANGED -406
#define GNUTLS_E_HANDSHAKE_DURING_FALSE_START -407
#define GNUTLS_E_UNAVAILABLE_DURING_HANDSHAKE -408
#define GNUTLS_E_PK_INVALID_PUBKEY -409
#define GNUTLS_E_PK_INVALID_PRIVKEY -410
#define GNUTLS_E_NOT_YET_ACTIVATED -411
#define GNUTLS_E_INVALID_UTF8_STRING -412
#define GNUTLS_E_NO_EMBEDDED_DATA -413
#define GNUTLS_E_INVALID_UTF8_EMAIL -414
#define GNUTLS_E_INVALID_PASSWORD_STRING -415
#define GNUTLS_E_CERTIFICATE_TIME_ERROR -416
#define GNUTLS_E_RECORD_OVERFLOW -417	/* GNUTLS_A_RECORD_OVERFLOW */
#define GNUTLS_E_ASN1_TIME_ERROR -418
#define GNUTLS_E_INCOMPATIBLE_SIG_WITH_KEY -419
#define GNUTLS_E_PK_INVALID_PUBKEY_PARAMS -420
#define GNUTLS_E_PK_NO_VALIDATION_PARAMS -421
#define GNUTLS_E_OCSP_MISMATCH_WITH_CERTS -422

#define GNUTLS_E_NO_COMMON_KEY_SHARE -423
#define GNUTLS_E_REAUTH_REQUEST -424
#define GNUTLS_E_TOO_MANY_MATCHES -425
#define GNUTLS_E_CRL_VERIFICATION_ERROR -426
#define GNUTLS_E_MISSING_EXTENSION -427
#define GNUTLS_E_DB_ENTRY_EXISTS -428
#define GNUTLS_E_EARLY_DATA_REJECTED -429
#define GNUTLS_E_X509_DUPLICATE_EXTENSION -430

#define GNUTLS_E_UNIMPLEMENTED_FEATURE -1250

/* Internal errors of the library; will never be returned
 * to a calling application */
#define GNUTLS_E_INT_RET_0 -1251
#define GNUTLS_E_INT_CHECK_AGAIN -1252

#define GNUTLS_E_APPLICATION_ERROR_MAX -65000
#define GNUTLS_E_APPLICATION_ERROR_MIN -65500

#define GNUTLS_CIPHER_FLAG_ONLY_AEAD	(1 << 0) /* When set, this cipher is only available through the new AEAD API */
#define GNUTLS_CIPHER_FLAG_XOR_NONCE	(1 << 1) /* In this TLS AEAD cipher xor the implicit_iv with the nonce */
#define GNUTLS_CIPHER_FLAG_NO_REKEY	    (1 << 2) /* whether this tls1.3 cipher doesn't need to rekey after 2^24 messages */

#define GNUTLS_MAC_FLAG_PREIMAGE_INSECURE	1  /* if this algorithm should not be trusted for pre-image attacks */
#define GNUTLS_MAC_FLAG_CONTINUOUS_MAC		(1 << 1) /* if this MAC should be used in a 'continuous' way in TLS */
#define GNUTLS_MAC_FLAG_PREIMAGE_INSECURE_REVERTIBLE	(1 << 2)  /* if this algorithm should not be trusted for pre-image attacks, but can be enabled through API */
#define GNUTLS_MAC_FLAG_ALLOW_INSECURE_REVERTIBLE	(1 << 3)  /* when checking with _gnutls_digest_is_insecure2, don't treat revertible setting as fatal */


#define is_cipher_algo_forbidden(x) 0
#define is_mac_algo_forbidden(x) 0


#define ASN1_SMALL_VALUE_SIZE 16
#define ASN1_MAX_NAME_SIZE 64

typedef struct asn1_node_st asn1_node_st;
typedef asn1_node_st *asn1_node;

struct asn1_node_st
{
    /* public fields: */
    char name[ASN1_MAX_NAME_SIZE + 1];	/* Node name */
    unsigned int name_hash;
    unsigned int type;		/* Node type */
    unsigned char *value;		/* Node value */
    int value_len;
    asn1_node down;		/* Pointer to the son node */
    asn1_node right;		/* Pointer to the brother node */
    asn1_node left;		/* Pointer to the next list element */
    /* private fields: */
    unsigned char small_value[ASN1_SMALL_VALUE_SIZE];	/* For small values */

    /* values used during decoding/coding */
    int tmp_ival;
    unsigned start; /* the start of the DER sequence - if decoded */
    unsigned end; /* the end of the DER sequence - if decoded */
};

typedef int (*gnutls_pin_callback_t) (void *userdata, int attempt,
                                      const char *token_url,
                                      const char *token_label,
                                      unsigned int flags,
                                      char *pin, size_t pin_max);

struct pin_info_st {
    gnutls_pin_callback_t cb;
    void *data;
};

typedef struct {
    unsigned char *data;
    unsigned int size;
} gnutls_datum_t;

struct name_st {
    unsigned int type;
    gnutls_datum_t san;
    gnutls_datum_t othername_oid;
};

struct gnutls_subject_alt_names_st {
    struct name_st *names;
    unsigned int size;
};

typedef struct gnutls_subject_alt_names_st *gnutls_subject_alt_names_t;

typedef struct gnutls_x509_dn_st {
    asn1_node asn;
} gnutls_x509_dn_st;

typedef struct gnutls_x509_crt_int {
    asn1_node cert;
    int use_extensions;
    unsigned expanded; /* a certificate has been expanded */
    unsigned modified; /* the cached values below may no longer be valid */
    unsigned flags;

    struct pin_info_st pin;

    /* These two cached values allow fast calls to
     * get_raw_*_dn(). */
    gnutls_datum_t raw_dn;
    gnutls_datum_t raw_issuer_dn;
    gnutls_datum_t raw_spki;

    gnutls_datum_t der;

    /* this cached value allows fast access to alt names */
    gnutls_subject_alt_names_t san;
    gnutls_subject_alt_names_t ian;

    /* backwards compatibility for gnutls_x509_crt_get_subject()
     * and gnutls_x509_crt_get_issuer() */
    gnutls_x509_dn_st dn;
    gnutls_x509_dn_st idn;
} gnutls_x509_crt_int;

typedef struct gnutls_x509_crt_int *gnutls_x509_crt_t;

typedef struct {
    int hello;
//    bigint_t params[GNUTLS_MAX_PK_PARAMS];
//    unsigned int params_nr;	/* the number of parameters */
//    unsigned int pkflags; /* gnutls_pk_flag_t */
//    unsigned int qbits; /* GNUTLS_PK_DH */
//    gnutls_ecc_curve_t curve; /* GNUTLS_PK_EC, GNUTLS_PK_ED25519, GNUTLS_PK_GOST* */
//    gnutls_group_t dh_group; /* GNUTLS_PK_DH - used by ext/key_share */
//    gnutls_gost_paramset_t gost_params; /* GNUTLS_PK_GOST_* */
//    gnutls_datum_t raw_pub; /* used by x25519 */
//    gnutls_datum_t raw_priv;
//
//    unsigned int seed_size;
//    uint8_t seed[MAX_PVP_SEED_SIZE];
//    gnutls_digest_algorithm_t palgo;
//    /* public key information */
//    gnutls_x509_spki_st spki;
//
//    gnutls_pk_algorithm_t algo;
} gnutls_pk_params_st;

typedef struct gnutls_x509_privkey_int {
    /* the size of params depends on the public
     * key algorithm
     */
    gnutls_pk_params_st params;

    unsigned expanded;
    unsigned flags;

    asn1_node key;
    struct pin_info_st pin;
} gnutls_x509_privkey_int;

typedef struct gnutls_x509_privkey_int *gnutls_x509_privkey_t;

void _gnutls_null_log(void *x, ...);

#define _gnutls_assert_log _gnutls_null_log

static int gnutls_assert_val_int(int val, const char *file, const char *func, int line)
{
    _gnutls_assert_log( "ASSERT: %s[%s]:%d\n", file,func,line);
    return val;
}
#define gnutls_assert_val(x) gnutls_assert_val_int(x, __FILE__, __func__, __LINE__)

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
    GNUTLS_CIPHER_AES_128_SIV = 37,
    GNUTLS_CIPHER_AES_256_SIV = 38,
    GNUTLS_CIPHER_AES_192_GCM = 39,
    GNUTLS_CIPHER_MAGMA_CTR_ACPKM = 40,
    GNUTLS_CIPHER_KUZNYECHIK_CTR_ACPKM = 41,

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

typedef struct api_cipher_hd_st *gnutls_cipher_hd_t;

typedef struct hash_hd_st *gnutls_hash_hd_t;
typedef struct hmac_hd_st *gnutls_hmac_hd_t;

typedef struct gnutls_session_int *gnutls_session_t;

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

const cipher_entry_st *_gnutls_cipher_to_entry(gnutls_cipher_algorithm_t c);
#define cipher_to_entry(x) _gnutls_cipher_to_entry(x)

#define gnutls_assert() _gnutls_assert_log( "ASSERT: %s[%s]:%d\n", __FILE__,__func__,__LINE__);

inline static cipher_type_t _gnutls_cipher_type(const cipher_entry_st * e)
{
    if (unlikely(e == NULL))
        return CIPHER_AEAD; /* doesn't matter */
    return e->type;
}

typedef int (*gnutls_cipher_init_func) (gnutls_cipher_algorithm_t, void **ctx, int enc);
typedef int (*gnutls_cipher_setkey_func) (void *ctx, const void *key, size_t keysize);
/* old style ciphers */
typedef int (*gnutls_cipher_setiv_func) (void *ctx, const void *iv, size_t ivsize);
typedef int (*gnutls_cipher_getiv_func) (void *ctx, void *iv, size_t ivsize);
typedef int (*gnutls_cipher_encrypt_func) (void *ctx, const void *plain, size_t plainsize,
                                           void *encr, size_t encrsize);
typedef int (*gnutls_cipher_decrypt_func) (void *ctx, const void *encr, size_t encrsize,
                                           void *plain, size_t plainsize);

/* aead ciphers */
typedef int (*gnutls_cipher_auth_func) (void *ctx, const void *data, size_t datasize);
typedef void (*gnutls_cipher_tag_func) (void *ctx, void *tag, size_t tagsize);

typedef int (*gnutls_cipher_aead_encrypt_func) (void *ctx,
                                                const void *nonce, size_t noncesize,
                                                const void *auth, size_t authsize,
                                                size_t tag_size,
                                                const void *plain, size_t plainsize,
                                                void *encr, size_t encrsize);
typedef int (*gnutls_cipher_aead_decrypt_func) (void *ctx,
                                                const void *nonce, size_t noncesize,
                                                const void *auth, size_t authsize,
                                                size_t tag_size,
                                                const void *encr, size_t encrsize,
                                                void *plain, size_t plainsize);
typedef void (*gnutls_cipher_deinit_func) (void *ctx);

typedef struct {
    gnutls_cipher_init_func init;
    gnutls_cipher_setkey_func setkey;
    gnutls_cipher_setiv_func setiv;
    gnutls_cipher_getiv_func getiv;
    gnutls_cipher_encrypt_func encrypt;
    gnutls_cipher_decrypt_func decrypt;
    gnutls_cipher_aead_encrypt_func aead_encrypt;
    gnutls_cipher_aead_decrypt_func aead_decrypt;
    gnutls_cipher_deinit_func deinit;
    gnutls_cipher_auth_func auth;
    gnutls_cipher_tag_func tag;

    /* Not needed for registered on run-time. Only included
     * should define it. */
    int (*exists) (gnutls_cipher_algorithm_t);	/* true/false */
} gnutls_crypto_cipher_st;

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