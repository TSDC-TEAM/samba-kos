#ifndef SAMBA_KOSCLIENT_H
#define SAMBA_KOSCLIENT_H

#include <string>
#include "event2/event_struct.h"
#include <file/KOSSMBDumpReader.h>


class KOSClient {

public:

    struct Params {
        int serverPort;
        KOSSMBDumpReader &reader;
    };

    explicit KOSClient(Params &params);
    ~KOSClient();

    bool run();

private:

    static void invokeConnEventCb(struct bufferevent *bev, short events, void *user_data);
    static void invokeWriteCb(struct bufferevent *bev, void *user_data);
    static void inwokeReadCb(struct bufferevent *bev, void *user_data);

    void connEventCb(struct bufferevent *bev, short events);
    void writeCb(struct bufferevent *bev);
    void readCb(struct bufferevent *bev);

    void writeNext();

    Params p;
    struct event_base *base;
    struct bufferevent *bevServer;
    char sessionID[8];

};


#endif //SAMBA_KOSCLIENT_H
