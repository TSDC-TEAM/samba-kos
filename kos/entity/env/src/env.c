#include <env/env.h>
#include <stdlib.h>

#define ROOT "ramdisk0"

int main(__attribute__((unused)) int argc, __attribute__((unused)) char** argv)
{
    const char* vfs_entity_envs[] = { "ROOTFS=" ROOT " / ext2 0" };
    const char* vfs_entity_args[] = { "-f", "fstab" };
    ENV_REGISTER_PROGRAM_ENVIRONMENT("VfsEntity", vfs_entity_args, vfs_entity_envs);

    envServerRun();

    return EXIT_SUCCESS;
}
