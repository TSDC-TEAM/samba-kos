# Tools for working with KasperskyOS images.
include (platform/image)

set (SECURITY_PSL_FILE       "src/security.psl")
set (CONNECTIONS_CFG_FILE    "src/init.yaml.in")
set (IMAGE_FS                "${CMAKE_BINARY_DIR}/hdd")
set (QEMU_DISK_IMAGE         sdcard0.img)
set (QEMU_DEPENDENCIES       ${QEMU_DISK_IMAGE})
set (QEMU_FLAGS              "-drive file=${QEMU_DISK_IMAGE},if=sd,format=raw")
set (QEMU_USER_NETWORK_FLAGS "hostfwd=tcp::1490-:1490")
# Add the hosts file to the common list of files included in the ROMFS image.
# This is required so that the VfsNet executable file can access the network settings in the hosts file.
set (FILES                   "${RESOURCES}/hdd/etc/hosts")
set (GINGER_DEFINITIONS      "BOARD=${CMAKE_SYSTEM_BOARD}")

# Define an ENTITIES variable with a list of entities.
set (ENTITIES NetInit
              samba::Smbd
              precompiled_vfs::VfsSdCardFs
              precompiled_vfs::VfsNet
              rump::dhcpcd_entity)

# Set additional connections for NetInit.
set (NETINIT_ENV "
    VFS_NETWORK_BACKEND: client:kl.VfsNet
    VFS_FILESYSTEM_BACKEND: client:kl.VfsSdCardFs")

set_target_properties (NetInit PROPERTIES
                       DEPENDS_ON_ENTITY "precompiled_vfs::VfsSdCardFs;precompiled_vfs::VfsNet"
                       EXTRA_ENV         ${NETINIT_ENV}
                       EXTRA_OPTIONS     "  wait_for: exit_success\n  before:\n  - samba::Smbd")

# Set additional connections for samba::Smbd.
set (SMBD_ENV "
    VFS_NETWORK_BACKEND: client:kl.VfsNet
    VFS_FILESYSTEM_BACKEND: client:kl.VfsSdCardFs")

set_target_properties (samba::Smbd PROPERTIES
                       DEPENDS_ON_ENTITY "precompiled_vfs::VfsSdCardFs;precompiled_vfs::VfsNet"
                       EXTRA_ENV         ${SMBD_ENV})

# Set additional connections for rump::dhcpcd_entity.
set (DHCPCD_ENV "
    VFS_FILESYSTEM_BACKEND: client{fs->net}:kl.VfsSdCardFs
    VFS_NETWORK_BACKEND:    client:kl.VfsNet")

set (DHCPCD_ARGS "
    - '-4'
    - '-f'
    - /etc/dhcpcd.conf")

set_target_properties (rump::dhcpcd_entity PROPERTIES
                       DEPENDS_ON_ENTITY "precompiled_vfs::VfsSdCardFs;precompiled_vfs::VfsNet"
                       EXTRA_ENV         ${DHCPCD_ENV}
                       EXTRA_ARGS        ${DHCPCD_ARGS})

set_target_properties (precompiled_vfs::VfsNet PROPERTIES
    EXTRA_ARGS "\
    - -l
    - devfs /dev devfs 0
    - -l
    - romfs /etc romfs ro")

# Add a target to create filesystem for disk image.
add_custom_target (disk_image_fs
                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES}/hdd ${IMAGE_FS})

add_custom_target (${QEMU_DISK_IMAGE}
                   DEPENDS disk_image_fs
                   COMMAND ${KL_SDK_ROOT_PATH}/common/prepare_hdd_img.sh
                           -d ${IMAGE_FS} -s 64 -f fat32 -img ${QEMU_DISK_IMAGE})

if (NOT "${CMAKE_SYSTEM_BOARD}" STREQUAL "QEMU")
    include (${KL_SDK_ROOT_PATH}/common/build-sd-image.cmake)

    # KasperskyOS image for the target hardware platform.
    build_kos_hw_image (kos-image
                        EINIT_ENTITY       EinitHw
                        CONNECTIONS_CFG    ${CONNECTIONS_CFG_FILE}
                        SECURITY_PSL       ${SECURITY_PSL_FILE}
                        GINGER_ENABLE      TRUE
                        GINGER_DEFINITIONS ${GINGER_DEFINITIONS}
                        IMAGE_FILES        ${ENTITIES}
                                           ${FILES})

    add_dependencies (kos-image disk_image_fs)

    # SD card image with KasperskyOS for the target hardware platform.
    build_sd_image (sd-image
                    KOS_IMAGE_TARGET      kos-image
                    PATH_PARTITION1_IMAGE ${IMAGE_FS})

else ()
    # KasperskyOS image for QEMU with simulation targets (sim, gdbsim, gdb).
    build_kos_qemu_image (kos-qemu-image
                          EINIT_ENTITY            EinitQemu
                          CONNECTIONS_CFG         ${CONNECTIONS_CFG_FILE}
                          SECURITY_PSL            ${SECURITY_PSL_FILE}
                          GINGER_ENABLE           TRUE
                          GINGER_DEFINITIONS      ${GINGER_DEFINITIONS}
                          QEMU_FLAGS              "${QEMU_FLAGS}"
                          QEMU_USER_NETWORK_FLAGS "${QEMU_USER_NETWORK_FLAGS}"
                          QEMU_DEPENDENCIES       "${QEMU_DEPENDENCIES}"
                          IMAGE_FILES             ${ENTITIES}
                                                  ${FILES})
endif ()
