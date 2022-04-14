#include <netinet/in.h>
#include <algorithm>
#include <iterator>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cassert>
#include "KOSSMBDumpReader.h"


KOSSMBDumpReader::KOSSMBDumpReader(Params &params) : p(params) {

}

KOSSMBDumpReader::~KOSSMBDumpReader() {

}

bool KOSSMBDumpReader::run() {
    fd = open(p.path.c_str(), O_RDONLY, 0);
    if (0 > fd) {
        return false;
    }
//    f.open(p.path, std::ios::in);
//    if (f.bad()) {
//        return false;
//    }

    return true;
}

bool KOSSMBDumpReader::readNext(std::vector<uint8_t> &v) {
    uint32_t nextSize = 0;
    uint32_t nextSizeReal = 0;
//    f.read((char *)&nextSize, 4);
    read(fd, &nextSize, 4);
    nextSizeReal = htonl(nextSize);
    v = {};
    v.reserve(nextSize + 4);
    std::copy_n((char *)&nextSize, 4, std::back_inserter(v));

    char *buf = (char *) malloc(nextSizeReal);
    int r = read(fd, buf, nextSizeReal);
    if (r != nextSizeReal) {
        assert(0);
    }
    std::copy_n((char *)buf, nextSizeReal, std::back_inserter(v));

//    std::copy_n(std::istream_iterator<uint8_t>(f), nextSizeReal, std::back_inserter(v));
    return true;
}

