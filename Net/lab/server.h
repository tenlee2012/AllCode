#ifndef SERVER_H
#define SERVER_H

#define SERV_PORT "8888"

struct addrItem {
    struct sockaddr_in addr;
    struct addrItem× next;
};

#endif
