set(TARGET_NAME resolv)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/kos/samba/libs/resolv/kosresolv.c
)

add_library(
        ${TARGET_NAME}_obj
        OBJECT
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}_obj
        PRIVATE
)

target_compile_definitions(
        ${TARGET_NAME}_obj
        PRIVATE
)

target_compile_options(
        ${TARGET_NAME}_obj
        PRIVATE
)
