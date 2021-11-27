include (platform/nk)

project_header_default("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")
nk_build_edl_files(${TARGET_NAME}_edl_files NK_MODULE ${PROJECT_NAME} EDL ${TARGET_NAME}.edl)

set_property(SOURCE "${CMAKE_BINARY_DIR}/_headers_/${PROJECT_NAME}/${TARGET_NAME}.edl.h" PROPERTY SKIP_AUTOGEN ON)

find_package(vfs REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

add_executable(${TARGET_NAME}
        ${TARGET_SRC}
        ${EDL_FILES}
        )

add_dependencies(${TARGET_NAME} ${TARGET_NAME}_edl_files)

target_link_libraries(${TARGET_NAME}
        ${vfs_CLIENT_LIB}
        ${TARGET_LIBS}
        )

if(KOS_HW)
    set_target_properties(${TARGET_NAME} PROPERTIES LINK_FLAGS_RELEASE -s)
endif()

add_kos_external_target(${TARGET_NAME}
        QEMU_ENTITY ${TARGET_NAME}::entity
        HW_ENTITY ${TARGET_NAME}::entity
        )
