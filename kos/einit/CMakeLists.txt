project (einit)

# Toolkit for working with NK parser.
include (platform/image)

# Set compilation flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

# Define an ENTITIES variable with a list of entities.
set (ENTITIES
        Env
        Smbd
        ${precompiled_vfsVfsRamFs}
        ${precompiled_vfsVfsNet}
        ${rump_DHCPCD_ENTITY})

if ("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "arm|aarch64")
    set (SECURITY_PSL_FILE "src/security.psl")
else ()
    message (FATAL_ERROR "${CMAKE_SYSTEM_PROCESSOR} architecture is not supported." )
endif ()

set_target_properties (${rump_DHCPCD_ENTITY} PROPERTIES
        EXTRA_CONNECTIONS
        "  - target: samba.Env
    id: {var: ENV_SERVICE_NAME, include: env/env.h}
  - target: kl.VfsNet
    id: kl.VfsNet
  - target: kl.VfsRamFs
    id: kl.VfsRamFs")
set_target_properties (${rump_DHCPCD_ENTITY} PROPERTIES DEPENDS_ON_ENTITY "")

set (ENV_ENTITY_CONNECTION
        "  - target: samba.Env
    id: {var: ENV_SERVICE_NAME, include: env/env.h}")

set_target_properties (${precompiled_vfsVfsNet} PROPERTIES
        EXTRA_CONNECTIONS ${ENV_ENTITY_CONNECTION})

set_target_properties (${precompiled_vfsVfsRamFs} PROPERTIES
        EXTRA_CONNECTIONS ${ENV_ENTITY_CONNECTION})

set_target_properties (${precompiled_vfsVfsSdCardFs} PROPERTIES
        EXTRA_CONNECTIONS ${ENV_ENTITY_CONNECTION})

# Add a target with making and copying the disk image to the example build
# directory.
add_custom_command (OUTPUT ramdisk0.img
        COMMAND ${CMAKE_COMMAND} -E make_directory
        ${PRODUCT_BINARY_DIR}/hdd
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${RESOURCES_PATH}/ramfs
        ${PRODUCT_BINARY_DIR}/hdd
        COMMAND $ENV{SDK_PREFIX}/common/prepare_hdd_img.sh -d ${PRODUCT_BINARY_DIR}/hdd -img ramdisk0.img -f ext4 -s 128)
add_custom_target (ramdisk0.img DEPENDS ramdisk0.img)

set (FILES ${PRODUCT_BINARY_DIR}/einit/ramdisk0.img)

# Building Kaspersky OS solution image for a hardware platform.
build_kos_hw_image (kos-image
        EINIT_ENTITY EinitHw
        CONNECTIONS_CFG "src/init.yaml.in"
        SECURITY_PSL ${SECURITY_PSL_FILE}
        IMAGE_FILES ${ENTITIES}
        ${FILES})
add_dependencies (kos-image ramdisk0.img)

# Building Kaspersky OS solution image for a QEMU platform.
build_kos_qemu_image (kos-qemu-image
        EINIT_ENTITY EinitQemu
        CONNECTIONS_CFG "src/init.yaml.in"
        SECURITY_PSL ${SECURITY_PSL_FILE}
        QEMU_FLAGS "-nic user,hostfwd=tcp::1490-:1490 -display none"
        IMAGE_FILES ${ENTITIES}
        ${FILES})
add_dependencies (kos-qemu-image ramdisk0.img)
