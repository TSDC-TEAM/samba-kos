project (testclient)

set(TARGET_NAME TestClient)

set(TARGET_EDL testclient_testclient)

# Include the CMake library named nk for working with the NK compiler (nk-gen-c).
include (platform/nk)

# Set the linker and compiler flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

nk_build_edl_files (${TARGET_EDL}
		NK_MODULE ${PROJECT_NAME}
		EDL ${TARGET_NAME}.edl)

add_executable (${TARGET_NAME} "main.c")
add_dependencies (${TARGET_NAME} ${TARGET_EDL})

target_link_libraries (${TARGET_NAME}
	kossmb
	c pthread ssl crypto z
	${vfs_CLIENT_LIB}
)

# The macro @INIT_<program_name>_ENTITY_CONNECTIONS@ can be used to automatically
# generate strings for a static channel with VFS.
# To make sure that this macro is replaced with an empty string, which is required
# if we want to use a dynamic channel, this command is added to CMakeLists.txt.
set_target_properties (${TARGET_NAME} PROPERTIES ${vfs_ENTITY}_REPLACEMENT "")
