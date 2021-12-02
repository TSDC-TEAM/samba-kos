set(TARGET_NAME talloc)

if(KOS)
    set(TARGET_SRC
            ${SMB_SRC_ROOT}/lib/talloc/talloc.c
            ${SMB_SRC_ROOT}/lib/util/time_basic.c
            ${SMB_SRC_ROOT}/lib/util/blocking.c
            ${SMB_SRC_ROOT}/lib/util/iov_buf.c
            ${SMB_SRC_ROOT}/lib/util/close_low_fd.c
            ${SMB_SRC_ROOT}/lib/util/gpfswrap.c
    )
else()
    set(TARGET_SRC
            ${SMB_SRC_ROOT}/lib/talloc/talloc.c
            ${SMB_SRC_ROOT}/lib/util/time_basic.c
            ${SMB_SRC_ROOT}/lib/util/blocking.c
            ${SMB_SRC_ROOT}/lib/util/iov_buf.c
            ${SMB_SRC_ROOT}/lib/util/close_low_fd.c
            ${SMB_SRC_ROOT}/lib/util/gpfswrap.c
    )
endif()

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/lib
        ${SMB_SRC_ROOT}/lib/replace
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/include/public
        ${SMB_SRC_ROOT}/include
        ${SMB_SRC_ROOT}/source4
        ${SMB_SRC_ROOT}/source4/lib
        ${SMB_SRC_ROOT}/source4/include
        ${SMB_SRC_ROOT}/third_party/gpfs
        ${SMB_SRC_ROOT}/bin/default/include
        ${SMB_SRC_ROOT}
)

set(TALLOC_DEFS
        _SAMBA_BUILD_=4
        HAVE_CONFIG_H=1
        _GNU_SOURCE=1
        _XOPEN_SOURCE_EXTENDED=1
        __STDC_WANT_LIB_EXT1__=1
        _REENTRANT
        )

if(KOS)
    target_compile_definitions(
            ${TARGET_NAME}
            PRIVATE
            ${TALLOC_DEFS}
    )
else()
    target_compile_definitions(
            ${TARGET_NAME}
            PRIVATE
            ${TALLOC_DEFS}
    )
endif()

set_source_files_properties(${SMB_SRC_ROOT}/lib/talloc/talloc.c
        PROPERTIES
        COMPILE_DEFINITIONS "STATIC_talloc_MODULES=NULL \"STATIC_talloc_MODULES_PROTO=extern void __talloc_dummy_module_proto(void)\""
        )
set_source_files_properties(${SMB_SRC_ROOT}/lib/util/time_basic.c
        PROPERTIES
        COMPILE_DEFINITIONS "STATIC_time_basic_MODULES=NULL \"STATIC_time_basic_MODULES_PROTO=extern void __time_basic_dummy_module_proto(void)\""
        )
set_source_files_properties(${SMB_SRC_ROOT}/lib/util/blocking.c
        PROPERTIES
        COMPILE_DEFINITIONS "STATIC_socket_blocking_MODULES=NULL \"STATIC_socket_blocking_MODULES_PROTO=extern void __socket_blocking_dummy_module_proto(void)\""
        )
set_source_files_properties(${SMB_SRC_ROOT}/lib/util/iov_buf.c
        PROPERTIES
        COMPILE_DEFINITIONS "STATIC_iov_buf_MODULES=NULL \"STATIC_iov_buf_MODULES_PROTO=extern void __iov_buf_dummy_module_proto(void)\""
        )
set_source_files_properties(${SMB_SRC_ROOT}/lib/util/close_low_fd.c
        PROPERTIES
        COMPILE_DEFINITIONS "STATIC_close_low_fd_MODULES=NULL \"STATIC_close_low_fd_MODULES_PROTO=extern void __close_low_fd_dummy_module_proto(void)\""
        )
set_source_files_properties(${SMB_SRC_ROOT}/lib/util/gpfswrap.c
        PROPERTIES
        COMPILE_DEFINITIONS "STATIC_gpfswrap_MODULES=NULL \"STATIC_gpfswrap_MODULES_PROTO=extern void __gpfswrap_dummy_module_proto(void)\""
        )

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        -fstack-clash-protection
        -fvisibility=hidden
)
