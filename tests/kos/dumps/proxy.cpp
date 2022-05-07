#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "network/KOSProxyServer.h"


int main() {
    std::clog << "Dumper is starting\n";

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