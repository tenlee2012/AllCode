#ifndef SOCKUTIL_H
#define SOCKUTIL_H

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include<stdarg.h>
#include<unistd.h>
#include<errno.h>

#ifndef INADDR_NONE
#define INADDR_NONE 0xFFFFFFFF
#endif

int connectSock(char* host, char* service, char* protocol);
int passiveSock(char* service, char* protocol, int qlen);
void errexit(char* fmt,...);

#endif
