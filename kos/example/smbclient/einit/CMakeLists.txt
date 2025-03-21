project (einit)

# Include the CMake library named image,
# which contains the solution image build scripts.
include (platform/image)
include (${KL_SDK_ROOT_PATH}/common/build-sd-image.cmake)

# Set the linker and compiler flags.
project_header_default ("STANDARD_GNU_17:YES" "STRICT_WARNINGS:NO")

# Define an ENTITIES variable with a list of programs.
set (ENTITIES
    TestClient
    precompiled_vfs::VfsNet
    rump::dhcpcd_entity
)

set (SECURITY_PSL_FILE "src/security.psl.in")
set (INIT_YAML_FILE "src/init.yaml.in")

# Add a target for making and copying the disk image to the example build
# directory.
set (CREATE_DISK_IMAGE $ENV{SDK_PREFIX}/common/prepare_hdd_img.sh)
set (DISK_IMAGE_DIR ${CMAKE_SOURCE_DIR}/resources/hdd)

if (ROOTFS_SDCARD)
    set (ROOTFS_ENTITY "kl.VfsSdCardFs")
    set (ROOTFS_DEVICE "sdcard")
    set (FS_BACKEND precompiled_vfs::VfsSdCardFs)
    set (DISK_IMAGE sdcard0.img)
    set (DISK_IMAGE_FS fat32)
    set (QEMU_FLAGS "-m 2048 -sd ${DISK_IMAGE}")
else()
    set (ROOTFS_ENTITY "kl.VfsRamFs")
    set (ROOTFS_DEVICE "ramfs")
    set (FS_BACKEND precompiled_vfs::VfsRamFs)
    set (DISK_IMAGE ramdisk0.img)
    set (DISK_IMAGE_FS ext4)
    set (FILES ${CMAKE_BINARY_DIR}/einit/${DISK_IMAGE})
endif()

# Information about selected configuration files source.
message ("Used DHCP client daemon configuration from ${ROOTFS_DEVICE}:/etc/dhcpcd.conf")
message ("Used NTP client daemon configuration from ${ROOTFS_DEVICE}:/etc/ntp.conf")

list (APPEND ENTITIES ${FS_BACKEND})

set_target_properties(${FS_BACKEND} PROPERTIES
    EXTRA_ARGS "\
    - -l
    - devfs /dev devfs 0")

set (EXTRA_CONNECTIONS "\
  - target: kl.VfsNet
    id: kl.VfsNet
  - target: ${ROOTFS_ENTITY}
    id: ${ROOTFS_ENTITY}")

# Set additional connections for Dhcpcd program.
set_target_properties (rump::dhcpcd_entity PROPERTIES
    DEPENDS_ON_ENTITY ""
    EXTRA_CONNECTIONS ${EXTRA_CONNECTIONS}
    EXTRA_ENV "\
    VFS_FILESYSTEM_BACKEND: client{fs->net}:${ROOTFS_ENTITY}
    VFS_NETWORK_BACKEND: client:kl.VfsNet"
    EXTRA_ARGS "\
    - '-4'
    - '-f'
    - /etc/dhcpcd.conf")

add_custom_target (${DISK_IMAGE}
    COMMAND ${CREATE_DISK_IMAGE} -d ${DISK_IMAGE_DIR} -img ${DISK_IMAGE} -f ${DISK_IMAGE_FS})

# Create a top-level CMake target named kos-image which can be used
# when building a solution image to be started on the hardware platform.
build_kos_hw_image (kos-image
                    EINIT_ENTITY EinitHw
                    CONNECTIONS_CFG ${INIT_YAML_FILE}
                    SECURITY_PSL ${SECURITY_PSL_FILE}
                    IMAGE_FILES ${ENTITIES}
                                ${FILES})

# Create a top-level CMake target named sd-image which can be used
# when building an SD card image to be started on the hardware platform.
build_sd_image (sd-image
                KOS_IMAGE_TARGET kos-image
                IMAGE_FS ${IMAGE_FS})

# Add a dependency on disk image generation to the kos-image target only if a ramdisk is used.
# The disk image must be generated before the kos-image target is built.
if (NOT ROOTFS_SDCARD)
    add_dependencies (kos-image ${DISK_IMAGE})
endif ()

# Create a top-level CMake target named kos-qemu-image which
# can be used when building a solution image to be started in QEMU.
build_kos_qemu_image (kos-qemu-image
                      EINIT_ENTITY EinitQemu
                      CONNECTIONS_CFG ${INIT_YAML_FILE}
                      SECURITY_PSL ${SECURITY_PSL_FILE}
                      QEMU_FLAGS "${QEMU_FLAGS} -nic user -display none"
                      IMAGE_FILES ${ENTITIES}
                                  ${FILES})
add_dependencies (kos-qemu-image ${DISK_IMAGE})
