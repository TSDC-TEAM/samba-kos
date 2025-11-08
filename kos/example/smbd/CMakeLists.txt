cmake_minimum_required (VERSION 3.25)
project (example_smbd)

# Initialize CMake library for KasperskyOS SDK.
include (platform)
# Statically link executable files.
initialize_platform (FORCE_STATIC)

# Set the linker and compiler flags.
project_header_default ("STANDARD_GNU_17:YES" "STRICT_WARNINGS:YES")

# Toolchain for working with the NK-parser.
include (platform/nk)

# Add a package with Smbd program implementation.
find_package (samba REQUIRED)

# Add a package for working with the virtual file system.
find_package (vfs REQUIRED)
include_directories (${vfs_INCLUDE})

# Add a package with the Dhcpcd program implementation.
find_package (rump REQUIRED COMPONENTS DHCPCD_ENTITY)
include_directories (${rump_INCLUDE})

# Add a package with the VFS program implementations.
find_package (precompiled_vfs REQUIRED)
include_directories (${precompiled_vfs_INCLUDE})

set (RESOURCES ${CMAKE_SOURCE_DIR}/resources)

add_compile_options (-fPIE -Wall -Wextra -Wconversion -Wsign-conversion
                     -Wformat=2 -Wformat-security -Werror=format-security)

add_subdirectory (netinit)
add_subdirectory (einit)
