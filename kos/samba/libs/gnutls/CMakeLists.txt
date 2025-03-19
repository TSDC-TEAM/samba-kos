set(TARGET_NAME gnutls)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/lib/gnutls/kosgnutls.c
        ${SMB_SRC_ROOT}/lib/gnutls/kosgnutls_errors.c
        ${SMB_SRC_ROOT}/lib/gnutls/kosgnutls_cipher.c
        ${SMB_SRC_ROOT}/lib/gnutls/kosgnutls_hmac.c
        ${SMB_SRC_ROOT}/lib/gnutls/kosgnutls_hash.c
        ${SMB_SRC_ROOT}/lib/gnutls/kosgnutls_aead_cipher.c
)

add_library(
        ${TARGET_NAME}_obj
        OBJECT
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}_obj
        PRIVATE
        ${SMB_SRC_ROOT}/third_party/openssl/include/
)

target_compile_definitions(
        ${TARGET_NAME}_obj
        PRIVATE
)

target_compile_options(
        ${TARGET_NAME}_obj
        PRIVATE
)
