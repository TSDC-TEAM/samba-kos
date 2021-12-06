set(TARGET_NAME tdb)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/lib/tdb/common/check.c
        ${SMB_SRC_ROOT}/lib/tdb/common/error.c
        ${SMB_SRC_ROOT}/lib/tdb/common/tdb.c
        ${SMB_SRC_ROOT}/lib/tdb/common/traverse.c
        ${SMB_SRC_ROOT}/lib/tdb/common/freelistcheck.c
        ${SMB_SRC_ROOT}/lib/tdb/common/lock.c
        ${SMB_SRC_ROOT}/lib/tdb/common/dump.c
        ${SMB_SRC_ROOT}/lib/tdb/common/freelist.c
        ${SMB_SRC_ROOT}/lib/tdb/common/io.c
        ${SMB_SRC_ROOT}/lib/tdb/common/open.c
        ${SMB_SRC_ROOT}/lib/tdb/common/transaction.c
        ${SMB_SRC_ROOT}/lib/tdb/common/hash.c
        ${SMB_SRC_ROOT}/lib/tdb/common/summary.c
        ${SMB_SRC_ROOT}/lib/tdb/common/rescue.c
        ${SMB_SRC_ROOT}/lib/tdb/common/mutex.c
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
        ${SMB_SRC_ROOT}/lib/tdb/include
        ${SMB_SRC_ROOT}/include
        ${SMB_SRC_ROOT}/include/public
        ${SMB_SRC_ROOT}/source4
        ${SMB_SRC_ROOT}/source4/lib
        ${SMB_SRC_ROOT}/source4/include
        ${SMB_SRC_ROOT}/source4/heimdal_build
        ${SMB_SRC_ROOT}/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/source4/heimdal/lib/com_err
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/source4/heimdal/include
        ${SMB_SRC_ROOT}/third_party/gpfs
        ${SMB_SRC_ROOT}/bin/default
        ${SMB_SRC_ROOT}/bin/default/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1/
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
        STATIC_tdb_MODULES=NULL
        "STATIC_tdb_MODULES_PROTO=extern void __tdb_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        -fstack-clash-protection
)
