set(TARGET_NAME samba-security)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/libcli/security/dom_sid.c
        ${SMB_SRC_ROOT}/libcli/security/display_sec.c
        ${SMB_SRC_ROOT}/libcli/security/secace.c
        ${SMB_SRC_ROOT}/libcli/security/secacl.c
        ${SMB_SRC_ROOT}/libcli/security/security_descriptor.c
        ${SMB_SRC_ROOT}/libcli/security/sddl.c
        ${SMB_SRC_ROOT}/libcli/security/privileges.c
        ${SMB_SRC_ROOT}/libcli/security/security_token.c
        ${SMB_SRC_ROOT}/libcli/security/access_check.c
        ${SMB_SRC_ROOT}/libcli/security/object_tree.c
        ${SMB_SRC_ROOT}/libcli/security/create_descriptor.c
        ${SMB_SRC_ROOT}/libcli/security/util_sid.c
        ${SMB_SRC_ROOT}/libcli/security/session.c
        ${SMB_SRC_ROOT}/libcli/security/secdesc.c
        ${SMB_SRC_ROOT}/bin/default/librpc/gen_ndr/ndr_security.c
        ${SMB_SRC_ROOT}/librpc/ndr/ndr_sec_helper.c
        )

add_library(
        ${TARGET_NAME}_obj
        OBJECT
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}_obj
        PRIVATE
        ${SMB_SRC_ROOT}/libcli/security
        ${SMB_SRC_ROOT}/bin/default/libcli/security
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
        STATIC_samba_security_MODULES=NULL
        "STATIC_samba_security_MODULES_PROTO=extern void __samba_security_dummy_module_proto(void)"
        STATIC_NDR_SECURITY_MODULES=NULL
        "STATIC_NDR_SECURITY_MODULES_PROTO=extern void __NDR_SECURITY_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}_obj
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
