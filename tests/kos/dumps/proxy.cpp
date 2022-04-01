#include <cstdio>
#include <cstdlib>
#include <memory>
#include "network/KOSProxyServer.h"


int main() {
    KOSDumpWriter::Params wp{
        .sepFiles = false,
        .dirName = "./"
    };
    KOSDumpWriter w;
    if (!w.init(wp)) {
        perror("Error while writer init");
    }

    KOSProxyServer::Params sp{
        .portEndpoint = 1490,
        .portClient = 445,
        .writer = w,
    };
    KOSProxyServer s(sp);
    if (!s.run()) {
        perror("Error while init");
        exit(EXIT_FAILURE);
    }

    return 0;
}