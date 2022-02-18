cmake_minimum_required (VERSION 3.14)

# Project header
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

find_package (ramdisk REQUIRED)
find_package (ns REQUIRED)

set(SDK_ENTITIES ${ramdisk_ENTITY} ${ns_ENTITY} ${rump_DHCPCD_ENTITY})

use_kos_external_targets(EXTERNAL_ENTITIES)
set(ENTITIES
        ${CMAKE_BINARY_DIR}/bin/Env
        ${EXTERNAL_ENTITIES}
        ${SDK_ENTITIES}
        )

# Connect RAMDISK driver with our implementation of VFS
set_target_properties (${vfs_DEFAULT_ENTITY} PROPERTIES ${blkdev_ENTITY}_REPLACEMENT ${ramdisk_ENTITY})
# We need to connect default VFS entity to env entity.
# Also, we need RAMDISK driver to be connected with default VFS entity.
set_target_properties (${vfs_DEFAULT_ENTITY} PROPERTIES EXTRA_CONNECTIONS
"
  - target: env.Env
    id: {var: ENV_SERVICE_NAME, include: env/env.h}
"
        ${blkdev_ENTITY}_REPLACEMENT ${ramdisk_ENTITY})

# Image file for RAMDISK
set(DISK_IMG ${PRODUCT_BINARY_DIR}/einit/ramdisk0.img)

# Custom target: collection of files from this repo to place into root FS
add_custom_target(ramdisk-image
        DEPENDS ${DISK_IMG}
        COMMENT "${DISK_IMG} is ready"
        )

# Command the copies collection of files into system_hdd and packs it into ${DISK_IMG}
add_custom_command (OUTPUT ${DISK_IMG}
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${PRODUCT_RESOURCE_DIR}/rootdir ${PRODUCT_BINARY_DIR}/system_hdd
        COMMAND mke2fs -v -d ${PRODUCT_BINARY_DIR}/system_hdd -t ext2 ${DISK_IMG} 150M
        COMMENT "Creating disk image ${DISK_IMG} from files in ${PRODUCT_BINARY_DIR}/system_hdd ..."
        )

# gen-product-images is artificial target that will be built on 'make all'
add_custom_target(gen-product-images ALL)
if (KOS_HW)
    # H/W image with KasperskyOS
    build_kos_hw_image (kos-image
            EINIT_ENTITY einit_hw
            CONNECTIONS_CFG "src/init.yaml"
            SECURITY_CFG "src/security.cfg"
            IMAGE_FILES ${ENTITIES} ${SDK_ENTITIES} ${IMG_CONTENT} ${DISK_IMG}
            )
    # enforce building kos-image target on 'make all' by setting it as a dependency
    add_dependencies(gen-product-images kos-image)
    # Workaround for dependency issue
    # build_kos_hw_image doesn't make any dependency on env for target einit_hw
    add_dependencies(einit_hw Env)
else ()
    # QEMU image with KasperskyOS for simulation & debugging (sim, gdbsim, gdb).
    build_kos_qemu_image (kos-qemu-image
            EINIT_ENTITY einit_qemu
            CONNECTIONS_CFG "src/init.yaml"
            SECURITY_CFG "src/security.cfg"
            QEMU_FLAGS "-nic user,hostfwd=tcp::1490-:1490 -display none"
            IMAGE_FILES ${ENTITIES} ${SDK_ENTITIES} ${IMG_CONTENT} ${DISK_IMG}
            QEMU_DEPENDENCIES ${DISK_IMG}
            )
    # enforce building kos-qemu-image target on 'make all' by setting it as a dependency
    add_dependencies(gen-product-images kos-qemu-image)
    # Workaround for dependency issue
    # build_kos_qemu_image doesn't make any dependency on env for target einit_qemu
    add_dependencies(einit_qemu Env)
endif ()

if (KOS_HW)
    add_dependencies(kos-image ramdisk-image)
else()
    add_dependencies(kos-qemu-image ramdisk-image)
    add_dependencies(sim ramdisk-image)
    add_dependencies(gdbsim ramdisk-image)
endif()
