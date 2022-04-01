#include <cstring>
#include <cstdlib>
#include <cassert>
#include "KOSProxyServer.h"
#include "event2/event.h"
#include "event2/listener.h"
#include "event2/bufferevent.h"
#include "event2/buffer.h"


KOSProxyServer::KOSProxyServer(Params &params) : p(params) {

}

KOSProxyServer::~KOSProxyServer() {

}

void KOSProxyServer::invokeListenerCb(struct evconnlistener *listener, evutil_socket_t fd,
                                      struct sockaddr *sa, int socklen, void *user_data) {
    ((KOSProxyServer *)(user_data))->listenerCb(fd, sa, socklen);
}

void KOSProxyServer::invokeConnEventCb(struct bufferevent *bev, short events, void *user_data) {
    ((KOSProxyServer *)(user_data))->connEventCb(bev, events);
}

void KOSProxyServer::invokeWriteCb(struct bufferevent *bev, void *user_data) {
    ((KOSProxyServer *)(user_data))->writeCb(bev);
}

void KOSProxyServer::inwokeReadCb(struct bufferevent *bev, void *user_data) {
    ((KOSProxyServer *)(user_data))->readCb(bev);
}

void KOSProxyServer::connEventCb(struct bufferevent *bev, short events) {
    if (events & BEV_EVENT_EOF) {
        printf("connection closed.\n");
        goto stop;
    } else if (events & BEV_EVENT_ERROR) {
        printf("got an error on the connection: %s\n", strerror(errno));
        goto stop;
    }

    return;

stop:
    bufferevent_free(bevEndpoint);
    bufferevent_free(bevClient);
}

void KOSProxyServer::writeCb(struct bufferevent *bev) {
    struct evbuffer *output = bufferevent_get_output(bev);
    if (evbuffer_get_length(output) == 0) {
        printf("flushed answer to %s\n", (bev == bevClient) ? "client" : "endpoint");
    }
}

void KOSProxyServer::readCb(struct bufferevent *bev) {
    struct evbuffer *input = bufferevent_get_input(bev);

    size_t len = evbuffer_get_length(input);
    char *data;
    data = static_cast<char *>(malloc(len));
    evbuffer_remove(input, data, len);

    if (bev == bevClient) {
        bufferevent_write(bevEndpoint, data, len);
        p.writer.dump(data, len);
    } else if (bev == bevEndpoint) {
        bufferevent_write(bevClient, data, len);
    } else {
        printf("something went wrong\n");
        assert(0);
    }

    free(data);
}

void KOSProxyServer::listenerCb(evutil_socket_t fd, struct sockaddr *sa, int socklen) {
    bevClient = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
    if (!bevClient) {
        fprintf(stderr, "error constructing bufferevent!\n");
        event_base_loopbreak(base);
        assert(0);
    }
    bufferevent_setcb(bevClient, KOSProxyServer::inwokeReadCb,
                                 KOSProxyServer::invokeWriteCb,
                                 KOSProxyServer::invokeConnEventCb, this);
    bufferevent_enable(bevClient, EV_WRITE | EV_READ);

    struct sockaddr_in sin = {0};
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(p.portEndpoint);

    bevEndpoint = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);
    if (!bevEndpoint) {
        fprintf(stderr, "socket init failed\n");
        assert(0);
    }
    bufferevent_setcb(bevEndpoint, KOSProxyServer::inwokeReadCb,
                                   KOSProxyServer::invokeWriteCb,
                                   KOSProxyServer::invokeConnEventCb, this);
    bufferevent_enable(bevEndpoint, EV_READ | EV_WRITE);

    int conRet = bufferevent_socket_connect(bevEndpoint, (struct sockaddr*)&sin, sizeof(sin));
    if (0 > conRet) {
        fprintf(stderr, "connect failed\n");
        assert(0);
    }
}

bool KOSProxyServer::run() {
    base = event_base_new();
    if (!base) {
        return false;
    }

    struct sockaddr_in sin = {0};
    sin.sin_family = AF_INET;
    sin.sin_port = htons(p.portClient);

    listener = evconnlistener_new_bind(base, KOSProxyServer::invokeListenerCb, (void *)this,
                                       LEV_OPT_REUSEABLE|LEV_OPT_CLOSE_ON_FREE, -1,
                                       (struct sockaddr *)&sin,
                                       sizeof(sin));
    if (!listener) {
        return false;
    }

    event_base_dispatch(base);

    return true;
}
