set(TARGET_NAME samba-sockets)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/lib/tsocket/tsocket.c
        ${SMB_SRC_ROOT}/lib/tsocket/tsocket_helpers.c
        ${SMB_SRC_ROOT}/lib/tsocket/tsocket_bsd.c
        ${SMB_SRC_ROOT}/lib/util/access.c
        ${SMB_SRC_ROOT}/source4/libcli/resolve/resolve.c
        ${SMB_SRC_ROOT}/source4/lib/socket/socket_unix.c
        ${SMB_SRC_ROOT}/source4/lib/socket/socket_ip.c
        ${SMB_SRC_ROOT}/source4/lib/socket/socket.c
        ${SMB_SRC_ROOT}/source4/lib/socket/access.c
        ${SMB_SRC_ROOT}/source4/lib/socket/connect_multi.c
        ${SMB_SRC_ROOT}/source4/lib/socket/connect.c
        ${SMB_SRC_ROOT}/bin/default/lib/samba-sockets.empty.c
        ${SMB_SRC_ROOT}/source4/libcli/composite/composite.c
        )

add_library(
        ${TARGET_NAME}_obj
        OBJECT
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}_obj
        PRIVATE
        ${SMB_SRC_ROOT}/lib/tsocket
        ${SMB_SRC_ROOT}/bin/default/lib/tsocket
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
        ${SMB_SRC_ROOT}/lib/util/charset
        ${SMB_SRC_ROOT}/bin/default/lib/util/charset
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        ${SMB_SRC_ROOT}/lib/socket
        ${SMB_SRC_ROOT}/bin/default/lib/socket
        ${SMB_SRC_ROOT}/source4/libcli
        ${SMB_SRC_ROOT}/bin/default/source4/libcli
        ${SMB_SRC_ROOT}/librpc
        ${SMB_SRC_ROOT}/bin/default/librpc
        ${SMB_SRC_ROOT}/libcli/nbt
        ${SMB_SRC_ROOT}/bin/default/libcli/nbt
        ${SMB_SRC_ROOT}/libcli/security
        ${SMB_SRC_ROOT}/bin/default/libcli/security
        ${SMB_SRC_ROOT}/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/source4/heimdal/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/include
        ${SMB_SRC_ROOT}/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/source4/heimdal_build
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build
        ${SMB_SRC_ROOT}/source4/lib/events
        ${SMB_SRC_ROOT}/bin/default/source4/lib/events
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
        ${SMB_SRC_ROOT}/source4/lib/socket
        ${SMB_SRC_ROOT}/bin/default/source4/lib/socket
)

target_compile_definitions(
        ${TARGET_NAME}_obj
        PRIVATE
        _SAMBA_BUILD_=4
        HAVE_CONFIG_H=1
        _GNU_SOURCE=1
        _XOPEN_SOURCE_EXTENDED=1
        __STDC_WANT_LIB_EXT1__=1
        _REENTRANT
        _POSIX_PTHREAD_SEMANTICS
        STATIC_LIBTSOCKET_MODULES=NULL
        "STATIC_LIBTSOCKET_MODULES_PROTO=extern void __LIBTSOCKET_dummy_module_proto(void)"
        STATIC_access_MODULES=NULL
        "STATIC_access_MODULES_PROTO=extern void __access_dummy_module_proto(void)"
        STATIC_LIBCLI_RESOLVE_MODULES=NULL
        "STATIC_LIBCLI_RESOLVE_MODULES_PROTO=extern void __LIBCLI_RESOLVE_dummy_module_proto(void)"
        STATIC_socket_unix_MODULES=NULL
        "STATIC_socket_unix_MODULES_PROTO=extern void __socket_unix_dummy_module_proto(void)"
        STATIC_socket_ip_MODULES=NULL
        "STATIC_socket_ip_MODULES_PROTO=extern void __socket_ip_dummy_module_proto(void)"
        STATIC_samba_socket_MODULES=NULL
        "STATIC_samba_socket_MODULES_PROTO=extern void __samba_socket_dummy_module_proto(void)"
        STATIC_samba_sockets_MODULES=NULL
        "STATIC_samba_sockets_MODULES_PROTO=extern void __samba_sockets_dummy_module_proto(void)"
        STATIC_cli_composite_MODULES=NULL
        "STATIC_cli_composite_MODULES_PROTO=extern void __cli_composite_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}_obj
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
