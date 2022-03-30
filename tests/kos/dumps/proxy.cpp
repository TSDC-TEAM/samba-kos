#include <cstdio>
#include <cstdlib>
#include "network/KOSProxyServer.h"

int main() {
    KOSProxyServer s;

    if (!s.run(445, 1490)) {
        perror("Error while init");
        exit(EXIT_FAILURE);
    }

    return 0;
}