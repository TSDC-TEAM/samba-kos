#ifndef SAMBA_KOSDUMPWRITER_H
#define SAMBA_KOSDUMPWRITER_H

#include <string>
#include <fstream>


class KOSDumpWriter {

public:

    struct Params {
        bool sepFiles;
        std::string dirName;
    };

    KOSDumpWriter();
    ~KOSDumpWriter();

    bool init(Params &p);
    int dump(void *data, int datalen);

private:

    Params params;
    std::fstream file;

};


#endif //SAMBA_KOSDUMPWRITER_H
