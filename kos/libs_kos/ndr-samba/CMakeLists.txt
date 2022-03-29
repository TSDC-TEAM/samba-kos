set(TARGET_NAME ndr-samba)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_schannel.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_schannel.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_epmapper.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_compression.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_named_pipe_auth.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_smb2_lease_struct.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_orpc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_orpc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/ndr-samba.empty.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_mdssvc.c
        ${SMB_SRC_ROOT}/bin/default/source3/librpc/gen_ndr/ndr_smbXsrv.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_drsuapi.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_drsuapi.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_witness.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_witness.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_idmap.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_fsrvp.c
        ${SMB_SRC_ROOT}/bin/default/source3/librpc/gen_ndr/ndr_open_files.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_unixinfo.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_xattrDUP.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_xattr.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_krb5ccache.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_ntlmssp.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_ntlmssp.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dnsserver.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_dnsserver.c
        ${SMB_SRC_ROOT}/lib/compression/lzxpress.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_drsblobs.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_drsblobs.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_auth.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_authDUP.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_ntprinting.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_ntprintingDUP.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_mgmt.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_dcom.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_negoex.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_negoex.c
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
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/bin/default/lib/talloc
        ${SMB_SRC_ROOT}/libcli/nbt
        ${SMB_SRC_ROOT}/bin/default/libcli/nbt
        /usr/include/p11-kit-1
        ${SMB_SRC_ROOT}/lib/compression
        ${SMB_SRC_ROOT}/bin/default/lib/compression
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
        ${SMB_SRC_ROOT}/lib/popt
        ${SMB_SRC_ROOT}/bin/default/lib/popt
        ${SMB_SRC_ROOT}/source3/librpc
        ${SMB_SRC_ROOT}/bin/default/source3/librpc
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
        STATIC_NDR_SCHANNEL_MODULES=NULL
        "STATIC_NDR_SCHANNEL_MODULES_PROTO=extern void __NDR_SCHANNEL_dummy_module_proto(void)"
        STATIC_NDR_EPMAPPER_MODULES=NULL
        "STATIC_NDR_EPMAPPER_MODULES_PROTO=extern void __NDR_EPMAPPER_dummy_module_proto(void)"
        STATIC_NDR_COMPRESSION_MODULES=NULL
        "STATIC_NDR_COMPRESSION_MODULES_PROTO=extern void __NDR_COMPRESSION_dummy_module_proto(void)"
        STATIC_NDR_NAMED_PIPE_AUTH_MODULES=NULL
        "STATIC_NDR_NAMED_PIPE_AUTH_MODULES_PROTO=extern void __NDR_NAMED_PIPE_AUTH_dummy_module_proto(void)"
        STATIC_NDR_SMB2_LEASE_STRUCT_MODULES=NULL
        "STATIC_NDR_SMB2_LEASE_STRUCT_MODULES_PROTO=extern void __NDR_SMB2_LEASE_STRUCT_dummy_module_proto(void)"
        STATIC_NDR_ORPC_MODULES=NULL
        "STATIC_NDR_ORPC_MODULES_PROTO=extern void __NDR_ORPC_dummy_module_proto(void)"
        STATIC_ndr_samba_MODULES=NULL
        "STATIC_ndr_samba_MODULES_PROTO=extern void __ndr_samba_dummy_module_proto(void)"
        STATIC_NDR_MDSSVC_MODULES=NULL
        "STATIC_NDR_MDSSVC_MODULES_PROTO=extern void __NDR_MDSSVC_dummy_module_proto(void)"
        STATIC_NDR_SMBXSRV_MODULES=NULL
        "STATIC_NDR_SMBXSRV_MODULES_PROTO=extern void __NDR_SMBXSRV_dummy_module_proto(void)"
        STATIC_NDR_DRSUAPI_MODULES=NULL
        "STATIC_NDR_DRSUAPI_MODULES_PROTO=extern void __NDR_DRSUAPI_dummy_module_proto(void)"
        STATIC_NDR_WITNESS_MODULES=NULL
        "STATIC_NDR_WITNESS_MODULES_PROTO=extern void __NDR_WITNESS_dummy_module_proto(void)"
        STATIC_NDR_IDMAP_MODULES=NULL
        "STATIC_NDR_IDMAP_MODULES_PROTO=extern void __NDR_IDMAP_dummy_module_proto(void)"
        STATIC_NDR_FSRVP_MODULES=NULL
        "STATIC_NDR_FSRVP_MODULES_PROTO=extern void __NDR_FSRVP_dummy_module_proto(void)"
        STATIC_NDR_OPEN_FILES_MODULES=NULL
        "STATIC_NDR_OPEN_FILES_MODULES_PROTO=extern void __NDR_OPEN_FILES_dummy_module_proto(void)"
        STATIC_NDR_UNIXINFO_MODULES=NULL
        "STATIC_NDR_UNIXINFO_MODULES_PROTO=extern void __NDR_UNIXINFO_dummy_module_proto(void)"
        STATIC_NDR_XATTR_MODULES=NULL
        "STATIC_NDR_XATTR_MODULES_PROTO=extern void __NDR_XATTR_dummy_module_proto(void)"
        STATIC_NDR_KRB5CCACHE_MODULES=NULL
        "STATIC_NDR_KRB5CCACHE_MODULES_PROTO=extern void __NDR_KRB5CCACHE_dummy_module_proto(void)"
        STATIC_NDR_NTLMSSP_MODULES=NULL
        "STATIC_NDR_NTLMSSP_MODULES_PROTO=extern void __NDR_NTLMSSP_dummy_module_proto(void)"
        STATIC_NDR_DNSSERVER_MODULES=NULL
        "STATIC_NDR_DNSSERVER_MODULES_PROTO=extern void __NDR_DNSSERVER_dummy_module_proto(void)"
        STATIC_LZXPRESS_MODULES=NULL
        "STATIC_LZXPRESS_MODULES_PROTO=extern void __LZXPRESS_dummy_module_proto(void)"
        STATIC_NDR_DRSBLOBS_MODULES=NULL
        "STATIC_NDR_DRSBLOBS_MODULES_PROTO=extern void __NDR_DRSBLOBS_dummy_module_proto(void)"
        STATIC_NDR_AUTH_MODULES=NULL
        "STATIC_NDR_AUTH_MODULES_PROTO=extern void __NDR_AUTH_dummy_module_proto(void)"
        STATIC_NDR_NTPRINTING_MODULES=NULL
        "STATIC_NDR_NTPRINTING_MODULES_PROTO=extern void __NDR_NTPRINTING_dummy_module_proto(void)"
        STATIC_NDR_MGMT_MODULES=NULL
        "STATIC_NDR_MGMT_MODULES_PROTO=extern void __NDR_MGMT_dummy_module_proto(void)"
        STATIC_NDR_DCOM_MODULES=NULL
        "STATIC_NDR_DCOM_MODULES_PROTO=extern void __NDR_DCOM_dummy_module_proto(void)"
        STATIC_NDR_NEGOEX_MODULES=NULL
        "STATIC_NDR_NEGOEX_MODULES_PROTO=extern void __NDR_NEGOEX_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
