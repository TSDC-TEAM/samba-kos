#ifndef SAMBA_KOSSMBDUMPREADER_H
#define SAMBA_KOSSMBDUMPREADER_H

#include <fstream>
#include <vector>
#include <string>


class KOSSMBDumpReader {

public:

    struct Params {
        std::string path;
    };

    KOSSMBDumpReader(Params &p);
    ~KOSSMBDumpReader();

    bool run();
    bool readNext(std::vector<uint8_t> &v);

private:

    Params p;
//    std::fstream f;
    int fd;

};


#endif //SAMBA_KOSSMBDUMPREADER_H
