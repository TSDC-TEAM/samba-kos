set (TARGET_NAME TestClient)
set (TARGET_EDL edl_files_${TARGET_NAME})

generate_edl_file (${TARGET_NAME} PREFIX "testclient")
nk_build_edl_files (${TARGET_EDL} NK_MODULE "testclient" EDL "${EDL_FILE}")

add_executable (${TARGET_NAME} "src/main.c")
add_dependencies (${TARGET_NAME} ${TARGET_EDL})
target_link_libraries (${TARGET_NAME} samba::smblib
									  vfs::client)

# The macro @INIT_<program_name>_ENTITY_CONNECTIONS@ can be used to automatically
# generate strings for a static channel with VFS.
# To make sure that this macro is replaced with an empty string, which is required
# if we want to use a dynamic channel, this command is added to CMakeLists.txt.
set_target_properties (${TARGET_NAME} PROPERTIES vfs::entity_REPLACEMENT "")
