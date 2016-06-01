#ifndef _DEFS_H_
#define _DEFS_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>
#define BUFSIZE 30

int	errexit(const char *format, ...);
int passiveSock(const char *service, const char *transport, int qlen);
int connectSock(const char *host, const char *service, const char *transport );

#endif

