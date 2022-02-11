set(TARGET_NAME messages-dgm)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/lib/messaging/messages_dgm.c
        ${SMB_SRC_ROOT}/lib/messaging/messages_dgm_ref.c
        ${SMB_SRC_ROOT}/lib/pthreadpool/pthreadpool.c
        ${SMB_SRC_ROOT}/lib/pthreadpool/pthreadpool_pipe.c
        ${SMB_SRC_ROOT}/lib/pthreadpool/pthreadpool_tevent.c
        )

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/lib/messaging
        ${SMB_SRC_ROOT}/bin/default/lib/messaging
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
        ${SMB_SRC_ROOT}/lib/util/home/user/samba-of-pred-kos-2/third_party/gpfs
        ${SMB_SRC_ROOT}/bin/default/lib/util/home/user/samba-of-pred-kos-2/third_party/gpfs
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/bin/default/lib/tevent
        ${SMB_SRC_ROOT}/lib/util/charset
        ${SMB_SRC_ROOT}/bin/default/lib/util/charset
        ${SMB_SRC_ROOT}/lib/pthreadpool
        ${SMB_SRC_ROOT}/bin/default/lib/pthreadpool
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        ${SMB_SRC_ROOT}/libcli/util
        ${SMB_SRC_ROOT}/bin/default/libcli/util
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
        STATIC_messages_dgm_MODULES=NULL
        "STATIC_messages_dgm_MODULES_PROTO=extern void __messages_dgm_dummy_module_proto(void)"
        STATIC_PTHREADPOOL_MODULES=NULL
        "STATIC_PTHREADPOOL_MODULES_PROTO=extern void __PTHREADPOOL_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        -fstack-clash-protection
)
