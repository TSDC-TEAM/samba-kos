#include "kosgnutls.h"
#include <openssl/evp.h>


#define MIN(a,b) (a) < (b) ? (a) : (b)

struct iov_iter_st {
    const giovec_t *iov;
    size_t iov_count;	/* the number of iov */
    size_t iov_index;	/* index of the current buffer */
    size_t iov_offset;	/* byte offset in the current buffer */

    uint8_t block[1024]; /* incomplete block for reading */
    size_t block_size;	/* actual block size of the cipher */
    size_t block_offset;	/* offset in block */
};

inline static const EVP_CIPHER *gnutls_2_openssl_cipher(gnutls_cipher_algorithm_t cipher)
{
    switch (cipher) {
        case GNUTLS_CIPHER_ARCFOUR_128: {
            return EVP_rc4();
        }
        case GNUTLS_CIPHER_AES_128_GCM: {
            return EVP_aes_128_gcm();
        }
        case GNUTLS_CIPHER_DES_CBC: {
            return EVP_des_cbc();
        }
        default: {
            return NULL;
        }
    }
}

inline static int gnutls_iov_iter_init(struct iov_iter_st *iter,
                                       const giovec_t *iov, size_t iov_count,
                                       size_t block_size)
{
    if (block_size > 1024)
        return -1;

    iter->iov = iov;
    iter->iov_count = iov_count;
    iter->iov_index = 0;
    iter->iov_offset = 0;
    iter->block_size = block_size;
    iter->block_offset = 0;
    return 0;
}

inline static ssize_t gnutls_iov_iter_next(struct iov_iter_st *iter, uint8_t **data)
{
    while (iter->iov_index < iter->iov_count) {
        const giovec_t *iov = &iter->iov[iter->iov_index];
        uint8_t *p = iov->iov_base;
        size_t len = iov->iov_len;
        size_t block_left;

        if (!p) {
            // skip NULL iov entries, else we run into issues below
            iter->iov_index++;
            continue;
        }

        if (len < iter->iov_offset)
            return 0;
        len -= iter->iov_offset;
        p += iter->iov_offset;

        /* We have at least one full block, return a whole set
         * of full blocks immediately. */
        if (iter->block_offset == 0 && len >= iter->block_size) {
            if ((len % iter->block_size) == 0) {
                iter->iov_index++;
                iter->iov_offset = 0;
            } else {
                len -= (len % iter->block_size);
                iter->iov_offset += len;
            }

            /* Return the blocks. */
            *data = p;
            return len;
        }

        /* We can complete one full block to return. */
        block_left = iter->block_size - iter->block_offset;
        if (len >= block_left) {
            memcpy(iter->block + iter->block_offset, p, block_left);
            if (len == block_left) {
                iter->iov_index++;
                iter->iov_offset = 0;
            } else
                iter->iov_offset += block_left;
            iter->block_offset = 0;

            /* Return the filled block. */
            *data = iter->block;
            return iter->block_size;
        }

        /* Not enough data for a full block, store in temp
         * memory and continue. */
        memcpy(iter->block + iter->block_offset, p, len);
        iter->block_offset += len;
        iter->iov_index++;
        iter->iov_offset = 0;
    }

    if (iter->block_offset > 0) {
        size_t len = iter->block_offset;

        /* Return the incomplete block. */
        *data = iter->block;
        iter->block_offset = 0;
        return len;
    }

    return 0;
}

inline static int gnutls_iov_iter_sync(struct iov_iter_st *iter, const uint8_t *data,
                                       size_t data_size)
{
    size_t iov_index;
    size_t iov_offset;

    /* We didn't return the cached block. */
    if (data != iter->block)
        return 0;

    iov_index = iter->iov_index;
    iov_offset = iter->iov_offset;

    /* When syncing a cache block we walk backwards because we only have a
     * pointer to were the block ends in the iovec, walking backwards is
     * fine as we are always writing a full block, so the whole content
     * is written in the right places:
     * iovec:     |--0--|---1---|--2--|-3-|
     * block:     |-----------------------|
     * 1st write                      |---|
     * 2nd write                |-----
     * 3rd write        |-------
     * last write |-----
     */
    while (data_size > 0) {
        const giovec_t *iov;
        uint8_t *p;
        size_t to_write;

        while (iov_offset == 0) {
            if (iov_index == 0)
                return -1;

            iov_index--;
            iov_offset = iter->iov[iov_index].iov_len;
        }

        iov = &iter->iov[iov_index];
        p = iov->iov_base;
        to_write = MIN(data_size, iov_offset);

        iov_offset -= to_write;
        data_size -= to_write;

        memcpy(p + iov_offset, &iter->block[data_size], to_write);
    }

    return 0;
}