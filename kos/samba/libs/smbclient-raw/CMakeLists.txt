set(TARGET_NAME smbclient-raw)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawfile.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/smb_signing.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/clisocket.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/clitransport.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/clisession.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/clitree.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/clierror.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawrequest.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawreadwrite.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawsearch.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawsetfileinfo.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/raweas.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawtrans.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/clioplock.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawnegotiate.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawfsinfo.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawfileinfo.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawnotify.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawioctl.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawacl.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawdate.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawlpq.c
        ${SMB_SRC_ROOT}/source4/libcli/raw/rawshadow.c
        ${SMB_SRC_ROOT}/source4/libcli/smb_composite/loadfile.c
        ${SMB_SRC_ROOT}/source4/libcli/smb_composite/savefile.c
        ${SMB_SRC_ROOT}/source4/libcli/smb_composite/connect_nego.c
        ${SMB_SRC_ROOT}/source4/libcli/smb_composite/connect.c
        ${SMB_SRC_ROOT}/source4/libcli/smb_composite/sesssetup.c
        ${SMB_SRC_ROOT}/source4/libcli/smb_composite/fetchfile.c
        ${SMB_SRC_ROOT}/source4/libcli/smb_composite/appendacl.c
        ${SMB_SRC_ROOT}/source4/libcli/smb_composite/fsinfo.c
        ${SMB_SRC_ROOT}/source4/libcli/smb_composite/smb2.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/transport.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/request.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/session.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/tcon.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/create.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/close.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/connect.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/getinfo.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/write.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/read.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/setinfo.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/find.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/ioctl.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/logoff.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/tdis.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/flush.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/lock.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/notify.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/cancel.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/keepalive.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/break.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/util.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/signing.c
        ${SMB_SRC_ROOT}/source4/libcli/smb2/lease_break.c
        )

add_library(
        ${TARGET_NAME}_obj
        OBJECT
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}_obj
        PRIVATE
        ${SMB_SRC_ROOT}/source4/libcli
        ${SMB_SRC_ROOT}/bin/default/source4/libcli
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
        ${SMB_SRC_ROOT}/librpc
        ${SMB_SRC_ROOT}/bin/default/librpc
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/source4/heimdal_build
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build
        ${SMB_SRC_ROOT}/libcli/auth
        ${SMB_SRC_ROOT}/bin/default/libcli/auth
        ${SMB_SRC_ROOT}/source4/auth/kerberos
        ${SMB_SRC_ROOT}/bin/default/source4/auth/kerberos
        ${SMB_SRC_ROOT}/lib/dbwrap
        ${SMB_SRC_ROOT}/bin/default/lib/dbwrap
        ${SMB_SRC_ROOT}/lib/messaging
        ${SMB_SRC_ROOT}/bin/default/lib/messaging
        ${SMB_SRC_ROOT}/libcli/security
        ${SMB_SRC_ROOT}/bin/default/libcli/security
        ${SMB_SRC_ROOT}/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/lib/pthreadpool
        ${SMB_SRC_ROOT}/bin/default/lib/pthreadpool
        ${SMB_SRC_ROOT}/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/source4/heimdal/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/include
        ${SMB_SRC_ROOT}/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/nsswitch
        ${SMB_SRC_ROOT}/bin/default/nsswitch
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        ${SMB_SRC_ROOT}/auth/credentials
        ${SMB_SRC_ROOT}/bin/default/auth/credentials
        ${SMB_SRC_ROOT}/lib/param
        ${SMB_SRC_ROOT}/bin/default/lib/param
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/source4/heimdal/lib
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib
        ${SMB_SRC_ROOT}/source4/heimdal/lib/krb5
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/krb5
        ${SMB_SRC_ROOT}/libcli/lsarpc
        ${SMB_SRC_ROOT}/bin/default/libcli/lsarpc
        ${SMB_SRC_ROOT}/source4/lib/socket
        ${SMB_SRC_ROOT}/bin/default/source4/lib/socket
        ${SMB_SRC_ROOT}/source4/heimdal/lib/com_err
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/com_err
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
        ${SMB_SRC_ROOT}/source4/lib/messaging
        ${SMB_SRC_ROOT}/bin/default/source4/lib/messaging
        ${SMB_SRC_ROOT}/libcli/drsuapi
        ${SMB_SRC_ROOT}/bin/default/libcli/drsuapi
        ${SMB_SRC_ROOT}/lib/socket
        ${SMB_SRC_ROOT}/bin/default/lib/socket
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
        ${SMB_SRC_ROOT}/source4/dsdb
        ${SMB_SRC_ROOT}/bin/default/source4/dsdb
        ${SMB_SRC_ROOT}/source4/lib/tls
        ${SMB_SRC_ROOT}/bin/default/source4/lib/tls
        ${SMB_SRC_ROOT}/libds/common
        ${SMB_SRC_ROOT}/bin/default/libds/common
        ${SMB_SRC_ROOT}/lib/tdb/include
        ${SMB_SRC_ROOT}/bin/default/lib/tdb/include
        ${SMB_SRC_ROOT}/lib/tdb
        ${SMB_SRC_ROOT}/bin/default/lib/tdb
        ${SMB_SRC_ROOT}/auth/gensec
        ${SMB_SRC_ROOT}/bin/default/auth/gensec
        ${SMB_SRC_ROOT}/source3
        ${SMB_SRC_ROOT}/bin/default/source3
        ${SMB_SRC_ROOT}/source3/include
        ${SMB_SRC_ROOT}/bin/default/source3/include
        ${SMB_SRC_ROOT}/source3/lib
        ${SMB_SRC_ROOT}/bin/default/source3/lib
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/gssapi
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/gssapi
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/bin/default/lib/tevent
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/bin/default/lib/talloc
        ${SMB_SRC_ROOT}/lib/popt
        ${SMB_SRC_ROOT}/bin/default/lib/popt
        ${SMB_SRC_ROOT}/source3/librpc
        ${SMB_SRC_ROOT}/bin/default/source3/librpc
        ${SMB_SRC_ROOT}/lib/krb5_wrap
        ${SMB_SRC_ROOT}/bin/default/lib/krb5_wrap
        ${SMB_SRC_ROOT}/nsswitch/libwbclient
        ${SMB_SRC_ROOT}/bin/default/nsswitch/libwbclient
        ${SMB_SRC_ROOT}/libcli/smb
        ${SMB_SRC_ROOT}/bin/default/libcli/smb
        ${SMB_SRC_ROOT}/lib/ldb-samba
        ${SMB_SRC_ROOT}/bin/default/lib/ldb-samba
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/spnego
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/spnego
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/krb5
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/krb5
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/mech
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/mech
        ${SMB_SRC_ROOT}/source4/lib/events
        ${SMB_SRC_ROOT}/bin/default/source4/lib/events
        ${SMB_SRC_ROOT}/auth/ntlmssp
        ${SMB_SRC_ROOT}/bin/default/auth/ntlmssp
        ${SMB_SRC_ROOT}/libcli/ldap
        ${SMB_SRC_ROOT}/bin/default/libcli/ldap
        ${SMB_SRC_ROOT}/lib/ldb/include
        ${SMB_SRC_ROOT}/bin/default/lib/ldb/include
        ${SMB_SRC_ROOT}/lib/ldb
        ${SMB_SRC_ROOT}/bin/default/lib/ldb
        ${SMB_SRC_ROOT}/source4/auth
        ${SMB_SRC_ROOT}/bin/default/source4/auth
        ${SMB_SRC_ROOT}/auth
        ${SMB_SRC_ROOT}/bin/default/auth
        ${SMB_SRC_ROOT}/lib/util/charset
        ${SMB_SRC_ROOT}/bin/default/lib/util/charset
        ${SMB_SRC_ROOT}/source4/cluster
        ${SMB_SRC_ROOT}/bin/default/source4/cluster
        ${SMB_SRC_ROOT}/auth/kerberos
        ${SMB_SRC_ROOT}/bin/default/auth/kerberos
        ${SMB_SRC_ROOT}/source4/heimdal/base
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/base
        ${SMB_SRC_ROOT}/source4/auth/gensec
        ${SMB_SRC_ROOT}/bin/default/source4/auth/gensec
        ${SMB_SRC_ROOT}/source4/lib/stream
        ${SMB_SRC_ROOT}/bin/default/source4/lib/stream
        ${SMB_SRC_ROOT}/source4/param
        ${SMB_SRC_ROOT}/bin/default/source4/param
        ${SMB_SRC_ROOT}/lib/tsocket
        ${SMB_SRC_ROOT}/bin/default/lib/tsocket
        ${SMB_SRC_ROOT}/libcli/nbt
        ${SMB_SRC_ROOT}/bin/default/libcli/nbt
        ${SMB_SRC_ROOT}/libcli/http
        ${SMB_SRC_ROOT}/bin/default/libcli/http
        ${SMB_SRC_ROOT}/lib/audit_logging
        ${SMB_SRC_ROOT}/bin/default/lib/audit_logging
        ${SMB_SRC_ROOT}/lib/compression
        ${SMB_SRC_ROOT}/bin/default/lib/compression
        ${SMB_SRC_ROOT}/source4/libcli/smb2
        ${SMB_SRC_ROOT}/bin/default/source4/libcli/smb2
        ${SMB_SRC_ROOT}/lib/async_req
        ${SMB_SRC_ROOT}/bin/default/lib/async_req
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hcrypto/libtommath
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
        STATIC_smbclient_raw_MODULES=NULL
        "STATIC_smbclient_raw_MODULES_PROTO=extern void __smbclient_raw_dummy_module_proto(void)"
        STATIC_LIBCLI_SMB_COMPOSITE_MODULES=NULL
        "STATIC_LIBCLI_SMB_COMPOSITE_MODULES_PROTO=extern void __LIBCLI_SMB_COMPOSITE_dummy_module_proto(void)"
        STATIC_LIBCLI_SMB2_MODULES=NULL
        "STATIC_LIBCLI_SMB2_MODULES_PROTO=extern void __LIBCLI_SMB2_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}_obj
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
