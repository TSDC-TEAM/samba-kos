#include "kosgnutls.h"
#include <openssl/rand.h>
#include <openssl/evp.h>


int gnutls_rnd(gnutls_rnd_level_t level, void *data, size_t len)
{
    RAND_bytes(data, (int)len);
    return 0;
}

int gnutls_global_init(void)
{
    return 0;
}