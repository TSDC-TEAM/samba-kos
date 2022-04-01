#include <network/KOSClient.h>
#include <file/KOSSMBDumpReader.h>


int main() {
    KOSSMBDumpReader::Params rp{
        .path = "./dump.bin"
    };
    KOSSMBDumpReader r(rp);
    if (!r.run()) {
        perror("Error while reader init");
        exit(EXIT_FAILURE);
    }

    KOSClient::Params cp{
        .serverPort = 1490,
        .reader = r
    };
    KOSClient c(cp);
    if (!c.run()) {
        perror("Error while client init");
        exit(EXIT_FAILURE);
    }

    return 0;
}