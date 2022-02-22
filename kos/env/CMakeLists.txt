project (env)

# Toolchain for work with NK-parser.
include (platform/nk)

# Set compilation flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

nk_build_edl_files (samba_env
        NK_MODULE "samba"
        EDL "${RESOURCES_PATH}/edl/Env.edl")

add_executable (Env "src/env.c" ${EDL_FILES})
add_dependencies(Env samba_env)
target_link_libraries (Env ${ENV_SERVER_LIB})
