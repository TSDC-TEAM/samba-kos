project(samba)

set(TARGET_NAME Smbd)

set(TARGET_EDL samba_smbd)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/source3/smbd/smbd_cleanupd.c
        ${SMB_SRC_ROOT}/source3/rpc_server/lsasd.c
        ${SMB_SRC_ROOT}/source3/rpc_server/mdssd.c
        ${SMB_SRC_ROOT}/source3/rpc_server/fssd.c
        ${SMB_SRC_ROOT}/source3/smbd/server.c
        ${SMB_SRC_ROOT}/source3/smbd/smbd_cleanupd.c
        ${SMB_SRC_ROOT}/source3/rpc_server/epmd.c
)

set(TARGET_LIBS
        ${SAMBA_EXT_MODULES}
        ${SAMBA_THIRD_PARTY_LIBS}
)

if (KOS)
    # Setting compilation flags.
    project_header_default ("STANDARD_GNU_17:YES" "STRICT_WARNINGS:NO")

    nk_build_edl_files (${TARGET_EDL}
            NK_MODULE ${PROJECT_NAME}
            EDL ${TARGET_NAME}.edl)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

    add_executable(${TARGET_NAME} ${TARGET_SRC} ${EDL_FILES})

    add_dependencies(${TARGET_NAME} ${TARGET_EDL})

    target_link_libraries(${TARGET_NAME} ${TARGET_LIBS} vfs::client)

    # We do not need default VFS entity here, which comes from vfs::client
    set_target_properties (${TARGET_NAME} PROPERTIES vfs::entity_REPLACEMENT "")
else ()
    add_executable(${TARGET_NAME} ${TARGET_SRC})

    if (TARGET_LIBS)
        target_link_libraries(${TARGET_NAME} ${TARGET_LIBS})
    endif ()
endif ()

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/source3
        ${SMB_SRC_ROOT}/bin/default/source3
        ${SMB_SRC_ROOT}/source3/include
        ${SMB_SRC_ROOT}/bin/default/source3/include
        ${SMB_SRC_ROOT}/source3/lib
        ${SMB_SRC_ROOT}/bin/default/source3/lib
        ${SMB_SRC_ROOT}/source4/heimdal/lib/com_err
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/com_err
        ${SMB_SRC_ROOT}/source4/heimdal/lib/krb5
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/krb5
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/gssapi
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/gssapi
        ${SMB_SRC_ROOT}/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/lib/tdb/include
        ${SMB_SRC_ROOT}/bin/default/lib/tdb/include
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/bin/default/lib/tevent
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/bin/default/lib/talloc
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
        ${SMB_SRC_ROOT}/source3/rpc_server
        ${SMB_SRC_ROOT}/bin/default/source3/rpc_server
        ${SMB_SRC_ROOT}/source4/heimdal_build
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build
        ${SMB_SRC_ROOT}/librpc
        ${SMB_SRC_ROOT}/bin/default/librpc
        ${SMB_SRC_ROOT}/source3/modules
        ${SMB_SRC_ROOT}/bin/default/source3/modules
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        ${SMB_SRC_ROOT}/source4/libcli
        ${SMB_SRC_ROOT}/bin/default/source4/libcli
        ${SMB_SRC_ROOT}/source4/librpc
        ${SMB_SRC_ROOT}/bin/default/source4/librpc
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/source3/auth
        ${SMB_SRC_ROOT}/bin/default/source3/auth
        ${SMB_SRC_ROOT}/source3/smbd/notifyd
        ${SMB_SRC_ROOT}/bin/default/source3/smbd/notifyd
        ${SMB_SRC_ROOT}/libcli/dns
        ${SMB_SRC_ROOT}/bin/default/libcli/dns
        ${SMB_SRC_ROOT}/source4/lib/messaging
        ${SMB_SRC_ROOT}/bin/default/source4/lib/messaging
        ${SMB_SRC_ROOT}/source3/librpc
        ${SMB_SRC_ROOT}/bin/default/source3/librpc
        ${SMB_SRC_ROOT}/source4/dsdb
        ${SMB_SRC_ROOT}/bin/default/source4/dsdb
        ${SMB_SRC_ROOT}/libds/common
        ${SMB_SRC_ROOT}/bin/default/libds/common
        ${SMB_SRC_ROOT}/auth/credentials
        ${SMB_SRC_ROOT}/bin/default/auth/credentials
        ${SMB_SRC_ROOT}/auth/gensec
        ${SMB_SRC_ROOT}/bin/default/auth/gensec
        ${SMB_SRC_ROOT}/lib/param
        ${SMB_SRC_ROOT}/bin/default/lib/param
        ${SMB_SRC_ROOT}/source3/param
        ${SMB_SRC_ROOT}/bin/default/source3/param
        ${SMB_SRC_ROOT}/libcli/smb
        ${SMB_SRC_ROOT}/bin/default/libcli/smb
        ${SMB_SRC_ROOT}/source4/heimdal/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/include
        ${SMB_SRC_ROOT}/libcli/nbt
        ${SMB_SRC_ROOT}/bin/default/libcli/nbt
        ${SMB_SRC_ROOT}/source4/lib/events
        ${SMB_SRC_ROOT}/bin/default/source4/lib/events
        ${SMB_SRC_ROOT}/source4/auth/kerberos
        ${SMB_SRC_ROOT}/bin/default/source4/auth/kerberos
        ${SMB_SRC_ROOT}/source4/lib/socket
        ${SMB_SRC_ROOT}/bin/default/source4/lib/socket
        ${SMB_SRC_ROOT}/source4/param
        ${SMB_SRC_ROOT}/bin/default/source4/param
        ${SMB_SRC_ROOT}/lib/afs
        ${SMB_SRC_ROOT}/bin/default/lib/afs
        ${SMB_SRC_ROOT}/auth
        ${SMB_SRC_ROOT}/bin/default/auth
        ${SMB_SRC_ROOT}/lib/messaging
        ${SMB_SRC_ROOT}/bin/default/lib/messaging
        ${SMB_SRC_ROOT}/lib/cmdline
        ${SMB_SRC_ROOT}/bin/default/lib/cmdline
        ${SMB_SRC_ROOT}/lib/ldb-samba
        ${SMB_SRC_ROOT}/bin/default/lib/ldb-samba
        ${SMB_SRC_ROOT}/lib/ldb/include
        ${SMB_SRC_ROOT}/bin/default/lib/ldb/include
        ${SMB_SRC_ROOT}/lib/ldb
        ${SMB_SRC_ROOT}/bin/default/lib/ldb
        ${SMB_SRC_ROOT}/source4/auth/gensec
        ${SMB_SRC_ROOT}/bin/default/source4/auth/gensec
        ${SMB_SRC_ROOT}/lib/tsocket
        ${SMB_SRC_ROOT}/bin/default/lib/tsocket
        ${SMB_SRC_ROOT}/source4/libcli/smb2
        ${SMB_SRC_ROOT}/bin/default/source4/libcli/smb2
        ${SMB_SRC_ROOT}/source4/libcli/ldap
        ${SMB_SRC_ROOT}/bin/default/source4/libcli/ldap
        ${SMB_SRC_ROOT}/libcli/auth
        ${SMB_SRC_ROOT}/bin/default/libcli/auth
        ${SMB_SRC_ROOT}/lib/dbwrap
        ${SMB_SRC_ROOT}/bin/default/lib/dbwrap
        ${SMB_SRC_ROOT}/libcli/security
        ${SMB_SRC_ROOT}/bin/default/libcli/security
        ${SMB_SRC_ROOT}/libcli/named_pipe_auth
        ${SMB_SRC_ROOT}/bin/default/libcli/named_pipe_auth
        ${SMB_SRC_ROOT}/libcli/cldap
        ${SMB_SRC_ROOT}/bin/default/libcli/cldap
        ${SMB_SRC_ROOT}/lib/tdb
        ${SMB_SRC_ROOT}/bin/default/lib/tdb
        ${SMB_SRC_ROOT}/lib/socket
        ${SMB_SRC_ROOT}/bin/default/lib/socket
        ${SMB_SRC_ROOT}/lib/krb5_wrap
        ${SMB_SRC_ROOT}/bin/default/lib/krb5_wrap
        ${SMB_SRC_ROOT}/libcli/ldap
        ${SMB_SRC_ROOT}/bin/default/libcli/ldap
        ${SMB_SRC_ROOT}/lib/util/charset
        ${SMB_SRC_ROOT}/bin/default/lib/util/charset
        ${SMB_SRC_ROOT}/source4/auth
        ${SMB_SRC_ROOT}/bin/default/source4/auth
        ${SMB_SRC_ROOT}/source4/cluster
        ${SMB_SRC_ROOT}/bin/default/source4/cluster
        ${SMB_SRC_ROOT}/lib/compression
        ${SMB_SRC_ROOT}/bin/default/lib/compression
        ${SMB_SRC_ROOT}/source3/passdb
        ${SMB_SRC_ROOT}/bin/default/source3/passdb
        ${SMB_SRC_ROOT}/libcli/http
        ${SMB_SRC_ROOT}/bin/default/libcli/http
        ${SMB_SRC_ROOT}/libcli/registry
        ${SMB_SRC_ROOT}/bin/default/libcli/registry
        ${SMB_SRC_ROOT}/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/libcli/lsarpc
        ${SMB_SRC_ROOT}/bin/default/libcli/lsarpc
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
        ${SMB_SRC_ROOT}/source4/lib/tls
        ${SMB_SRC_ROOT}/bin/default/source4/lib/tls
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/source4/heimdal/lib
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib
        ${SMB_SRC_ROOT}/nsswitch/libwbclient
        ${SMB_SRC_ROOT}/bin/default/nsswitch/libwbclient
        ${SMB_SRC_ROOT}/lib/smbconf
        ${SMB_SRC_ROOT}/bin/default/lib/smbconf
        ${SMB_SRC_ROOT}/lib/addns
        ${SMB_SRC_ROOT}/bin/default/lib/addns
        ${SMB_SRC_ROOT}/libcli/netlogon
        ${SMB_SRC_ROOT}/bin/default/libcli/netlogon
        ${SMB_SRC_ROOT}/auth/kerberos
        ${SMB_SRC_ROOT}/bin/default/auth/kerberos
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/spnego
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/spnego
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/krb5
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/krb5
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/mech
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/mech
        ${SMB_SRC_ROOT}/source4/heimdal/base
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/base
        ${SMB_SRC_ROOT}/lib/audit_logging
        ${SMB_SRC_ROOT}/bin/default/lib/audit_logging
        ${SMB_SRC_ROOT}/lib/async_req
        ${SMB_SRC_ROOT}/bin/default/lib/async_req
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/lib/pthreadpool
        ${SMB_SRC_ROOT}/bin/default/lib/pthreadpool
        ${SMB_SRC_ROOT}/nsswitch
        ${SMB_SRC_ROOT}/bin/default/nsswitch
        ${SMB_SRC_ROOT}/libcli/drsuapi
        ${SMB_SRC_ROOT}/bin/default/libcli/drsuapi
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
        ${SMB_SRC_ROOT}/auth/ntlmssp
        ${SMB_SRC_ROOT}/bin/default/auth/ntlmssp
        ${SMB_SRC_ROOT}/source4/lib/stream
        ${SMB_SRC_ROOT}/bin/default/source4/lib/stream
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
        STATIC_smbd_smbd_MODULES=NULL
        "STATIC_smbd_smbd_MODULES_PROTO=extern void __smbd_smbd_dummy_module_proto(void)"
        STATIC_CMDLINE_S3_MODULES=NULL
        "STATIC_CMDLINE_S3_MODULES_PROTO=extern void __CMDLINE_S3_dummy_module_proto(void)"
        STATIC_LSASD_MODULES=NULL
        "STATIC_LSASD_MODULES_PROTO=extern void __LSASD_dummy_module_proto(void)"
        STATIC_MDSSD_MODULES=NULL
        "STATIC_MDSSD_MODULES_PROTO=extern void __MDSSD_dummy_module_proto(void)"
        STATIC_FSSD_MODULES=NULL
        "STATIC_FSSD_MODULES_PROTO=extern void __FSSD_dummy_module_proto(void)"
        STATIC_EPMD_MODULES=NULL
        "STATIC_EPMD_MODULES_PROTO=extern void __EPMD_dummy_module_proto(void)"
)

install(TARGETS ${TARGET_NAME})
