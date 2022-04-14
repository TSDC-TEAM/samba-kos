#include <cassert>
#include <cstring>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "KOSClient.h"
#include <utils/hex.h>
#include "event2/event.h"
#include "event2/listener.h"
#include "event2/bufferevent.h"
#include "event2/buffer.h"


KOSClient::KOSClient(KOSClient::Params &params) : p(params) {

}

KOSClient::~KOSClient() {

}

bool KOSClient::run() {
    base = event_base_new();
    if (!base) {
        return false;
    }

    struct sockaddr_in sin = {0};
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(p.serverPort);

    bevServer = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);
    if (!bevServer) {
        fprintf(stderr, "socket init failed\n");
        return false;
    }
    bufferevent_setcb(bevServer, KOSClient::inwokeReadCb,
                      KOSClient::invokeWriteCb,
                      KOSClient::invokeConnEventCb, this);
    bufferevent_enable(bevServer, EV_READ | EV_WRITE);

    int conRet = bufferevent_socket_connect(bevServer, (struct sockaddr*)&sin, sizeof(sin));
    if (0 > conRet) {
        fprintf(stderr, "connect failed\n");
        assert(0);
    }

    event_base_dispatch(base);

    return true;
}


void KOSClient::invokeConnEventCb(struct bufferevent *bev, short events, void *user_data) {
    ((KOSClient *)(user_data))->connEventCb(bev, events);
}

void KOSClient::invokeWriteCb(struct bufferevent *bev, void *user_data) {
    ((KOSClient *)(user_data))->writeCb(bev);
}

void KOSClient::inwokeReadCb(struct bufferevent *bev, void *user_data) {
    ((KOSClient *)(user_data))->readCb(bev);
}

void KOSClient::connEventCb(struct bufferevent *bev, short events) {
    if (events & BEV_EVENT_EOF) {
        printf("connection closed\n");
        bufferevent_free(bevServer);
    } else if (events & BEV_EVENT_ERROR) {
        printf("got an error on the connection: %s\n", strerror(errno));
        bufferevent_free(bevServer);
    } else if (events & BEV_EVENT_CONNECTED) {
        printf("got an error on the connection\n");
        writeNext();
    }
}

void KOSClient::writeCb(struct bufferevent *bev) {
    struct evbuffer *output = bufferevent_get_output(bev);
    if (evbuffer_get_length(output) == 0) {
        printf("flushed answer\n");
    }
}

void KOSClient::readCb(struct bufferevent *bev) {
    struct evbuffer *input = bufferevent_get_input(bev);

    size_t len = evbuffer_get_length(input);
    char *data;
    data = static_cast<char *>(malloc(len));
    evbuffer_remove(input, data, len);

    if (len > 64 + 4) {
        dumpHex(data + 4 + 16 + 16 + 8, 8);
        memcpy(sessionID, data + 4 + 16 + 16 + 8, 8);
    }

    writeNext();
}

void KOSClient::writeNext() {
    std::vector<uint8_t> v;
    p.reader.readNext(v);
    if (!v.empty()) {
        printf("Ok, my ses:\n");
        memcpy(v.data() + 4 + 16 + 16 + 8, sessionID, 8);
        dumpHex(v.data() + 4 + 16 + 16 + 8, 8);
        bufferevent_write(bevServer, v.data(), v.size());
        printf("write %zu bytes\n", v.size());
    } else {
        printf("Ok\n");
    }
}
