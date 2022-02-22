#include <env/env.h>
#include <precompiled_vfs/defs.h>
#include <stdio.h>
#include <stdlib.h>
#include <vfs/rumpfs_client.h>
#include <vfs/vfs.h>

/* Add an automatically generated config file. */
//#include "config.h"

#define WHITE "\033[1;37m"
#define NC    "\033[0m"

int main(int argc, char** argv)
{
#if defined(ROOTFS_SDCARD)
    const char* RootFsDevice = "sdcard";
#else
    const char* RootFsDevice = "ramfs";
#endif

    const char* VfsNetArgs[] = {
            "-l", "devfs /dev devfs 0"
    };
    const char* VfsNetEnvs[] = {
            _VFS_NETWORK_BACKEND"=server:"NET_VFS_CONNECTION,
            _VFS_FILESYSTEM_BACKEND"=server:"NET_VFS_CONNECTION,
    };
    ENV_REGISTER_PROGRAM_ENVIRONMENT("VfsNet", VfsNetArgs, VfsNetEnvs);

    const char* VfsRamFsArgs[] = {
    };
    const char* VfsRamFsEnvs[] = {
            "ROOTFS=ramdisk0,0 / ext4 0",
            _VFS_FILESYSTEM_BACKEND"=server:"RAM_FS_VFS_CONNECTION,
    };
    ENV_REGISTER_PROGRAM_ENVIRONMENT("VfsRamFs", VfsRamFsArgs, VfsRamFsEnvs);

    const char* SmbdEnvs[] = {
            _VFS_FILESYSTEM_BACKEND"=client:"RAM_FS_VFS_CONNECTION,
            _VFS_NETWORK_BACKEND"=client:"NET_VFS_CONNECTION,
    };
    ENV_REGISTER_VARS("Smbd", SmbdEnvs);

    const char* DhcpcdEnvs[] = {
#if defined(ROOTFS_SDCARD) && defined(__arm__)
            _VFS_FILESYSTEM_BACKEND"="RUMPFS_CLIENT_FS_BACKEND":"SDCARD_FS_VFS_CONNECTION,
#else
            _VFS_FILESYSTEM_BACKEND"="RUMPFS_CLIENT_FS_BACKEND":"RAM_FS_VFS_CONNECTION,
#endif
            _VFS_NETWORK_BACKEND"=client:"NET_VFS_CONNECTION,
    };

    const char* DhcpcdArgs[] = {
            "-4",
            "-f", "/etc/dhcpcd.conf"
    };

    fprintf(stderr,
            "[ENV] Used DHCP client daemon configuration from "
            WHITE "%s" NC ":/etc/dhcpcd.conf\r\n",
            RootFsDevice);

    ENV_REGISTER_PROGRAM_ENVIRONMENT("Dhcpcd", DhcpcdArgs, DhcpcdEnvs);

    envServerRun();

    return EXIT_SUCCESS;
}
