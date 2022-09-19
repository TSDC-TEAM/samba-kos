set(TARGET_NAME bsd)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/kos/samba/libs/bsd/kosbsd.c
)

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
)

target_compile_definitions(
        ${TARGET_NAME}
        PRIVATE
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
)
