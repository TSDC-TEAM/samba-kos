set(TARGET_NAME smb-transport)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/lib/async_req/async_sock.c
        ${SMB_SRC_ROOT}/libcli/smb/read_smb.c
        )

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/lib/async_req
        ${SMB_SRC_ROOT}/bin/default/lib/async_req
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
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
        /usr/include/p11-kit-1
        ${SMB_SRC_ROOT}/libcli/smb
        ${SMB_SRC_ROOT}/bin/default/libcli/smb
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
        STATIC_LIBASYNC_REQ_MODULES=NULL
        "STATIC_LIBASYNC_REQ_MODULES_PROTO=extern void __LIBASYNC_REQ_dummy_module_proto(void)"
        STATIC_smb_transport_MODULES=NULL
        "STATIC_smb_transport_MODULES_PROTO=extern void __smb_transport_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
