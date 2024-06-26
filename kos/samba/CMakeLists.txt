cmake_minimum_required (VERSION 3.12)

option(KOS_HW "Build for KOS HW (default is FALSE)" OFF)

project(samba LANGUAGES C CXX)

set(SANITIZE 1)

if(SANITIZE AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options("-fsanitize=address" "-fno-omit-frame-pointer")
    add_link_options("-fsanitize=address")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(GCCDEFS "-fstack-clash-protection")
endif()

set(CMAKE_C_STANDARD 11)

set(SMB_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(PRODUCT_RESOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)
set(PRODUCT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(RESOURCES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/resources)

if (KOS)
    # Initialize CMake library for the KasperskyOS SDK.
    include (platform)
    # Statically link executable files.
    initialize_platform (FORCE_STATIC)

    # Include the CMake library named install,
    # which contains artifact installation functions.
    include (platform/install)

    # Include the CMake library named options,
    # which contains platform definitions.
    include (platform/options)

    # # Include the CMake library named nk
    # for working with the NK compiler (nk-gen-c).
    include (platform/nk)

    # Attach a package with the virtual file system implementation.
    find_package (vfs REQUIRED)
    include_directories (${vfs_INCLUDE})

    # Attach a package with the Dhcpcd program implementation.
    find_package (rump REQUIRED COMPONENTS DHCPCD_ENTITY)
    include_directories (${rump_INCLUDE})

    # Attach a package with the VFS program implementation.
    find_package (precompiled_vfs REQUIRED)
    include_directories (${precompiled_vfs_INCLUDE})

    # Choose the storage devices for the configuration files.
    # If none of the option is selected, the ramfs device is used.
    option(ROOTFS_SDCARD   "Use SD card to get configuration file"       OFF)

    # Build configuration header files from a configuration file template.
    # configure_file(resources/include/config.h.in config.h)

    # Attach the directory with the generated config header files.
    include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif ()

add_subdirectory(libs)
add_subdirectory(smbd)

#
# Package configure file.
#
include(CMakePackageConfigHelpers)

set(LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib)
set(BIN_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/bin)

configure_package_config_file(smbd-config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/smbd-config.cmake
        INSTALL_DESTINATION ${LIB_INSTALL_DIR}/smbd/cmake
        PATH_VARS BIN_INSTALL_DIR
)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/smbd-config-version.cmake
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion
)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/smbd-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/smbd-config-version.cmake
        DESTINATION ${LIB_INSTALL_DIR}/cmake/smbd
)

configure_package_config_file(smblib-config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/smblib-config.cmake
        INSTALL_DESTINATION ${LIB_INSTALL_DIR}/smblib/cmake
        PATH_VARS LIB_INSTALL_DIR
)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/smblib-config-version.cmake
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion
)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/smblib-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/smblib-config-version.cmake
        DESTINATION ${LIB_INSTALL_DIR}/cmake/smblib
)

if(NOT TARGET uninstall)
    configure_file(
            "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
            "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
            IMMEDIATE @ONLY)

    add_custom_target(uninstall
            COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

