#include "kosgnutls.h"
#include <openssl/evp.h>


inline static const EVP_CIPHER *gnutls_2_openssl_cipher(gnutls_cipher_algorithm_t cipher)
{
    switch (cipher) {
        case GNUTLS_CIPHER_ARCFOUR_128: {
            return EVP_rc4();
        }
        case GNUTLS_CIPHER_AES_128_GCM: {
            return EVP_aes_128_gcm();
        }
        default: {
            return NULL;
        }
    }
}