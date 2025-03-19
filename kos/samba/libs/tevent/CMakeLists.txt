set(TARGET_NAME tevent)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/lib/tevent/tevent.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_debug.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_fd.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_immediate.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_queue.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_req.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_wrapper.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_poll.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_threads.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_signal.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_standard.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_timed.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_util.c
        ${SMB_SRC_ROOT}/lib/tevent/tevent_wakeup.c
        )

add_library(
        ${TARGET_NAME}_obj
        OBJECT
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}_obj
        PRIVATE
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/bin/default/lib/tevent
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
        STATIC_tevent_MODULES=NULL
        "STATIC_tevent_MODULES_PROTO=extern void __tevent_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}_obj
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
)
