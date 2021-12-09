project(smb)

#libcli/smbreadline/smbreadline.c.1.o', '-o/home/user/kasperskyos/samba/bin/default/source3/client/smbclient', '-Wl,-rpath,/home/user/kasperskyos/samba/bin/shared', '-Wl,-rpath,/home/user/kasperskyos/samba/bin/shared/private', '-Wl,-Bstatic', '-Wl,-Bdynamic', '-L/home/user/kasperskyos/samba/bin/default/source4/cluster', '-L/home/user/kasperskyos/samba/bin/default/source4/lib/messaging', '-L/home/user/kasperskyos/samba/bin/default/libcli/nbt', '-L/home/user/kasperskyos/samba/bin/default/source4/lib/socket', '-L/home/user/kasperskyos/samba/bin/default/libds/common', '-L/home/user/kasperskyos/samba/bin/default/auth', '-L/home/user/kasperskyos/samba/bin/default/source4/libcli/ldap', '-L/home/user/kasperskyos/samba/bin/default/libcli/dns', '-L/home/user/kasperskyos/samba/bin/default/nsswitch', '-L/home/user/kasperskyos/samba/bin/default/source4/dsdb', '-L/home/user/kasperskyos/samba/bin/default/lib/ldb', '-L/home/user/kasperskyos/samba/bin/default/lib/ldb-samba', '-L/home/user/kasperskyos/samba/bin/default/source4/lib/events', '-L/home/user/kasperskyos/samba/bin/default/source4/auth/kerberos', '-L/home/user/kasperskyos/samba/bin/default/lib/tdb_wrap', '-L/home/user/kasperskyos/samba/bin/default/lib/tdb', '-L/home/user/kasperskyos/samba/bin/default/libcli/cldap', '-L/home/user/kasperskyos/samba/bin/default/lib/addns', '-L/home/user/kasperskyos/samba/bin/default/lib/krb5_wrap', '-L/home/user/kasperskyos/samba/bin/default/source4/heimdal_build', '-L/home/user/kasperskyos/samba/bin/default/libcli/ldap', '-L/home/user/kasperskyos/samba/bin/default/lib/socket', '-L/home/user/kasperskyos/samba/bin/default/lib/messaging', '-L/home/user/kasperskyos/samba/bin/default/lib/replace', '-L/home/user/kasperskyos/samba/bin/default/lib/tevent', '-L/home/user/kasperskyos/samba/bin/default/libcli/registry', '-L/home/user/kasperskyos/samba/bin/default/libcli/auth', '-L/home/user/kasperskyos/samba/bin/default/auth/gensec', '-L/home/user/kasperskyos/samba/bin/default/source4/librpc', '-L/home/user/kasperskyos/samba/bin/default/lib/util', '-L/home/user/kasperskyos/samba/bin/default/nsswitch/libwbclient', '-L/home/user/kasperskyos/samba/bin/default/lib', '-L/home/user/kasperskyos/samba/bin/default/libcli/util', '-L/home/user/kasperskyos/samba/bin/default/lib/param', '-L/home/user/kasperskyos/samba/bin/default/auth/credentials', '-L/home/user/kasperskyos/samba/bin/default/libcli/security', '-L/home/user/kasperskyos/samba/bin/default/lib/dbwrap', '-L/home/user/kasperskyos/samba/bin/default/lib/cmdline', '-L/home/user/kasperskyos/samba/bin/default/lib/talloc', '-L/home/user/kasperskyos/samba/bin/default/libcli/smb', '-L/home/user/kasperskyos/samba/bin/default/librpc', '-L/home/user/kasperskyos/samba/bin/default/source3', '-L/usr/local/lib', '-L/usr/local/lib', '-L/usr/lib/x86_64-linux-gnu', '-lmsrpc3-samba4', '-lsmbconf', '-llibsmb-samba4', '-lndr-standard', '-lcli-smb-common-samba4', '-ldcerpc-samba-samba4', '-ltalloc', '-lcmdline-samba4', '-lndr', '-ldcerpc-binding', '-lndr-nbt', '-ldbwrap-samba4', '-lsamba-security-samba4', '-lsamba-credentials', '-lgse-samba4', '-lndr-samba-samba4', '-lsamba-hostconfig', '-lsamba-errors', '-lsamba-sockets-samba4', '-lwbclient', '-ltevent-util', '-lndr-samba4', '-lgensec-samba4', '-lsamba-util', '-lutil-tdb-samba4', '-lcliauth-samba4', '-lutil-reg-samba4', '-lmessages-util-samba4', '-lsamba3-util-samba4', '-lsamba-debug-samba4', '-ltevent', '-lsys-rw-samba4', '-lserver-id-db-samba4', '-lreplace-samba4', '-ltalloc-report-printf-samba4', '-liov-buf-samba4', '-lsocket-blocking-samba4', '-lmessages-dgm-samba4', '-linterfaces-samba4', '-lCHARSET3-samba4', '-lsmbd-shim-samba4', '-lsamba-cluster-support-samba4', '-lcli-ldap-common-samba4', '-lasn1util-samba4', '-lkrb5-samba4', '-lkrb5samba-samba4', '-laddns-samba4', '-lgssapi-samba4', '-lcli-cldap-samba4', '-lsmb-transport-samba4', '-ltdb', '-ltdb-wrap-samba4', '-lauthkrb5-samba4', '-levents-samba4', '-lldbsamba-samba4', '-lcom_err-samba4', '-lldb', '-lsamdb-common-samba4', '-lsecrets3-samba4', '-lndr-krb5pac', '-lserver-role-samba4', '-lroken-samba4', '-lwinbind-client-samba4', '-lsamba-modules-samba4', '-lsamdb', '-lgenrand-samba4', '-lutil-setid-samba4', '-ltime-basic-samba4', '-lmsghdr-samba4', '-lhx509-samba4', '-lasn1-samba4', '-lheimbase-samba4', '-lwind-samba4', '-lhcrypto-samba4', '-lclidns-samba4', '-lcli-ldap-samba4', '-lcommon-auth-samba4', '-lflag-mapping-samba4', '-lnetif-samba4', '-lcli-nbt-samba4', '-lMESSAGING-SEND-samba4', '-lcluster-samba4', '-lpthread', '-ldl', '-lresolv', '-lutil', '-lz', '-lpopt', '-lncurses', '-lncurses', '-ltinfo', '-lgnutls', '-pie', '-Wl,-z,relro,-z,now', '-Wl,-no-undefined', '-Wl,--export-dynamic']

set(TARGET_NAME Smbclient)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/lib/cmdline/cmdline_s3.c
        ${SMB_SRC_ROOT}/source3/client/client.c
        ${SMB_SRC_ROOT}/source3/client/clitar.c
        ${SMB_SRC_ROOT}/source3/client/dnsbrowse.c
        ${SMB_SRC_ROOT}/libcli/smbreadline/smbreadline.c
)

set(TARGET_LIBS
        ${SAMBA_EXT_MODULES}
        ${SAMBA_THIRD_PARTY_LIBS}
)

include(executable)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}
        ${SMB_SRC_ROOT}/lib
        ${SMB_SRC_ROOT}/lib/tsocket
        ${SMB_SRC_ROOT}/lib/replace
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/lib/ldb-samba
        ${SMB_SRC_ROOT}/lib/ldb/include
        ${SMB_SRC_ROOT}/lib/tdb/include
        ${SMB_SRC_ROOT}/include
        ${SMB_SRC_ROOT}/include/public
        ${SMB_SRC_ROOT}/source3
        ${SMB_SRC_ROOT}/source3/lib
        ${SMB_SRC_ROOT}/source3/include
        ${SMB_SRC_ROOT}/source4/heimdal_build
        ${SMB_SRC_ROOT}/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/source4/heimdal/lib
        ${SMB_SRC_ROOT}/source4/heimdal/base
        ${SMB_SRC_ROOT}/source4/heimdal/lib/krb5
        ${SMB_SRC_ROOT}/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/source4/heimdal/lib/com_err
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/gssapi
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/mech
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/source4/heimdal/include
        ${SMB_SRC_ROOT}/third_party/gpfs
        ${SMB_SRC_ROOT}/bin/default
        ${SMB_SRC_ROOT}/bin/default/include
        ${SMB_SRC_ROOT}/bin/default/lib/ldb/include
        ${SMB_SRC_ROOT}/bin/default/librpc/
        ${SMB_SRC_ROOT}/bin/default/source4
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/krb5
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/spnego
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/krb5
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
)
