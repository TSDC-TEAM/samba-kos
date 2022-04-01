#ifndef SAMBA_KOSPROXYSERVER_H
#define SAMBA_KOSPROXYSERVER_H

#include "event2/event_struct.h"
#include "file/KOSDumpWriter.h"


class KOSProxyServer{

public:
    KOSProxyServer();
    ~KOSProxyServer();

    bool run(int portListen, int portRedirect);

private:

    static void invokeListenerCb(struct evconnlistener *listener, evutil_socket_t fd,
                                 struct sockaddr *sa, int socklen, void *user_data);
    static void invokeConnEventCb(struct bufferevent *bev, short events, void *user_data);
    static void invokeWriteCb(struct bufferevent *bev, void *user_data);
    static void inwokeReadCb(struct bufferevent *bev, void *user_data);

    void connEventCb(struct bufferevent *bev, short events);
    void writeCb(struct bufferevent *bev);
    void readCb(struct bufferevent *bev);
    void listenerCb(evutil_socket_t fd, struct sockaddr *sa, int socklen);

    struct event_base *base;
    struct evconnlistener *listener;
    struct bufferevent *bevClient;
    struct bufferevent *bevEndpoint;

    int portEndpoint;
    KOSDumpWriter writer;

};

#endif //SAMBA_KOSPROXYSERVER_H
