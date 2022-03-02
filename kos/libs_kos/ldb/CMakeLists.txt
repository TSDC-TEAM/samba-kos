set(TARGET_NAME ldb)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_modules.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_ldif.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_parse.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_msg.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_utf8.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_debug.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_dn.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_match.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_options.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_pack.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_attributes.c
        ${SMB_SRC_ROOT}/lib/ldb/common/attrib_handlers.c
        ${SMB_SRC_ROOT}/lib/ldb/common/ldb_controls.c
        ${SMB_SRC_ROOT}/lib/ldb/common/qsort.c
        ${SMB_SRC_ROOT}/lib/ldb/ldb_map/ldb_map.c
        ${SMB_SRC_ROOT}/lib/ldb/ldb_map/ldb_map_inbound.c
        ${SMB_SRC_ROOT}/lib/ldb/ldb_map/ldb_map_outbound.c
        )

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/lib/ldb
        ${SMB_SRC_ROOT}/bin/default/lib/ldb
        ${SMB_SRC_ROOT}/lib/ldb/include
        ${SMB_SRC_ROOT}/bin/default/lib/ldb/include
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
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/bin/default/lib/tevent
        ${SMB_SRC_ROOT}/lib/tdb/include
        ${SMB_SRC_ROOT}/bin/default/lib/tdb/include
        ${SMB_SRC_ROOT}/lib/tdb
        ${SMB_SRC_ROOT}/bin/default/lib/tdb
)

target_compile_definitions(
        ${TARGET_NAME}
        PRIVATE
        _SAMBA_BUILD_=4
        HAVE_CONFIG_H=1
        _GNU_SOURCE=1
        _XOPEN_SOURCE_EXTENDED=1
        LDB_MODULESDIR="/home/user/samba-of-pred-kos-2/bin/modules/ldb"
        __STDC_WANT_LIB_EXT1__=1
        _REENTRANT
        _POSIX_PTHREAD_SEMANTICS
        STATIC_LIBLDB_MAIN_MODULES=NULL
        "STATIC_LIBLDB_MAIN_MODULES_PROTO=extern void __LIBLDB_MAIN_dummy_module_proto(void)"
        STATIC_ldb_MODULES=NULL
        "STATIC_ldb_MODULES_PROTO=extern void __ldb_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
