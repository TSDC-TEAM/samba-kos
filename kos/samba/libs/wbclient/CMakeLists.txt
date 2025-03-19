set(TARGET_NAME wbclient)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/nsswitch/libwbclient/wbc_guid.c
        ${SMB_SRC_ROOT}/nsswitch/libwbclient/wbc_idmap.c
        ${SMB_SRC_ROOT}/nsswitch/libwbclient/wbclient.c
        ${SMB_SRC_ROOT}/nsswitch/libwbclient/wbc_pam.c
        ${SMB_SRC_ROOT}/nsswitch/libwbclient/wbc_pwd.c
        ${SMB_SRC_ROOT}/nsswitch/libwbclient/wbc_sid.c
        ${SMB_SRC_ROOT}/nsswitch/libwbclient/wbc_util.c
        ${SMB_SRC_ROOT}/lib/util/smb_strtox.c
        )

add_library(
        ${TARGET_NAME}_obj
        OBJECT
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}_obj
        PRIVATE
        ${SMB_SRC_ROOT}/nsswitch/libwbclient
        ${SMB_SRC_ROOT}/bin/default/nsswitch/libwbclient
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
        ${SMB_SRC_ROOT}/nsswitch
        ${SMB_SRC_ROOT}/bin/default/nsswitch
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
        STATIC_wbclient_MODULES=NULL
        "STATIC_wbclient_MODULES_PROTO=extern void __wbclient_dummy_module_proto(void)"
        STATIC_smb_strtox_MODULES=NULL
        "STATIC_smb_strtox_MODULES_PROTO=extern void __smb_strtox_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}_obj
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
