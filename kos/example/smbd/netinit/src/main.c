#include <kos_net.h>

int main(void)
{
    /* Initialisation of network interface "en0". */
    if (!wait_for_iface(NULL, IWF_IP4 | IWF_GW4, DEFAULT_TIMEOUT))
    {
        perror("can not init network");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
