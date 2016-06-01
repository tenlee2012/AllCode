#ifndef SOCKLINK_H
#define SOCKLINK_H
#include<pthread.h>

typedef struct SockEle{
	void* next;
	int sock;
	pthread_t tid;
}*pSockEle;

extern pSockEle linkHead,linkTail;
void linkInsert(int sock, pthread_t tid);
void linkDelete(int sock);
void linkPrint(void);
int linkGetSize(void);

#endif//SOCKLINK_H
