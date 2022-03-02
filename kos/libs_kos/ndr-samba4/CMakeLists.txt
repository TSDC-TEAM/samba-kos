set(TARGET_NAME ndr-samba4)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_table.c
        ${SMB_SRC_ROOT}/bin/default/source4/librpc/gen_ndr/tables.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_messaging.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_quota.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dbgidl.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_clusapi.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_printcap.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_wmi.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_wmi.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_audiosrv.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_trkwks.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_scerpc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_winstation.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_fsrvp_state.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dsbackup.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_browser.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_winspool.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_rap.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_rap.c
        ${SMB_SRC_ROOT}/bin/default/source3/librpc/gen_ndr/ndr_perfcount.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_w32time.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_keysvc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dfsblobs.c
        ${SMB_SRC_ROOT}/bin/default/source3/librpc/gen_ndr/ndr_secrets.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_winbind.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_preg.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_preg.c
        ${SMB_SRC_ROOT}/bin/default/source4/librpc/gen_ndr/ndr_winsif.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_frstrans.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_fscc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_ODJ.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_ODJDUP.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_ioctl.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_ioctl.c
        ${SMB_SRC_ROOT}/bin/default/source4/librpc/gen_ndr/ndr_irpc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_rot.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_smb_acl.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_frsapi.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_backupkey.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_backupkey.c
        ${SMB_SRC_ROOT}/bin/default/source4/librpc/gen_ndr/ndr_ntp_signd.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_oxidresolver.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_msgsvc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_cab.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_cab.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_bkupblobs.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_bkupblobs.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_policyagent.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_wzcsvc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_remact.c
        ${SMB_SRC_ROOT}/bin/default/source4/librpc/gen_ndr/ndr_opendb.c
        ${SMB_SRC_ROOT}/bin/default/source4/librpc/gen_ndr/ndr_winsrepl.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_frsrpc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_frsrpc.c
        ${SMB_SRC_ROOT}/bin/default/source3/librpc/gen_ndr/ndr_leases_db.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_nfs4acl.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_efs.c
        ${SMB_SRC_ROOT}/bin/default/source4/librpc/ndr-samba4.empty.c
        ${SMB_SRC_ROOT}/bin/default/source4/librpc/gen_ndr/ndr_sasl_helpers.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dcerpc.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_dcerpc.c
        )

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/source4/librpc
        ${SMB_SRC_ROOT}/bin/default/source4/librpc
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
        ${SMB_SRC_ROOT}/lib/util/home/user/samba-of-pred-kos-2/third_party/gpfs
        ${SMB_SRC_ROOT}/bin/default/lib/util/home/user/samba-of-pred-kos-2/third_party/gpfs
        ${SMB_SRC_ROOT}/libcli/security
        ${SMB_SRC_ROOT}/bin/default/libcli/security
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
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
        ${SMB_SRC_ROOT}/lib/popt
        ${SMB_SRC_ROOT}/bin/default/lib/popt
        ${SMB_SRC_ROOT}/source3/librpc
        ${SMB_SRC_ROOT}/bin/default/source3/librpc
        ${SMB_SRC_ROOT}/lib/util/charset
        ${SMB_SRC_ROOT}/bin/default/lib/util/charset
        ${SMB_SRC_ROOT}/libcli/nbt
        ${SMB_SRC_ROOT}/bin/default/libcli/nbt
        ${SMB_SRC_ROOT}/lib/compression
        ${SMB_SRC_ROOT}/bin/default/lib/compression
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
        STATIC_ndr_table_MODULES=NULL
        "STATIC_ndr_table_MODULES_PROTO=extern void __ndr_table_dummy_module_proto(void)"
        STATIC_NDR_MESSAGING_MODULES=NULL
        "STATIC_NDR_MESSAGING_MODULES_PROTO=extern void __NDR_MESSAGING_dummy_module_proto(void)"
        STATIC_NDR_QUOTA_MODULES=NULL
        "STATIC_NDR_QUOTA_MODULES_PROTO=extern void __NDR_QUOTA_dummy_module_proto(void)"
        STATIC_NDR_DBGIDL_MODULES=NULL
        "STATIC_NDR_DBGIDL_MODULES_PROTO=extern void __NDR_DBGIDL_dummy_module_proto(void)"
        STATIC_NDR_CLUSAPI_MODULES=NULL
        "STATIC_NDR_CLUSAPI_MODULES_PROTO=extern void __NDR_CLUSAPI_dummy_module_proto(void)"
        STATIC_NDR_PRINTCAP_MODULES=NULL
        "STATIC_NDR_PRINTCAP_MODULES_PROTO=extern void __NDR_PRINTCAP_dummy_module_proto(void)"
        STATIC_NDR_WMI_MODULES=NULL
        "STATIC_NDR_WMI_MODULES_PROTO=extern void __NDR_WMI_dummy_module_proto(void)"
        STATIC_NDR_AUDIOSRV_MODULES=NULL
        "STATIC_NDR_AUDIOSRV_MODULES_PROTO=extern void __NDR_AUDIOSRV_dummy_module_proto(void)"
        STATIC_NDR_TRKWKS_MODULES=NULL
        "STATIC_NDR_TRKWKS_MODULES_PROTO=extern void __NDR_TRKWKS_dummy_module_proto(void)"
        STATIC_NDR_SCERPC_MODULES=NULL
        "STATIC_NDR_SCERPC_MODULES_PROTO=extern void __NDR_SCERPC_dummy_module_proto(void)"
        STATIC_NDR_WINSTATION_MODULES=NULL
        "STATIC_NDR_WINSTATION_MODULES_PROTO=extern void __NDR_WINSTATION_dummy_module_proto(void)"
        STATIC_NDR_FSRVP_STATE_MODULES=NULL
        "STATIC_NDR_FSRVP_STATE_MODULES_PROTO=extern void __NDR_FSRVP_STATE_dummy_module_proto(void)"
        STATIC_NDR_DSBACKUP_MODULES=NULL
        "STATIC_NDR_DSBACKUP_MODULES_PROTO=extern void __NDR_DSBACKUP_dummy_module_proto(void)"
        STATIC_NDR_BROWSER_MODULES=NULL
        "STATIC_NDR_BROWSER_MODULES_PROTO=extern void __NDR_BROWSER_dummy_module_proto(void)"
        STATIC_NDR_WINSPOOL_MODULES=NULL
        "STATIC_NDR_WINSPOOL_MODULES_PROTO=extern void __NDR_WINSPOOL_dummy_module_proto(void)"
        STATIC_NDR_RAP_MODULES=NULL
        "STATIC_NDR_RAP_MODULES_PROTO=extern void __NDR_RAP_dummy_module_proto(void)"
        STATIC_NDR_PERFCOUNT_MODULES=NULL
        "STATIC_NDR_PERFCOUNT_MODULES_PROTO=extern void __NDR_PERFCOUNT_dummy_module_proto(void)"
        STATIC_NDR_W32TIME_MODULES=NULL
        "STATIC_NDR_W32TIME_MODULES_PROTO=extern void __NDR_W32TIME_dummy_module_proto(void)"
        STATIC_NDR_KEYSVC_MODULES=NULL
        "STATIC_NDR_KEYSVC_MODULES_PROTO=extern void __NDR_KEYSVC_dummy_module_proto(void)"
        STATIC_NDR_DFSBLOBS_MODULES=NULL
        "STATIC_NDR_DFSBLOBS_MODULES_PROTO=extern void __NDR_DFSBLOBS_dummy_module_proto(void)"
        STATIC_NDR_SECRETS_MODULES=NULL
        "STATIC_NDR_SECRETS_MODULES_PROTO=extern void __NDR_SECRETS_dummy_module_proto(void)"
        STATIC_NDR_WINBIND_MODULES=NULL
        "STATIC_NDR_WINBIND_MODULES_PROTO=extern void __NDR_WINBIND_dummy_module_proto(void)"
        STATIC_NDR_PREG_MODULES=NULL
        "STATIC_NDR_PREG_MODULES_PROTO=extern void __NDR_PREG_dummy_module_proto(void)"
        STATIC_NDR_WINSIF_MODULES=NULL
        "STATIC_NDR_WINSIF_MODULES_PROTO=extern void __NDR_WINSIF_dummy_module_proto(void)"
        STATIC_NDR_FRSTRANS_MODULES=NULL
        "STATIC_NDR_FRSTRANS_MODULES_PROTO=extern void __NDR_FRSTRANS_dummy_module_proto(void)"
        STATIC_NDR_FSCC_MODULES=NULL
        "STATIC_NDR_FSCC_MODULES_PROTO=extern void __NDR_FSCC_dummy_module_proto(void)"
        STATIC_NDR_ODJ_MODULES=NULL
        "STATIC_NDR_ODJ_MODULES_PROTO=extern void __NDR_ODJ_dummy_module_proto(void)"
        STATIC_NDR_IOCTL_MODULES=NULL
        "STATIC_NDR_IOCTL_MODULES_PROTO=extern void __NDR_IOCTL_dummy_module_proto(void)"
        STATIC_NDR_IRPC_MODULES=NULL
        "STATIC_NDR_IRPC_MODULES_PROTO=extern void __NDR_IRPC_dummy_module_proto(void)"
        STATIC_NDR_ROT_MODULES=NULL
        "STATIC_NDR_ROT_MODULES_PROTO=extern void __NDR_ROT_dummy_module_proto(void)"
        STATIC_NDR_SMB_ACL_MODULES=NULL
        "STATIC_NDR_SMB_ACL_MODULES_PROTO=extern void __NDR_SMB_ACL_dummy_module_proto(void)"
        STATIC_NDR_FRSAPI_MODULES=NULL
        "STATIC_NDR_FRSAPI_MODULES_PROTO=extern void __NDR_FRSAPI_dummy_module_proto(void)"
        STATIC_NDR_BACKUPKEY_MODULES=NULL
        "STATIC_NDR_BACKUPKEY_MODULES_PROTO=extern void __NDR_BACKUPKEY_dummy_module_proto(void)"
        STATIC_NDR_NTP_SIGND_MODULES=NULL
        "STATIC_NDR_NTP_SIGND_MODULES_PROTO=extern void __NDR_NTP_SIGND_dummy_module_proto(void)"
        STATIC_NDR_OXIDRESOLVER_MODULES=NULL
        "STATIC_NDR_OXIDRESOLVER_MODULES_PROTO=extern void __NDR_OXIDRESOLVER_dummy_module_proto(void)"
        STATIC_NDR_MSGSVC_MODULES=NULL
        "STATIC_NDR_MSGSVC_MODULES_PROTO=extern void __NDR_MSGSVC_dummy_module_proto(void)"
        STATIC_NDR_CAB_MODULES=NULL
        "STATIC_NDR_CAB_MODULES_PROTO=extern void __NDR_CAB_dummy_module_proto(void)"
        STATIC_NDR_BKUPBLOBS_MODULES=NULL
        "STATIC_NDR_BKUPBLOBS_MODULES_PROTO=extern void __NDR_BKUPBLOBS_dummy_module_proto(void)"
        STATIC_NDR_POLICYAGENT_MODULES=NULL
        "STATIC_NDR_POLICYAGENT_MODULES_PROTO=extern void __NDR_POLICYAGENT_dummy_module_proto(void)"
        STATIC_NDR_WZCSVC_MODULES=NULL
        "STATIC_NDR_WZCSVC_MODULES_PROTO=extern void __NDR_WZCSVC_dummy_module_proto(void)"
        STATIC_NDR_REMACT_MODULES=NULL
        "STATIC_NDR_REMACT_MODULES_PROTO=extern void __NDR_REMACT_dummy_module_proto(void)"
        STATIC_NDR_OPENDB_MODULES=NULL
        "STATIC_NDR_OPENDB_MODULES_PROTO=extern void __NDR_OPENDB_dummy_module_proto(void)"
        STATIC_NDR_WINSREPL_MODULES=NULL
        "STATIC_NDR_WINSREPL_MODULES_PROTO=extern void __NDR_WINSREPL_dummy_module_proto(void)"
        STATIC_NDR_FRSRPC_MODULES=NULL
        "STATIC_NDR_FRSRPC_MODULES_PROTO=extern void __NDR_FRSRPC_dummy_module_proto(void)"
        STATIC_NDR_LEASES_DB_MODULES=NULL
        "STATIC_NDR_LEASES_DB_MODULES_PROTO=extern void __NDR_LEASES_DB_dummy_module_proto(void)"
        STATIC_NDR_NFS4ACL_MODULES=NULL
        "STATIC_NDR_NFS4ACL_MODULES_PROTO=extern void __NDR_NFS4ACL_dummy_module_proto(void)"
        STATIC_NDR_EFS_MODULES=NULL
        "STATIC_NDR_EFS_MODULES_PROTO=extern void __NDR_EFS_dummy_module_proto(void)"
        STATIC_ndr_samba4_MODULES=NULL
        "STATIC_ndr_samba4_MODULES_PROTO=extern void __ndr_samba4_dummy_module_proto(void)"
        STATIC_NDR_SASL_HELPERS_MODULES=NULL
        "STATIC_NDR_SASL_HELPERS_MODULES_PROTO=extern void __NDR_SASL_HELPERS_dummy_module_proto(void)"
        STATIC_NDR_DCERPC_MODULES=NULL
        "STATIC_NDR_DCERPC_MODULES_PROTO=extern void __NDR_DCERPC_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
