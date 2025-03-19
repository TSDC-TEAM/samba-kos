set(TARGET_NAME ndr-standard)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_eventlog6.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_spoolss.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_atsvc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_samr.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_winreg.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dfs.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_wkssvc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_eventlog.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_ntsvcs.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_server_id.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_initshutdown.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_echo.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dssetup.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_netlogon.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_netlogon.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_notify.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_spoolss_buf.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_srvsvc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_svcctl.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_svcctlDUP.c
        ${SMB_SRC_ROOT}/bin/default/librpc/ndr-standard.empty.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_file_id.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_lsa.c
        )

add_library(
        ${TARGET_NAME}_obj
        OBJECT
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}_obj
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
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
        ${SMB_SRC_ROOT}/libcli/security
        ${SMB_SRC_ROOT}/bin/default/libcli/security
        ${SMB_SRC_ROOT}/libcli/nbt
        ${SMB_SRC_ROOT}/bin/default/libcli/nbt
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
        STATIC_NDR_EVENTLOG6_MODULES=NULL
        "STATIC_NDR_EVENTLOG6_MODULES_PROTO=extern void __NDR_EVENTLOG6_dummy_module_proto(void)"
        STATIC_NDR_SPOOLSS_MODULES=NULL
        "STATIC_NDR_SPOOLSS_MODULES_PROTO=extern void __NDR_SPOOLSS_dummy_module_proto(void)"
        STATIC_NDR_ATSVC_MODULES=NULL
        "STATIC_NDR_ATSVC_MODULES_PROTO=extern void __NDR_ATSVC_dummy_module_proto(void)"
        STATIC_NDR_SAMR_MODULES=NULL
        "STATIC_NDR_SAMR_MODULES_PROTO=extern void __NDR_SAMR_dummy_module_proto(void)"
        STATIC_NDR_WINREG_MODULES=NULL
        "STATIC_NDR_WINREG_MODULES_PROTO=extern void __NDR_WINREG_dummy_module_proto(void)"
        STATIC_NDR_DFS_MODULES=NULL
        "STATIC_NDR_DFS_MODULES_PROTO=extern void __NDR_DFS_dummy_module_proto(void)"
        STATIC_NDR_WKSSVC_MODULES=NULL
        "STATIC_NDR_WKSSVC_MODULES_PROTO=extern void __NDR_WKSSVC_dummy_module_proto(void)"
        STATIC_NDR_EVENTLOG_MODULES=NULL
        "STATIC_NDR_EVENTLOG_MODULES_PROTO=extern void __NDR_EVENTLOG_dummy_module_proto(void)"
        STATIC_NDR_NTSVCS_MODULES=NULL
        "STATIC_NDR_NTSVCS_MODULES_PROTO=extern void __NDR_NTSVCS_dummy_module_proto(void)"
        STATIC_NDR_SERVER_ID_MODULES=NULL
        "STATIC_NDR_SERVER_ID_MODULES_PROTO=extern void __NDR_SERVER_ID_dummy_module_proto(void)"
        STATIC_NDR_INITSHUTDOWN_MODULES=NULL
        "STATIC_NDR_INITSHUTDOWN_MODULES_PROTO=extern void __NDR_INITSHUTDOWN_dummy_module_proto(void)"
        STATIC_NDR_ECHO_MODULES=NULL
        "STATIC_NDR_ECHO_MODULES_PROTO=extern void __NDR_ECHO_dummy_module_proto(void)"
        STATIC_NDR_DSSETUP_MODULES=NULL
        "STATIC_NDR_DSSETUP_MODULES_PROTO=extern void __NDR_DSSETUP_dummy_module_proto(void)"
        STATIC_NDR_NETLOGON_MODULES=NULL
        "STATIC_NDR_NETLOGON_MODULES_PROTO=extern void __NDR_NETLOGON_dummy_module_proto(void)"
        STATIC_NDR_NOTIFY_MODULES=NULL
        "STATIC_NDR_NOTIFY_MODULES_PROTO=extern void __NDR_NOTIFY_dummy_module_proto(void)"
        STATIC_NDR_SPOOLSS_BUF_MODULES=NULL
        "STATIC_NDR_SPOOLSS_BUF_MODULES_PROTO=extern void __NDR_SPOOLSS_BUF_dummy_module_proto(void)"
        STATIC_NDR_SRVSVC_MODULES=NULL
        "STATIC_NDR_SRVSVC_MODULES_PROTO=extern void __NDR_SRVSVC_dummy_module_proto(void)"
        STATIC_NDR_SVCCTL_MODULES=NULL
        "STATIC_NDR_SVCCTL_MODULES_PROTO=extern void __NDR_SVCCTL_dummy_module_proto(void)"
        STATIC_ndr_standard_MODULES=NULL
        "STATIC_ndr_standard_MODULES_PROTO=extern void __ndr_standard_dummy_module_proto(void)"
        STATIC_NDR_FILE_ID_MODULES=NULL
        "STATIC_NDR_FILE_ID_MODULES_PROTO=extern void __NDR_FILE_ID_dummy_module_proto(void)"
        STATIC_NDR_LSA_MODULES=NULL
        "STATIC_NDR_LSA_MODULES_PROTO=extern void __NDR_LSA_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}_obj
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
