cmake_minimum_required (VERSION 3.14)

project(env)
set(TARGET_NAME Env)

include (platform/nk)

nk_build_edl_files (${TARGET_NAME}_edl_files NK_MODULE ${PROJECT_NAME} EDL ${TARGET_NAME}.edl)
add_executable (${TARGET_NAME} ${EDL_FILES} src/env.c)
add_dependencies(${TARGET_NAME} ${TARGET_NAME}_edl_files)
target_link_libraries (${TARGET_NAME} ${ENV_CLIENT_LIB})
