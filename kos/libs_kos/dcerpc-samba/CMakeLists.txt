set(TARGET_NAME dcerpc-samba)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/bin/default/librpc/dcerpc-samba.empty.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_eventlog_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_spoolss_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_netlogon_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_samr_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dfs_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_lsa_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_srvsvc_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_svcctl_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dnsserver_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_epmapper_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_wkssvc_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_atsvc_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_winreg_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_ntsvcs_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_echo_c.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_initshutdown_c.c
        )

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/librpc
        ${SMB_SRC_ROOT}/bin/default/librpc
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
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/bin/default/lib/tevent
        ${SMB_SRC_ROOT}/lib/util/charset
        ${SMB_SRC_ROOT}/bin/default/lib/util/charset
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
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        ${SMB_SRC_ROOT}/source4/lib/socket
        ${SMB_SRC_ROOT}/bin/default/source4/lib/socket
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
        ${SMB_SRC_ROOT}/lib/socket
        ${SMB_SRC_ROOT}/bin/default/lib/socket
        ${SMB_SRC_ROOT}/lib/tsocket
        ${SMB_SRC_ROOT}/bin/default/lib/tsocket
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/bin/default/lib/talloc
        ${SMB_SRC_ROOT}/libcli/nbt
        ${SMB_SRC_ROOT}/bin/default/libcli/nbt
        ${SMB_SRC_ROOT}/source4/libcli
        ${SMB_SRC_ROOT}/bin/default/source4/libcli
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
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/lib/tdb/include
        ${SMB_SRC_ROOT}/bin/default/lib/tdb/include
        ${SMB_SRC_ROOT}/lib/popt
        ${SMB_SRC_ROOT}/bin/default/lib/popt
        ${SMB_SRC_ROOT}/source3/librpc
        ${SMB_SRC_ROOT}/bin/default/source3/librpc
        ${SMB_SRC_ROOT}/lib/compression
        ${SMB_SRC_ROOT}/bin/default/lib/compression
        ${SMB_SRC_ROOT}/source4/lib/events
        ${SMB_SRC_ROOT}/bin/default/source4/lib/events
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
        STATIC_dcerpc_samba_MODULES=NULL
        "STATIC_dcerpc_samba_MODULES_PROTO=extern void __dcerpc_samba_dummy_module_proto(void)"
        STATIC_RPC_NDR_EVENTLOG_MODULES=NULL
        "STATIC_RPC_NDR_EVENTLOG_MODULES_PROTO=extern void __RPC_NDR_EVENTLOG_dummy_module_proto(void)"
        STATIC_RPC_NDR_SPOOLSS_MODULES=NULL
        "STATIC_RPC_NDR_SPOOLSS_MODULES_PROTO=extern void __RPC_NDR_SPOOLSS_dummy_module_proto(void)"
        STATIC_RPC_NDR_NETLOGON_MODULES=NULL
        "STATIC_RPC_NDR_NETLOGON_MODULES_PROTO=extern void __RPC_NDR_NETLOGON_dummy_module_proto(void)"
        STATIC_RPC_NDR_SAMR_MODULES=NULL
        "STATIC_RPC_NDR_SAMR_MODULES_PROTO=extern void __RPC_NDR_SAMR_dummy_module_proto(void)"
        STATIC_RPC_NDR_DFS_MODULES=NULL
        "STATIC_RPC_NDR_DFS_MODULES_PROTO=extern void __RPC_NDR_DFS_dummy_module_proto(void)"
        STATIC_RPC_NDR_LSA_MODULES=NULL
        "STATIC_RPC_NDR_LSA_MODULES_PROTO=extern void __RPC_NDR_LSA_dummy_module_proto(void)"
        STATIC_RPC_NDR_SRVSVC_MODULES=NULL
        "STATIC_RPC_NDR_SRVSVC_MODULES_PROTO=extern void __RPC_NDR_SRVSVC_dummy_module_proto(void)"
        STATIC_RPC_NDR_SVCCTL_MODULES=NULL
        "STATIC_RPC_NDR_SVCCTL_MODULES_PROTO=extern void __RPC_NDR_SVCCTL_dummy_module_proto(void)"
        STATIC_RPC_NDR_DNSSERVER_MODULES=NULL
        "STATIC_RPC_NDR_DNSSERVER_MODULES_PROTO=extern void __RPC_NDR_DNSSERVER_dummy_module_proto(void)"
        STATIC_RPC_NDR_EPMAPPER_MODULES=NULL
        "STATIC_RPC_NDR_EPMAPPER_MODULES_PROTO=extern void __RPC_NDR_EPMAPPER_dummy_module_proto(void)"
        STATIC_RPC_NDR_WKSSVC_MODULES=NULL
        "STATIC_RPC_NDR_WKSSVC_MODULES_PROTO=extern void __RPC_NDR_WKSSVC_dummy_module_proto(void)"
        STATIC_RPC_NDR_ATSVC_MODULES=NULL
        "STATIC_RPC_NDR_ATSVC_MODULES_PROTO=extern void __RPC_NDR_ATSVC_dummy_module_proto(void)"
        STATIC_RPC_NDR_WINREG_MODULES=NULL
        "STATIC_RPC_NDR_WINREG_MODULES_PROTO=extern void __RPC_NDR_WINREG_dummy_module_proto(void)"
        STATIC_RPC_NDR_NTSVCS_MODULES=NULL
        "STATIC_RPC_NDR_NTSVCS_MODULES_PROTO=extern void __RPC_NDR_NTSVCS_dummy_module_proto(void)"
        STATIC_RPC_NDR_ECHO_MODULES=NULL
        "STATIC_RPC_NDR_ECHO_MODULES_PROTO=extern void __RPC_NDR_ECHO_dummy_module_proto(void)"
        STATIC_RPC_NDR_INITSHUTDOWN_MODULES=NULL
        "STATIC_RPC_NDR_INITSHUTDOWN_MODULES_PROTO=extern void __RPC_NDR_INITSHUTDOWN_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
