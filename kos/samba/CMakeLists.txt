cmake_minimum_required (VERSION 3.25)
project (samba LANGUAGES C CXX VERSION 4.15.2)

# Path to Samba sources.
get_filename_component (SMB_SRC_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

set (SANITIZE 0)

add_compile_options ("-Wno-unused-command-line-argument"
                     "-Wno-macro-redefined"
                     "-Wno-unknown-warning-option"
                     "-Wno-deprecated-declarations"
                     "-O2")
if (SANITIZE)
    add_compile_options ("-fsanitize=address"
                         "-fno-omit-frame-pointer")
    add_link_options ("-fsanitize=address")
endif ()

# Initialize CMake library for KasperskyOS SDK.
include (platform)
initialize_platform (FORCE_STATIC)

# Set the linker and compiler flags.
project_header_default ("STANDARD_GNU_17:YES" "STRICT_WARNINGS:YES")

# Add functions for installing artefacts.
include (platform/install)

# Toolchain for working with the NK-parser.
include (platform/nk)

# Add a package for working with the virtual file system.
find_package (vfs REQUIRED)

# Add a package with VFS program implementations.
find_package (precompiled_vfs REQUIRED)
include_directories (${precompiled_vfs_INCLUDE})

# Add a package with the Dhcpcd program implementation.
find_package (rump REQUIRED COMPONENTS DHCPCD_ENTITY)
include_directories (${rump_INCLUDE})

set (EXPORT_TARGETS)

# Add subdirectory with kossmb library implementation.
add_subdirectory(libs)
# Add subdirectory with Smbd program implementation.
add_subdirectory(smbd)

# Install rules.
export_targets (TARGETS ${EXPORT_TARGETS}
                GENERATE_CONFIG_IN
                NO_SET_AND_CHECK_MACRO)

# Uninstall rule.
if (NOT TARGET uninstall)
    configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
                    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
                    IMMEDIATE @ONLY)

    add_custom_target (uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif ()
