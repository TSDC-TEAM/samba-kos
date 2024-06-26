cmake_minimum_required(VERSION 3.14)

project (example_smbclient)

# Include the CMake library named install,
# which contains artifact installation functions.
include (platform/install)

# Include the CMake library named options,
# which contains platform definitions.
include (platform/options)

# Initialize CMake library for the KasperskyOS SDK.
include (platform)
# Statically link executable files.
initialize_platform (FORCE_STATIC)

# Include the CMake library named nk for working with
# the NK compiler (nk-gen-c).
include (platform/nk)

find_package (smblib REQUIRED)

# Add a package for working with the virtual file system.
find_package (vfs REQUIRED)
include_directories (${vfs_INCLUDE})

# Add a package with the Dhcpcd program implementation.
find_package (rump REQUIRED COMPONENTS DHCPCD_ENTITY)
include_directories (${rump_INCLUDE})

# Add a package with the VFS progam implementations.
find_package (precompiled_vfs REQUIRED)
include_directories (${precompiled_vfs_INCLUDE})

# Choose the storage devices for the configuration files.
# If none of the options are selected, the ramfs device is used.
option (ROOTFS_SDCARD   "Use SD card to get configuration file" OFF)

add_subdirectory (testclient)
add_subdirectory (einit)
