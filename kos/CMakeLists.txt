option(KOS_HW "Build for KOS HW (default is FALSE)" OFF)

if (KOS)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/kos)
else()
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/linux)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(PRODUCT_RESOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)
set(PRODUCT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(RESOURCES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/resources)

if (KOS)
    # Initialize CMake library for Kaspersky OS SDK.
    include (platform)
    initialize_platform ()

    # Connect artifact installation functions.
    include (platform/install)

    # Platform definitions
    include (platform/options)

    # Build idl/cdl/edl files
    include (platform/nk)

    # Attach a package with the virtual file system implementation.
    find_package (vfs REQUIRED)
    include_directories (${vfs_INCLUDE})

    # Attach a package with the dhcpcd entity implementation.
    find_package (rump REQUIRED COMPONENTS DHCPCD_ENTITY)
    include_directories (${rump_INCLUDE})

    # Attach a package with VFS entities implementation
    find_package (precompiled_vfs REQUIRED)
    include_directories (${precompiled_vfs_INCLUDE})

    # Choose the storage devices for the configuration files.
    # If none of the option is selected, the ramfs device is used.
    option(ROOTFS_SDCARD   "Use SD card to get configuration file"       OFF)

    # Build configuration header files from a configuration file template
    #configure_file(resources/include/config.h.in config.h)

    # Attach the directory with the generated config header files
    include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif ()

add_subdirectory(libs_kos)
add_subdirectory(smbd)

if (KOS)
    add_subdirectory(env)
    add_subdirectory(einit)
endif ()
