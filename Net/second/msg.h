#ifndef MSG_H
#define MGS_H

#include "sockutil.h"
#define MSG_LEN 100 //最大的消息长度

struct msg {
    char content[MSG_LEN];
    struct sockaddr_in addr;
    struct msg* next;
};

struct msgQ {
    struct msg* head;
    struct msg* tail;
};

struct msg* buildMsg(char *cont);
int freeMsg(struct msg* pMsg);
struct msgQ* buildMsgQ(void);
int freeMsgQ(struct msgQ* pMsgQ);
struct msg* getFromMsgQ(struct msgQ* pMsgQ);
int appToMsgQ(struct msgQ* pMsgQ, struct msg* pMsg);

#endif
