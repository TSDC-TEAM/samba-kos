set(TARGET_NAME ndr-nbt)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/libcli/nbt/nbtname.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_nbt.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_nbt.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dnsp.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_dnsp.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dns.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_dns.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_dns_utils.c
        )

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/libcli/nbt
        ${SMB_SRC_ROOT}/bin/default/libcli/nbt
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
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/bin/default/lib/talloc
        ${SMB_SRC_ROOT}/librpc
        ${SMB_SRC_ROOT}/bin/default/librpc
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/bin/default/lib/tevent
        ${SMB_SRC_ROOT}/lib/util/charset
        ${SMB_SRC_ROOT}/bin/default/lib/util/charset
        ${SMB_SRC_ROOT}/libcli/security
        ${SMB_SRC_ROOT}/bin/default/libcli/security
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
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
        STATIC_NDR_NBT_BUF_MODULES=NULL
        "STATIC_NDR_NBT_BUF_MODULES_PROTO=extern void __NDR_NBT_BUF_dummy_module_proto(void)"
        STATIC_ndr_nbt_MODULES=NULL
        "STATIC_ndr_nbt_MODULES_PROTO=extern void __ndr_nbt_dummy_module_proto(void)"
        STATIC_NDR_DNSP_MODULES=NULL
        "STATIC_NDR_DNSP_MODULES_PROTO=extern void __NDR_DNSP_dummy_module_proto(void)"
        STATIC_NDR_DNS_MODULES=NULL
        "STATIC_NDR_DNS_MODULES_PROTO=extern void __NDR_DNS_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
