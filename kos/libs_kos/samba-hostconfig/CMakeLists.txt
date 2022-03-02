set(TARGET_NAME samba-hostconfig)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/lib/param/loadparm.c
        ${SMB_SRC_ROOT}/lib/param/util.c
        ${SMB_SRC_ROOT}/lib/param/param_table.c
        ${SMB_SRC_ROOT}/lib/crypto/gnutls_error.c
        ${SMB_SRC_ROOT}/lib/crypto/gnutls_arcfour_confounded_md5.c
        ${SMB_SRC_ROOT}/lib/crypto/gnutls_weak_crypto.c
        )

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/lib/param
        ${SMB_SRC_ROOT}/bin/default/lib/param
        ${SMB_SRC_ROOT}/include/public
        ${SMB_SRC_ROOT}/bin/default/include/public
        ${SMB_SRC_ROOT}/source4
        ${SMB_SRC_ROOT}/bin/default/source4
        ${SMB_SRC_ROOT}/lib
        ${SMB_SRC_ROOT}/bin/default/lib
        ${SMB_SRC_ROOT}/source4/lib
        ${SMB_SRC_ROOT}/bin/default/source4/lib
        ${SMB_SRC_ROOT}/source4/include
        ${SMB_SRC_ROOT}/bin/default/source4/include
        ${SMB_SRC_ROOT}/include
        ${SMB_SRC_ROOT}/bin/default/include
        ${SMB_SRC_ROOT}/lib/replace
        ${SMB_SRC_ROOT}/bin/default/lib/replace
        ${SMB_SRC_ROOT}/.
        ${SMB_SRC_ROOT}/bin/default/
        ${SMB_SRC_ROOT}/lib/util/home/user/samba-of-pred-kos-2/third_party/gpfs
        ${SMB_SRC_ROOT}/bin/default/lib/util/home/user/samba-of-pred-kos-2/third_party/gpfs
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/bin/default/lib/tevent
        ${SMB_SRC_ROOT}/lib/util/charset
        ${SMB_SRC_ROOT}/bin/default/lib/util/charset
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
        ${SMB_SRC_ROOT}/lib/tdb/include
        ${SMB_SRC_ROOT}/bin/default/lib/tdb/include
        ${SMB_SRC_ROOT}/lib/tdb
        ${SMB_SRC_ROOT}/bin/default/lib/tdb
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/bin/default/lib/talloc
        /usr/include/p11-kit-1
)

target_compile_definitions(
        ${TARGET_NAME}
        PRIVATE
        _SAMBA_BUILD_=4
        HAVE_CONFIG_H=1
        _GNU_SOURCE=1
        _XOPEN_SOURCE_EXTENDED=1
        __STDC_WANT_LIB_EXT1__=1
        _REENTRANT
        _POSIX_PTHREAD_SEMANTICS
        STATIC_samba_hostconfig_MODULES=NULL
        "STATIC_samba_hostconfig_MODULES_PROTO=extern void __samba_hostconfig_dummy_module_proto(void)"
        STATIC_GNUTLS_HELPERS_MODULES=NULL
        "STATIC_GNUTLS_HELPERS_MODULES_PROTO=extern void __GNUTLS_HELPERS_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
