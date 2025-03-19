set(TARGET_NAME winbind-client)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/nsswitch/wb_common.c
        )

add_library(
        ${TARGET_NAME}_obj
        OBJECT
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}_obj
        PRIVATE
        ${SMB_SRC_ROOT}/nsswitch
        ${SMB_SRC_ROOT}/bin/default/nsswitch
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
)

target_compile_definitions(
        ${TARGET_NAME}_obj
        PRIVATE
        _SAMBA_BUILD_=4
        HAVE_CONFIG_H=1
        _GNU_SOURCE=1
        _XOPEN_SOURCE_EXTENDED=1
        WINBINDD_SOCKET_DIR="/usr/local/samba/var/run/winbindd"
        __STDC_WANT_LIB_EXT1__=1
        _REENTRANT
        _POSIX_PTHREAD_SEMANTICS
        STATIC_winbind_client_MODULES=NULL
        "STATIC_winbind_client_MODULES_PROTO=extern void __winbind_client_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}_obj
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
