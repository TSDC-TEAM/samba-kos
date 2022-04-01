#include <netinet/in.h>
#include <algorithm>
#include <iterator>
#include "KOSSMBDumpReader.h"


KOSSMBDumpReader::KOSSMBDumpReader(Params &params) : p(params) {

}

KOSSMBDumpReader::~KOSSMBDumpReader() {

}

bool KOSSMBDumpReader::run() {
    f.open(p.path, std::ios::in);
    if (f.bad()) {
        return false;
    }

    return true;
}

bool KOSSMBDumpReader::readNext(std::vector<uint8_t> &v) {
    uint32_t nextSize = 0;
    uint32_t nextSizeReal = 0;
    f.read((char *)&nextSize, 4);
    nextSizeReal = htonl(nextSize);
    v = {};
    v.reserve(nextSize + 4);
    std::copy_n((char *)&nextSize, 4, std::back_inserter(v));
    std::copy_n(std::istream_iterator<uint8_t>(f), nextSizeReal, std::back_inserter(v));
    return true;
}

