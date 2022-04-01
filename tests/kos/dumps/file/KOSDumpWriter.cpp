#include "KOSDumpWriter.h"


KOSDumpWriter::KOSDumpWriter() {

}

KOSDumpWriter::~KOSDumpWriter() {

}

bool KOSDumpWriter::init(KOSDumpWriter::Params &p) {
    params = p;
    if (p.sepFiles) {
        ;
    } else {
        std::string path = p.dirName;
        path.append("/dump.bin");
        file.open(path, std::ios::binary | std::ios::out);
        if (file.bad()) {
            return false;
        }
    }

    return true;
}

bool KOSDumpWriter::isActive() {
    return params.sepFiles ? true : !file.bad();
}

int KOSDumpWriter::dump(void *data, int datalen) {
    static int i = 0;

    if (!params.sepFiles) {
        file.write((char *)data, datalen);
        file.flush();
        return 0;
    }

    std::string path = params.dirName;
    path.append("/");
    path.append(std::to_string(i++));

    std::ofstream myfile;
    myfile.open(path, std::ios::binary);
    myfile.write((char *)data, datalen);
    myfile.close();

    return 0;
}
