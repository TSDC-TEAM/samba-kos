set(TARGET_NAME ndr)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_misc.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_basic.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr.c
        ${SMB_SRC_ROOT}/librpc/ndr/uuid.c
)

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}
        ${SMB_SRC_ROOT}/lib
        ${SMB_SRC_ROOT}/lib/replace
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/include
        ${SMB_SRC_ROOT}/include/public
        ${SMB_SRC_ROOT}/source4
        ${SMB_SRC_ROOT}/source4/lib
        ${SMB_SRC_ROOT}/source4/include
        ${SMB_SRC_ROOT}/source4/heimdal_build
        ${SMB_SRC_ROOT}/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/source4/heimdal/lib/com_err
        ${SMB_SRC_ROOT}/source4/heimdal/include
        ${SMB_SRC_ROOT}/third_party/gpfs
        ${SMB_SRC_ROOT}/bin/default/include
        ${SMB_SRC_ROOT}/bin/default
)

target_compile_definitions(
        ${TARGET_NAME}
        PRIVATE
        _SAMBA_BUILD_=4
        HAVE_CONFIG_H=1
        _GNU_SOURCE=1
        _XOPEN_SOURCE_EXTENDED=1
        HAVE_CONFIG_H=1
        __STDC_WANT_LIB_EXT1__=1
        _REENTRANT
        STATIC_ndr_MODULES=NULL
        "STATIC_ndr_MODULES_PROTO=extern void __ndr_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        -fstack-clash-protection
)
