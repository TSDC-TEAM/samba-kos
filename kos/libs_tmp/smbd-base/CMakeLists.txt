set(TARGET_NAME smbd-base)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/source3/rpc_server/rpc_ep_register.c
        ${SMB_SRC_ROOT}/source3/librpc/rpc/dcerpc_ep.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_commit.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_audit.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_shadow_copy2.c
        ${SMB_SRC_ROOT}/source3/modules/hash_inode.c
        ${SMB_SRC_ROOT}/source3/libads/ldap_printer.c
        ${SMB_SRC_ROOT}/source3/rpc_server/rpc_sock_helper.c
        ${SMB_SRC_ROOT}/source3/printing/printing.c
        ${SMB_SRC_ROOT}/source3/printing/rap_jobid.c
        ${SMB_SRC_ROOT}/source3/printing/nt_printing.c
        ${SMB_SRC_ROOT}/source3/printing/nt_printing_tdb.c
        ${SMB_SRC_ROOT}/source3/printing/nt_printing_migrate_internal.c
        ${SMB_SRC_ROOT}/source3/printing/nt_printing_ads.c
        ${SMB_SRC_ROOT}/source3/printing/queue_process.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_dirsort.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_streams_xattr.c
        ${SMB_SRC_ROOT}/source3/rpc_server/initshutdown/srv_initshutdown_nt.c
        ${SMB_SRC_ROOT}/source3/registry/regfio.c
        ${SMB_SRC_ROOT}/bin/default/source3/modules/vfs.empty.c
        ${SMB_SRC_ROOT}/source3/services/svc_spoolss.c
        ${SMB_SRC_ROOT}/source3/services/svc_rcinit.c
        ${SMB_SRC_ROOT}/source3/services/svc_winreg_glue.c
        ${SMB_SRC_ROOT}/source3/services/svc_netlogon.c
        ${SMB_SRC_ROOT}/source3/services/svc_winreg.c
        ${SMB_SRC_ROOT}/source3/services/svc_wins.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_widelinks.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_xattr_tdb.c
        ${SMB_SRC_ROOT}/source3/rpc_server/rpc_config.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_virusfilter_utils.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_media_harmony.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_full_audit.c
        ${SMB_SRC_ROOT}/source3/rpc_server/fss/srv_fss_agent.c
        ${SMB_SRC_ROOT}/source3/locking/leases_db.c
        ${SMB_SRC_ROOT}/source3/printing/pcap.c
        ${SMB_SRC_ROOT}/source3/printing/print_svid.c
        ${SMB_SRC_ROOT}/source3/printing/print_aix.c
        ${SMB_SRC_ROOT}/source3/printing/print_cups.c
        ${SMB_SRC_ROOT}/source3/printing/print_generic.c
        ${SMB_SRC_ROOT}/source3/printing/lpq_parse.c
        ${SMB_SRC_ROOT}/source3/printing/load.c
        ${SMB_SRC_ROOT}/source3/printing/print_standard.c
        ${SMB_SRC_ROOT}/source3/printing/print_iprint.c
        ${SMB_SRC_ROOT}/source3/printing/printer_list.c
        ${SMB_SRC_ROOT}/lib/afs/afs_settoken.c
        ${SMB_SRC_ROOT}/source3/printing/spoolssd.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_acl_xattr.c
        ${SMB_SRC_ROOT}/source3/registry/reg_backend_printing.c
        ${SMB_SRC_ROOT}/source3/registry/reg_backend_shares.c
        ${SMB_SRC_ROOT}/source3/registry/reg_backend_netlogon_params.c
        ${SMB_SRC_ROOT}/source3/registry/reg_backend_prod_options.c
        ${SMB_SRC_ROOT}/source3/registry/reg_backend_tcpip_params.c
        ${SMB_SRC_ROOT}/source3/registry/reg_backend_hkpt_params.c
        ${SMB_SRC_ROOT}/source3/registry/reg_backend_current_version.c
        ${SMB_SRC_ROOT}/source3/registry/reg_backend_perflib.c
        ${SMB_SRC_ROOT}/source3/registry/reg_init_full.c
        ${SMB_SRC_ROOT}/source3/registry/reg_perfcount.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_unityed_media.c
        ${SMB_SRC_ROOT}/source3/rpc_server/mdssvc/dalloc.c
        ${SMB_SRC_ROOT}/source3/rpc_server/mdssvc/marshalling.c
        ${SMB_SRC_ROOT}/source3/smbd/notifyd/notifyd_entry.c
        ${SMB_SRC_ROOT}/source3/smbd/notifyd/notifyd_db.c
        ${SMB_SRC_ROOT}/source3/printing/notify.c
        ${SMB_SRC_ROOT}/source3/printing/printing_db.c
        ${SMB_SRC_ROOT}/source3/smbd/notifyd/notifyd.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_recycle.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_streams_depot.c
        ${SMB_SRC_ROOT}/source3/rpc_server/ntsvcs/srv_ntsvcs_nt.c
        ${SMB_SRC_ROOT}/source3/smbd/fd_handle.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_fake_perms.c
        ${SMB_SRC_ROOT}/source3/modules/offload_token.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_virusfilter.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_virusfilter_sophos.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_virusfilter_fsav.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_virusfilter_clamav.c
        ${SMB_SRC_ROOT}/source3/registry/reg_parse_prs.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_fruit.c
        ${SMB_SRC_ROOT}/source3/lib/eventlog/eventlog.c
        ${SMB_SRC_ROOT}/source3/rpc_server/epmapper/srv_epmapper.c
        ${SMB_SRC_ROOT}/source3/rpc_server/srvsvc/srv_srvsvc_nt.c
        ${SMB_SRC_ROOT}/source3/smbd/server_reload.c
        ${SMB_SRC_ROOT}/source3/smbd/files.c
        ${SMB_SRC_ROOT}/source3/smbd/connection.c
        ${SMB_SRC_ROOT}/source3/smbd/utmp.c
        ${SMB_SRC_ROOT}/source3/smbd/session.c
        ${SMB_SRC_ROOT}/source3/smbd/dfree.c
        ${SMB_SRC_ROOT}/source3/smbd/dir.c
        ${SMB_SRC_ROOT}/source3/smbd/password.c
        ${SMB_SRC_ROOT}/source3/smbd/conn_msg.c
        ${SMB_SRC_ROOT}/source3/smbd/conn_idle.c
        ${SMB_SRC_ROOT}/source3/smbd/share_access.c
        ${SMB_SRC_ROOT}/source3/smbd/fileio.c
        ${SMB_SRC_ROOT}/source3/smbd/ipc.c
        ${SMB_SRC_ROOT}/source3/smbd/lanman.c
        ${SMB_SRC_ROOT}/source3/smbd/negprot.c
        ${SMB_SRC_ROOT}/source3/smbd/message.c
        ${SMB_SRC_ROOT}/source3/smbd/nttrans.c
        ${SMB_SRC_ROOT}/source3/smbd/pipes.c
        ${SMB_SRC_ROOT}/source3/smbd/reply.c
        ${SMB_SRC_ROOT}/source3/smbd/sesssetup.c
        ${SMB_SRC_ROOT}/source3/smbd/trans2.c
        ${SMB_SRC_ROOT}/source3/smbd/uid.c
        ${SMB_SRC_ROOT}/source3/smbd/dosmode.c
        ${SMB_SRC_ROOT}/source3/smbd/filename.c
        ${SMB_SRC_ROOT}/source3/smbd/open.c
        ${SMB_SRC_ROOT}/source3/smbd/close.c
        ${SMB_SRC_ROOT}/source3/smbd/blocking.c
        ${SMB_SRC_ROOT}/source3/smbd/sec_ctx.c
        ${SMB_SRC_ROOT}/source3/smbd/srvstr.c
        ${SMB_SRC_ROOT}/source3/smbd/vfs.c
        ${SMB_SRC_ROOT}/source3/smbd/perfcount.c
        ${SMB_SRC_ROOT}/source3/smbd/statcache.c
        ${SMB_SRC_ROOT}/source3/smbd/seal.c
        ${SMB_SRC_ROOT}/source3/smbd/posix_acls.c
        ${SMB_SRC_ROOT}/source3/lib/sysacls.c
        ${SMB_SRC_ROOT}/source3/smbd/process.c
        ${SMB_SRC_ROOT}/source3/smbd/service.c
        ${SMB_SRC_ROOT}/source3/smbd/error.c
        ${SMB_SRC_ROOT}/source3/printing/printspoolss.c
        ${SMB_SRC_ROOT}/source3/lib/sessionid_tdb.c
        ${SMB_SRC_ROOT}/source3/lib/cleanupdb.c
        ${SMB_SRC_ROOT}/source3/smbd/fake_file.c
        ${SMB_SRC_ROOT}/source3/smbd/quotas.c
        ${SMB_SRC_ROOT}/source3/smbd/ntquotas.c
        ${SMB_SRC_ROOT}/source3/smbd/msdfs.c
        ${SMB_SRC_ROOT}/source3/smbd/aio.c
        ${SMB_SRC_ROOT}/source3/smbd/statvfs.c
        ${SMB_SRC_ROOT}/source3/smbd/dmapi.c
        ${SMB_SRC_ROOT}/source3/smbd/signing.c
        ${SMB_SRC_ROOT}/source3/smbd/file_access.c
        ${SMB_SRC_ROOT}/source3/smbd/dnsregister.c
        ${SMB_SRC_ROOT}/source3/smbd/globals.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_server.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_glue.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_negprot.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_sesssetup.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_tcon.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_create.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_close.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_flush.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_read.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_write.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_lock.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_ioctl.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_ioctl_dfs.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_ioctl_filesys.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_ioctl_named_pipe.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_ioctl_network_fs.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_ioctl_smbtorture.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_keepalive.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_query_directory.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_notify.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_getinfo.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_setinfo.c
        ${SMB_SRC_ROOT}/source3/smbd/smb2_break.c
        ${SMB_SRC_ROOT}/source3/smbd/smbXsrv_version.c
        ${SMB_SRC_ROOT}/source3/smbd/smbXsrv_client.c
        ${SMB_SRC_ROOT}/source3/smbd/smbXsrv_session.c
        ${SMB_SRC_ROOT}/source3/smbd/smbXsrv_tcon.c
        ${SMB_SRC_ROOT}/source3/smbd/smbXsrv_open.c
        ${SMB_SRC_ROOT}/source3/smbd/server_exit.c
        ${SMB_SRC_ROOT}/source3/smbd/durable.c
        ${SMB_SRC_ROOT}/source3/smbd/scavenger.c
        ${SMB_SRC_ROOT}/source3/smbd/mangle.c
        ${SMB_SRC_ROOT}/source3/smbd/mangle_hash.c
        ${SMB_SRC_ROOT}/source3/smbd/mangle_hash2.c
        ${SMB_SRC_ROOT}/source3/smbd/oplock.c
        ${SMB_SRC_ROOT}/source3/smbd/oplock_linux.c
        ${SMB_SRC_ROOT}/source3/smbd/notify.c
        ${SMB_SRC_ROOT}/source3/smbd/notify_msg.c
        ${SMB_SRC_ROOT}/bin/default/source3/smbd/build_options.c
        ${SMB_SRC_ROOT}/source3/smbd/smb1_utils.c
        ${SMB_SRC_ROOT}/source3/smbd/conn.c
        ${SMB_SRC_ROOT}/source3/modules/util_reparse.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_preopen.c
        ${SMB_SRC_ROOT}/source3/rpc_server/rpc_modules.c
        ${SMB_SRC_ROOT}/source3/rpc_server/echo/srv_echo_nt.c
        ${SMB_SRC_ROOT}/source3/param/service.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_shell_snap.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_not_implemented.c
        ${SMB_SRC_ROOT}/source3/rpc_server/spoolss/srv_iremotewinspool_nt.c
        ${SMB_SRC_ROOT}/source3/rpc_server/spoolss/srv_iremotewinspool.c
        ${SMB_SRC_ROOT}/source3/lib/adouble.c
        ${SMB_SRC_ROOT}/source3/rpc_server/rpc_ncacn_np.c
        ${SMB_SRC_ROOT}/source3/rpc_server/rpc_handles.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_time_audit.c
        ${SMB_SRC_ROOT}/source3/profile/profile_dummy.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_cap.c
        ${SMB_SRC_ROOT}/source3/locking/locking.c
        ${SMB_SRC_ROOT}/source3/locking/brlock.c
        ${SMB_SRC_ROOT}/source3/locking/posix.c
        ${SMB_SRC_ROOT}/source3/locking/share_mode_lock.c
        ${SMB_SRC_ROOT}/source3/rpc_server/wkssvc/srv_wkssvc_nt.c
        ${SMB_SRC_ROOT}/source3/lib/filename_util.c
        ${SMB_SRC_ROOT}/source3/rpc_server/svcctl/srv_svcctl_nt.c
        ${SMB_SRC_ROOT}/source3/rpc_server/svcctl/srv_svcctl_reg.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_expand_msdfs.c
        ${SMB_SRC_ROOT}/source3/rpc_server/netlogon/srv_netlog_nt.c
        ${SMB_SRC_ROOT}/source3/rpc_server/mdssvc/mdssvc.c
        ${SMB_SRC_ROOT}/source3/rpc_server/mdssvc/mdssvc_noindex.c
        ${SMB_SRC_ROOT}/source3/rpc_server/mdssvc/srv_mdssvc_nt.c
        ${SMB_SRC_ROOT}/source3/rpc_server/srv_access_check.c
        ${SMB_SRC_ROOT}/source3/rpc_client/cli_winreg_int.c
        ${SMB_SRC_ROOT}/source3/rpc_server/rpc_service_setup.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_acl_tdb.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_linux_xfs_sgid.c
        ${SMB_SRC_ROOT}/source3/rpc_server/eventlog/srv_eventlog_nt.c
        ${SMB_SRC_ROOT}/source3/rpc_server/eventlog/srv_eventlog_reg.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_default_quota.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_shadow_copy.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_worm.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_syncops.c
        ${SMB_SRC_ROOT}/source3/rpc_server/winreg/srv_winreg_nt.c
        ${SMB_SRC_ROOT}/librpc/rpc/dcerpc_helper.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_catia.c
        ${SMB_SRC_ROOT}/source3/rpc_server/rpc_server.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_readahead.c
        ${SMB_SRC_ROOT}/source3/rpc_server/fss/srv_fss_state.c
        ${SMB_SRC_ROOT}/source3/rpc_server/samr/srv_samr_nt.c
        ${SMB_SRC_ROOT}/source3/rpc_server/samr/srv_samr_util.c
        ${SMB_SRC_ROOT}/source3/rpc_server/samr/srv_samr_chgpasswd.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_readonly.c
        ${SMB_SRC_ROOT}/source3/modules/getdate.c
        ${SMB_SRC_ROOT}/source3/rpc_server/lsa/srv_lsa_nt.c
        ${SMB_SRC_ROOT}/bin/default/source3/rpc_server/rpc.empty.c
        ${SMB_SRC_ROOT}/source3/rpc_server/dfs/srv_dfs_nt.c
        ${SMB_SRC_ROOT}/source3/lib/sysquotas.c
        ${SMB_SRC_ROOT}/source3/lib/sysquotas_linux.c
        ${SMB_SRC_ROOT}/source3/lib/sysquotas_xfs.c
        ${SMB_SRC_ROOT}/source3/lib/sysquotas_4A.c
        ${SMB_SRC_ROOT}/source3/lib/sysquotas_4B.c
        ${SMB_SRC_ROOT}/source3/lib/sysquotas_jfs2.c
        ${SMB_SRC_ROOT}/source3/lib/sysquotas_nfs.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_acl_common.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_aio_fork.c
        ${SMB_SRC_ROOT}/source3/rpc_server/dssetup/srv_dssetup_nt.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_aio_pthread.c
        ${SMB_SRC_ROOT}/source3/lib/string_replace.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_offline.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_extd_audit.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_default.c
        ${SMB_SRC_ROOT}/source3/lib/lsa.c
        ${SMB_SRC_ROOT}/source3/locking/leases_util.c
        ${SMB_SRC_ROOT}/source3/libads/authdata.c
        ${SMB_SRC_ROOT}/source3/rpc_server/srv_pipe_hnd.c
        ${SMB_SRC_ROOT}/source3/rpc_server/srv_pipe.c
        ${SMB_SRC_ROOT}/lib/afs/afs_funcs.c
        ${SMB_SRC_ROOT}/source3/modules/vfs_crossrename.c
        ${SMB_SRC_ROOT}/source3/rpc_server/spoolss/srv_spoolss_nt.c
        ${SMB_SRC_ROOT}/source3/rpc_server/spoolss/srv_spoolss_util.c
        )

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/source3/rpc_server
        ${SMB_SRC_ROOT}/bin/default/source3/rpc_server
        ${SMB_SRC_ROOT}/source3
        ${SMB_SRC_ROOT}/bin/default/source3
        ${SMB_SRC_ROOT}/source3/include
        ${SMB_SRC_ROOT}/bin/default/source3/include
        ${SMB_SRC_ROOT}/source3/lib
        ${SMB_SRC_ROOT}/bin/default/source3/lib
        ${SMB_SRC_ROOT}/source3/passdb
        ${SMB_SRC_ROOT}/bin/default/source3/passdb
        ${SMB_SRC_ROOT}/source3/modules
        ${SMB_SRC_ROOT}/bin/default/source3/modules
        ${SMB_SRC_ROOT}/source3/librpc
        ${SMB_SRC_ROOT}/bin/default/source3/librpc
        ${SMB_SRC_ROOT}/source3/param
        ${SMB_SRC_ROOT}/bin/default/source3/param
        ${SMB_SRC_ROOT}/source3/auth
        ${SMB_SRC_ROOT}/bin/default/source3/auth
        ${SMB_SRC_ROOT}/source3/smbd/notifyd
        ${SMB_SRC_ROOT}/bin/default/source3/smbd/notifyd
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
        ${SMB_SRC_ROOT}/lib/util/charset
        ${SMB_SRC_ROOT}/bin/default/lib/util/charset
        ${SMB_SRC_ROOT}/lib/util/home/user/samba-of-pred-kos-2/third_party/gpfs
        ${SMB_SRC_ROOT}/bin/default/lib/util/home/user/samba-of-pred-kos-2/third_party/gpfs
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        /usr/include/p11-kit-1
        ${SMB_SRC_ROOT}/lib/tdb
        ${SMB_SRC_ROOT}/bin/default/lib/tdb
        ${SMB_SRC_ROOT}/source4/heimdal_build
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build
        ${SMB_SRC_ROOT}/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/source4/heimdal/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/include
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/source4/heimdal/base
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/base
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/source4/heimdal/lib
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/spnego
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/spnego
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/krb5
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/krb5
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/mech
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/mech
        ${SMB_SRC_ROOT}/lib/krb5_wrap
        ${SMB_SRC_ROOT}/bin/default/lib/krb5_wrap
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/librpc
        ${SMB_SRC_ROOT}/bin/default/librpc
        ${SMB_SRC_ROOT}/libcli/auth
        ${SMB_SRC_ROOT}/bin/default/libcli/auth
        ${SMB_SRC_ROOT}/libcli/lsarpc
        ${SMB_SRC_ROOT}/bin/default/libcli/lsarpc
        ${SMB_SRC_ROOT}/source4/lib/socket
        ${SMB_SRC_ROOT}/bin/default/source4/lib/socket
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
        ${SMB_SRC_ROOT}/source4/lib/messaging
        ${SMB_SRC_ROOT}/bin/default/source4/lib/messaging
        ${SMB_SRC_ROOT}/source4/dsdb
        ${SMB_SRC_ROOT}/bin/default/source4/dsdb
        ${SMB_SRC_ROOT}/libds/common
        ${SMB_SRC_ROOT}/bin/default/libds/common
        ${SMB_SRC_ROOT}/source4/lib/tls
        ${SMB_SRC_ROOT}/bin/default/source4/lib/tls
        ${SMB_SRC_ROOT}/auth/gensec
        ${SMB_SRC_ROOT}/bin/default/auth/gensec
        ${SMB_SRC_ROOT}/auth/credentials
        ${SMB_SRC_ROOT}/bin/default/auth/credentials
        ${SMB_SRC_ROOT}/lib/param
        ${SMB_SRC_ROOT}/bin/default/lib/param
        ${SMB_SRC_ROOT}/source4/libcli
        ${SMB_SRC_ROOT}/bin/default/source4/libcli
        ${SMB_SRC_ROOT}/nsswitch/libwbclient
        ${SMB_SRC_ROOT}/bin/default/nsswitch/libwbclient
        ${SMB_SRC_ROOT}/source4/lib/events
        ${SMB_SRC_ROOT}/bin/default/source4/lib/events
        ${SMB_SRC_ROOT}/libcli/ldap
        ${SMB_SRC_ROOT}/bin/default/libcli/ldap
        ${SMB_SRC_ROOT}/source4/auth/kerberos
        ${SMB_SRC_ROOT}/bin/default/source4/auth/kerberos
        ${SMB_SRC_ROOT}/lib/smbconf
        ${SMB_SRC_ROOT}/bin/default/lib/smbconf
        ${SMB_SRC_ROOT}/lib/ldb/include
        ${SMB_SRC_ROOT}/bin/default/lib/ldb/include
        ${SMB_SRC_ROOT}/lib/ldb
        ${SMB_SRC_ROOT}/bin/default/lib/ldb
        ${SMB_SRC_ROOT}/auth
        ${SMB_SRC_ROOT}/bin/default/auth
        ${SMB_SRC_ROOT}/lib/messaging
        ${SMB_SRC_ROOT}/bin/default/lib/messaging
        ${SMB_SRC_ROOT}/auth/kerberos
        ${SMB_SRC_ROOT}/bin/default/auth/kerberos
        ${SMB_SRC_ROOT}/lib/ldb-samba
        ${SMB_SRC_ROOT}/bin/default/lib/ldb-samba
        ${SMB_SRC_ROOT}/source4/auth/gensec
        ${SMB_SRC_ROOT}/bin/default/source4/auth/gensec
        ${SMB_SRC_ROOT}/source4/param
        ${SMB_SRC_ROOT}/bin/default/source4/param
        ${SMB_SRC_ROOT}/lib/tsocket
        ${SMB_SRC_ROOT}/bin/default/lib/tsocket
        ${SMB_SRC_ROOT}/libcli/http
        ${SMB_SRC_ROOT}/bin/default/libcli/http
        ${SMB_SRC_ROOT}/lib/audit_logging
        ${SMB_SRC_ROOT}/bin/default/lib/audit_logging
        ${SMB_SRC_ROOT}/lib/async_req
        ${SMB_SRC_ROOT}/bin/default/lib/async_req
        ${SMB_SRC_ROOT}/libcli/registry
        ${SMB_SRC_ROOT}/bin/default/libcli/registry
        ${SMB_SRC_ROOT}/lib/dbwrap
        ${SMB_SRC_ROOT}/bin/default/lib/dbwrap
        ${SMB_SRC_ROOT}/libcli/security
        ${SMB_SRC_ROOT}/bin/default/libcli/security
        ${SMB_SRC_ROOT}/lib/pthreadpool
        ${SMB_SRC_ROOT}/bin/default/lib/pthreadpool
        ${SMB_SRC_ROOT}/nsswitch
        ${SMB_SRC_ROOT}/bin/default/nsswitch
        ${SMB_SRC_ROOT}/libcli/drsuapi
        ${SMB_SRC_ROOT}/bin/default/libcli/drsuapi
        ${SMB_SRC_ROOT}/lib/socket
        ${SMB_SRC_ROOT}/bin/default/lib/socket
        ${SMB_SRC_ROOT}/auth/ntlmssp
        ${SMB_SRC_ROOT}/bin/default/auth/ntlmssp
        ${SMB_SRC_ROOT}/source4/auth
        ${SMB_SRC_ROOT}/bin/default/source4/auth
        ${SMB_SRC_ROOT}/source4/cluster
        ${SMB_SRC_ROOT}/bin/default/source4/cluster
        ${SMB_SRC_ROOT}/source4/lib/stream
        ${SMB_SRC_ROOT}/bin/default/source4/lib/stream
        ${SMB_SRC_ROOT}/libcli/nbt
        ${SMB_SRC_ROOT}/bin/default/libcli/nbt
        ${SMB_SRC_ROOT}/lib/compression
        ${SMB_SRC_ROOT}/bin/default/lib/compression
        ${SMB_SRC_ROOT}/source4/librpc
        ${SMB_SRC_ROOT}/bin/default/source4/librpc
        ${SMB_SRC_ROOT}/libcli/dns
        ${SMB_SRC_ROOT}/bin/default/libcli/dns
        ${SMB_SRC_ROOT}/libcli/smb
        ${SMB_SRC_ROOT}/bin/default/libcli/smb
        ${SMB_SRC_ROOT}/lib/afs
        ${SMB_SRC_ROOT}/bin/default/lib/afs
        ${SMB_SRC_ROOT}/source4/libcli/smb2
        ${SMB_SRC_ROOT}/bin/default/source4/libcli/smb2
        ${SMB_SRC_ROOT}/source4/libcli/ldap
        ${SMB_SRC_ROOT}/bin/default/source4/libcli/ldap
        ${SMB_SRC_ROOT}/libcli/named_pipe_auth
        ${SMB_SRC_ROOT}/bin/default/libcli/named_pipe_auth
        ${SMB_SRC_ROOT}/libcli/cldap
        ${SMB_SRC_ROOT}/bin/default/libcli/cldap
        ${SMB_SRC_ROOT}/lib/addns
        ${SMB_SRC_ROOT}/bin/default/lib/addns
        ${SMB_SRC_ROOT}/libcli/netlogon
        ${SMB_SRC_ROOT}/bin/default/libcli/netlogon
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
        STATIC_RPC_SERVER_REGISTER_MODULES=NULL
        "STATIC_RPC_SERVER_REGISTER_MODULES_PROTO=extern void __RPC_SERVER_REGISTER_dummy_module_proto(void)"
        STATIC_vfs_commit_MODULES=NULL
        "STATIC_vfs_commit_MODULES_PROTO=extern void __vfs_commit_dummy_module_proto(void)"
        STATIC_vfs_audit_MODULES=NULL
        "STATIC_vfs_audit_MODULES_PROTO=extern void __vfs_audit_dummy_module_proto(void)"
        STATIC_vfs_shadow_copy2_MODULES=NULL
        "STATIC_vfs_shadow_copy2_MODULES_PROTO=extern void __vfs_shadow_copy2_dummy_module_proto(void)"
        STATIC_HASH_INODE_MODULES=NULL
        "STATIC_HASH_INODE_MODULES_PROTO=extern void __HASH_INODE_dummy_module_proto(void)"
        STATIC_LIBADS_PRINTER_MODULES=NULL
        "STATIC_LIBADS_PRINTER_MODULES_PROTO=extern void __LIBADS_PRINTER_dummy_module_proto(void)"
        STATIC_RPC_SOCK_HELPER_MODULES=NULL
        "STATIC_RPC_SOCK_HELPER_MODULES_PROTO=extern void __RPC_SOCK_HELPER_dummy_module_proto(void)"
        STATIC_PRINTBACKEND_MODULES=NULL
        "STATIC_PRINTBACKEND_MODULES_PROTO=extern void __PRINTBACKEND_dummy_module_proto(void)"
        STATIC_vfs_dirsort_MODULES=NULL
        "STATIC_vfs_dirsort_MODULES_PROTO=extern void __vfs_dirsort_dummy_module_proto(void)"
        STATIC_vfs_streams_xattr_MODULES=NULL
        "STATIC_vfs_streams_xattr_MODULES_PROTO=extern void __vfs_streams_xattr_dummy_module_proto(void)"
        STATIC_RPC_INITSHUTDOWN_MODULES=NULL
        "STATIC_RPC_INITSHUTDOWN_MODULES_PROTO=extern void __RPC_INITSHUTDOWN_dummy_module_proto(void)"
        STATIC_REGFIO_MODULES=NULL
        "STATIC_REGFIO_MODULES_PROTO=extern void __REGFIO_dummy_module_proto(void)"
        STATIC_vfs_MODULES=,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,NULL
        "STATIC_vfs_MODULES_PROTO=_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()_MODULE_PROTO()extern void __vfs_dummy_module_proto(void)"
        STATIC_SERVICES_MODULES=NULL
        "STATIC_SERVICES_MODULES_PROTO=extern void __SERVICES_dummy_module_proto(void)"
        STATIC_vfs_widelinks_MODULES=NULL
        "STATIC_vfs_widelinks_MODULES_PROTO=extern void __vfs_widelinks_dummy_module_proto(void)"
        STATIC_vfs_xattr_tdb_MODULES=NULL
        "STATIC_vfs_xattr_tdb_MODULES_PROTO=extern void __vfs_xattr_tdb_dummy_module_proto(void)"
        STATIC_RPC_CONFIG_MODULES=NULL
        "STATIC_RPC_CONFIG_MODULES_PROTO=extern void __RPC_CONFIG_dummy_module_proto(void)"
        STATIC_VFS_VIRUSFILTER_UTILS_MODULES=NULL
        "STATIC_VFS_VIRUSFILTER_UTILS_MODULES_PROTO=extern void __VFS_VIRUSFILTER_UTILS_dummy_module_proto(void)"
        STATIC_vfs_media_harmony_MODULES=NULL
        "STATIC_vfs_media_harmony_MODULES_PROTO=extern void __vfs_media_harmony_dummy_module_proto(void)"
        STATIC_vfs_full_audit_MODULES=NULL
        "STATIC_vfs_full_audit_MODULES_PROTO=extern void __vfs_full_audit_dummy_module_proto(void)"
        STATIC_RPC_FSS_AGENT_MODULES=NULL
        "STATIC_RPC_FSS_AGENT_MODULES_PROTO=extern void __RPC_FSS_AGENT_dummy_module_proto(void)"
        STATIC_LEASES_DB_MODULES=NULL
        "STATIC_LEASES_DB_MODULES_PROTO=extern void __LEASES_DB_dummy_module_proto(void)"
        STATIC_PRINTING_MODULES=NULL
        "STATIC_PRINTING_MODULES_PROTO=extern void __PRINTING_dummy_module_proto(void)"
        STATIC_LIBAFS_SETTOKEN_MODULES=NULL
        "STATIC_LIBAFS_SETTOKEN_MODULES_PROTO=extern void __LIBAFS_SETTOKEN_dummy_module_proto(void)"
        STATIC_SPOOLSSD_MODULES=NULL
        "STATIC_SPOOLSSD_MODULES_PROTO=extern void __SPOOLSSD_dummy_module_proto(void)"
        STATIC_vfs_acl_xattr_MODULES=NULL
        "STATIC_vfs_acl_xattr_MODULES_PROTO=extern void __vfs_acl_xattr_dummy_module_proto(void)"
        STATIC_REG_FULL_MODULES=NULL
        "STATIC_REG_FULL_MODULES_PROTO=extern void __REG_FULL_dummy_module_proto(void)"
        STATIC_vfs_unityed_media_MODULES=NULL
        "STATIC_vfs_unityed_media_MODULES_PROTO=extern void __vfs_unityed_media_dummy_module_proto(void)"
        STATIC_mdssvc_MODULES=NULL
        "STATIC_mdssvc_MODULES_PROTO=extern void __mdssvc_dummy_module_proto(void)"
        STATIC_notifyd_db_MODULES=NULL
        "STATIC_notifyd_db_MODULES_PROTO=extern void __notifyd_db_dummy_module_proto(void)"
        STATIC_PRINTBASE_MODULES=NULL
        "STATIC_PRINTBASE_MODULES_PROTO=extern void __PRINTBASE_dummy_module_proto(void)"
        STATIC_notifyd_MODULES=NULL
        "STATIC_notifyd_MODULES_PROTO=extern void __notifyd_dummy_module_proto(void)"
        STATIC_vfs_recycle_MODULES=NULL
        "STATIC_vfs_recycle_MODULES_PROTO=extern void __vfs_recycle_dummy_module_proto(void)"
        STATIC_vfs_streams_depot_MODULES=NULL
        "STATIC_vfs_streams_depot_MODULES_PROTO=extern void __vfs_streams_depot_dummy_module_proto(void)"
        STATIC_RPC_NTSVCS_MODULES=NULL
        "STATIC_RPC_NTSVCS_MODULES_PROTO=extern void __RPC_NTSVCS_dummy_module_proto(void)"
        STATIC_fd_handle_MODULES=NULL
        "STATIC_fd_handle_MODULES_PROTO=extern void __fd_handle_dummy_module_proto(void)"
        STATIC_vfs_fake_perms_MODULES=NULL
        "STATIC_vfs_fake_perms_MODULES_PROTO=extern void __vfs_fake_perms_dummy_module_proto(void)"
        STATIC_OFFLOAD_TOKEN_MODULES=NULL
        "STATIC_OFFLOAD_TOKEN_MODULES_PROTO=extern void __OFFLOAD_TOKEN_dummy_module_proto(void)"
        STATIC_vfs_virusfilter_MODULES=NULL
        "STATIC_vfs_virusfilter_MODULES_PROTO=extern void __vfs_virusfilter_dummy_module_proto(void)"
        STATIC_REG_PARSE_PRS_MODULES=NULL
        "STATIC_REG_PARSE_PRS_MODULES_PROTO=extern void __REG_PARSE_PRS_dummy_module_proto(void)"
        STATIC_vfs_fruit_MODULES=NULL
        "STATIC_vfs_fruit_MODULES_PROTO=extern void __vfs_fruit_dummy_module_proto(void)"
        STATIC_LIBEVENTLOG_MODULES=NULL
        "STATIC_LIBEVENTLOG_MODULES_PROTO=extern void __LIBEVENTLOG_dummy_module_proto(void)"
        STATIC_RPC_EPMAPPER_MODULES=NULL
        "STATIC_RPC_EPMAPPER_MODULES_PROTO=extern void __RPC_EPMAPPER_dummy_module_proto(void)"
        STATIC_RPC_SRVSVC_MODULES=NULL
        "STATIC_RPC_SRVSVC_MODULES_PROTO=extern void __RPC_SRVSVC_dummy_module_proto(void)"
        STATIC_smbd_base_MODULES=NULL
        "STATIC_smbd_base_MODULES_PROTO=extern void __smbd_base_dummy_module_proto(void)"
        STATIC_UTIL_REPARSE_MODULES=NULL
        "STATIC_UTIL_REPARSE_MODULES_PROTO=extern void __UTIL_REPARSE_dummy_module_proto(void)"
        STATIC_vfs_preopen_MODULES=NULL
        "STATIC_vfs_preopen_MODULES_PROTO=extern void __vfs_preopen_dummy_module_proto(void)"
        STATIC_RPC_MODULES_MODULES=NULL
        "STATIC_RPC_MODULES_MODULES_PROTO=extern void __RPC_MODULES_dummy_module_proto(void)"
        STATIC_RPC_RPCECHO_MODULES=NULL
        "STATIC_RPC_RPCECHO_MODULES_PROTO=extern void __RPC_RPCECHO_dummy_module_proto(void)"
        STATIC_param_service_MODULES=NULL
        "STATIC_param_service_MODULES_PROTO=extern void __param_service_dummy_module_proto(void)"
        STATIC_vfs_shell_snap_MODULES=NULL
        "STATIC_vfs_shell_snap_MODULES_PROTO=extern void __vfs_shell_snap_dummy_module_proto(void)"
        STATIC_vfs_not_implemented_MODULES=NULL
        "STATIC_vfs_not_implemented_MODULES_PROTO=extern void __vfs_not_implemented_dummy_module_proto(void)"
        STATIC_RPC_IREMOTEWINSPOOL_MODULES=NULL
        "STATIC_RPC_IREMOTEWINSPOOL_MODULES_PROTO=extern void __RPC_IREMOTEWINSPOOL_dummy_module_proto(void)"
        STATIC_ADOUBLE_MODULES=NULL
        "STATIC_ADOUBLE_MODULES_PROTO=extern void __ADOUBLE_dummy_module_proto(void)"
        STATIC_RPC_NCACN_NP_MODULES=NULL
        "STATIC_RPC_NCACN_NP_MODULES_PROTO=extern void __RPC_NCACN_NP_dummy_module_proto(void)"
        STATIC_vfs_time_audit_MODULES=NULL
        "STATIC_vfs_time_audit_MODULES_PROTO=extern void __vfs_time_audit_dummy_module_proto(void)"
        STATIC_PROFILE_MODULES=NULL
        "STATIC_PROFILE_MODULES_PROTO=extern void __PROFILE_dummy_module_proto(void)"
        STATIC_vfs_cap_MODULES=NULL
        "STATIC_vfs_cap_MODULES_PROTO=extern void __vfs_cap_dummy_module_proto(void)"
        STATIC_LOCKING_MODULES=NULL
        "STATIC_LOCKING_MODULES_PROTO=extern void __LOCKING_dummy_module_proto(void)"
        STATIC_RPC_WKSSVC_MODULES=NULL
        "STATIC_RPC_WKSSVC_MODULES_PROTO=extern void __RPC_WKSSVC_dummy_module_proto(void)"
        STATIC_FNAME_UTIL_MODULES=NULL
        "STATIC_FNAME_UTIL_MODULES_PROTO=extern void __FNAME_UTIL_dummy_module_proto(void)"
        STATIC_RPC_SVCCTL_MODULES=NULL
        "STATIC_RPC_SVCCTL_MODULES_PROTO=extern void __RPC_SVCCTL_dummy_module_proto(void)"
        STATIC_vfs_expand_msdfs_MODULES=NULL
        "STATIC_vfs_expand_msdfs_MODULES_PROTO=extern void __vfs_expand_msdfs_dummy_module_proto(void)"
        STATIC_RPC_NETLOGON_MODULES=NULL
        "STATIC_RPC_NETLOGON_MODULES_PROTO=extern void __RPC_NETLOGON_dummy_module_proto(void)"
        STATIC_rpc_mdssvc_module_MODULES=NULL
        "STATIC_rpc_mdssvc_module_MODULES_PROTO=extern void __rpc_mdssvc_module_dummy_module_proto(void)"
        STATIC_SRV_ACCESS_CHECK_MODULES=NULL
        "STATIC_SRV_ACCESS_CHECK_MODULES_PROTO=extern void __SRV_ACCESS_CHECK_dummy_module_proto(void)"
        STATIC_LIBCLI_WINREG_INTERNAL_MODULES=NULL
        "STATIC_LIBCLI_WINREG_INTERNAL_MODULES_PROTO=extern void __LIBCLI_WINREG_INTERNAL_dummy_module_proto(void)"
        STATIC_RPC_SERVICE_MODULES=NULL
        "STATIC_RPC_SERVICE_MODULES_PROTO=extern void __RPC_SERVICE_dummy_module_proto(void)"
        STATIC_vfs_acl_tdb_MODULES=NULL
        "STATIC_vfs_acl_tdb_MODULES_PROTO=extern void __vfs_acl_tdb_dummy_module_proto(void)"
        STATIC_vfs_linux_xfs_sgid_MODULES=NULL
        "STATIC_vfs_linux_xfs_sgid_MODULES_PROTO=extern void __vfs_linux_xfs_sgid_dummy_module_proto(void)"
        STATIC_RPC_EVENTLOG_MODULES=NULL
        "STATIC_RPC_EVENTLOG_MODULES_PROTO=extern void __RPC_EVENTLOG_dummy_module_proto(void)"
        STATIC_vfs_default_quota_MODULES=NULL
        "STATIC_vfs_default_quota_MODULES_PROTO=extern void __vfs_default_quota_dummy_module_proto(void)"
        STATIC_vfs_shadow_copy_MODULES=NULL
        "STATIC_vfs_shadow_copy_MODULES_PROTO=extern void __vfs_shadow_copy_dummy_module_proto(void)"
        STATIC_vfs_worm_MODULES=NULL
        "STATIC_vfs_worm_MODULES_PROTO=extern void __vfs_worm_dummy_module_proto(void)"
        STATIC_vfs_syncops_MODULES=NULL
        "STATIC_vfs_syncops_MODULES_PROTO=extern void __vfs_syncops_dummy_module_proto(void)"
        STATIC_RPC_WINREG_MODULES=NULL
        "STATIC_RPC_WINREG_MODULES_PROTO=extern void __RPC_WINREG_dummy_module_proto(void)"
        STATIC_DCERPC_HELPER_MODULES=NULL
        "STATIC_DCERPC_HELPER_MODULES_PROTO=extern void __DCERPC_HELPER_dummy_module_proto(void)"
        STATIC_vfs_catia_MODULES=NULL
        "STATIC_vfs_catia_MODULES_PROTO=extern void __vfs_catia_dummy_module_proto(void)"
        STATIC_RPC_SERVER_LOOP_MODULES=NULL
        "STATIC_RPC_SERVER_LOOP_MODULES_PROTO=extern void __RPC_SERVER_LOOP_dummy_module_proto(void)"
        STATIC_vfs_readahead_MODULES=NULL
        "STATIC_vfs_readahead_MODULES_PROTO=extern void __vfs_readahead_dummy_module_proto(void)"
        STATIC_RPC_FSS_STATE_MODULES=NULL
        "STATIC_RPC_FSS_STATE_MODULES_PROTO=extern void __RPC_FSS_STATE_dummy_module_proto(void)"
        STATIC_RPC_SAMR_MODULES=NULL
        "STATIC_RPC_SAMR_MODULES_PROTO=extern void __RPC_SAMR_dummy_module_proto(void)"
        STATIC_vfs_readonly_MODULES=NULL
        "STATIC_vfs_readonly_MODULES_PROTO=extern void __vfs_readonly_dummy_module_proto(void)"
        STATIC_RPC_LSARPC_MODULES=NULL
        "STATIC_RPC_LSARPC_MODULES_PROTO=extern void __RPC_LSARPC_dummy_module_proto(void)"
        STATIC_rpc_MODULES=,NULL
        "STATIC_rpc_MODULES_PROTO=_MODULE_PROTO()extern void __rpc_dummy_module_proto(void)"
        STATIC_RPC_NETDFS_MODULES=NULL
        "STATIC_RPC_NETDFS_MODULES_PROTO=extern void __RPC_NETDFS_dummy_module_proto(void)"
        STATIC_sysquotas_MODULES=NULL
        "STATIC_sysquotas_MODULES_PROTO=extern void __sysquotas_dummy_module_proto(void)"
        STATIC_vfs_acl_common_MODULES=NULL
        "STATIC_vfs_acl_common_MODULES_PROTO=extern void __vfs_acl_common_dummy_module_proto(void)"
        STATIC_vfs_aio_fork_MODULES=NULL
        "STATIC_vfs_aio_fork_MODULES_PROTO=extern void __vfs_aio_fork_dummy_module_proto(void)"
        STATIC_RPC_DSSETUP_MODULES=NULL
        "STATIC_RPC_DSSETUP_MODULES_PROTO=extern void __RPC_DSSETUP_dummy_module_proto(void)"
        STATIC_vfs_aio_pthread_MODULES=NULL
        "STATIC_vfs_aio_pthread_MODULES_PROTO=extern void __vfs_aio_pthread_dummy_module_proto(void)"
        STATIC_STRING_REPLACE_MODULES=NULL
        "STATIC_STRING_REPLACE_MODULES_PROTO=extern void __STRING_REPLACE_dummy_module_proto(void)"
        STATIC_vfs_offline_MODULES=NULL
        "STATIC_vfs_offline_MODULES_PROTO=extern void __vfs_offline_dummy_module_proto(void)"
        STATIC_vfs_extd_audit_MODULES=NULL
        "STATIC_vfs_extd_audit_MODULES_PROTO=extern void __vfs_extd_audit_dummy_module_proto(void)"
        STATIC_vfs_default_MODULES=NULL
        "STATIC_vfs_default_MODULES_PROTO=extern void __vfs_default_dummy_module_proto(void)"
        STATIC_LIBLSA_MODULES=NULL
        "STATIC_LIBLSA_MODULES_PROTO=extern void __LIBLSA_dummy_module_proto(void)"
        STATIC_LEASES_UTIL_MODULES=NULL
        "STATIC_LEASES_UTIL_MODULES_PROTO=extern void __LEASES_UTIL_dummy_module_proto(void)"
        STATIC_LIBADS_SERVER_MODULES=NULL
        "STATIC_LIBADS_SERVER_MODULES_PROTO=extern void __LIBADS_SERVER_dummy_module_proto(void)"
        STATIC_RPC_SERVER_MODULES=NULL
        "STATIC_RPC_SERVER_MODULES_PROTO=extern void __RPC_SERVER_dummy_module_proto(void)"
        STATIC_LIBAFS_MODULES=NULL
        "STATIC_LIBAFS_MODULES_PROTO=extern void __LIBAFS_dummy_module_proto(void)"
        STATIC_vfs_crossrename_MODULES=NULL
        "STATIC_vfs_crossrename_MODULES_PROTO=extern void __vfs_crossrename_dummy_module_proto(void)"
        STATIC_RPC_SPOOLSS_MODULES=NULL
        "STATIC_RPC_SPOOLSS_MODULES_PROTO=extern void __RPC_SPOOLSS_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        -fstack-clash-protection
        -Wno-strict-overflow
)
