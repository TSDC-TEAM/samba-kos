# Toolkit for working with NK parser.
include (platform/nk)

# Setting compilation flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

nk_build_edl_files (${TARGET_EDL}
        NK_MODULE samba
        EDL ${RESOURCES_PATH}/edl/${TARGET_NAME}.edl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

add_executable(${TARGET_NAME} ${TARGET_SRC} ${EDL_FILES})

add_dependencies(${TARGET_NAME} ${TARGET_EDL})

target_link_libraries(${TARGET_NAME} ${TARGET_LIBS} ${vfs_CLIENT_LIB})

# We do not need default VFS entity here, which comes from ${vfs_CLIENT_LIB}
set_target_properties (${TARGET_NAME} PROPERTIES ${vfs_ENTITY}_REPLACEMENT "")
