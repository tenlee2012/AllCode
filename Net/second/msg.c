#include "msg.h"

//构建消息
struct msg* buildMsg(char *cont) {
    struct msg* pMsg;
    pMsg = (struct msg*)malloc(sizeof(struct msg));
    if(pMsg == NULL) return NULL;
    strcpy(pMsg->content, cont);
    memset(&pMsg->addr, 0, sizeof(struct sockaddr_in));
    pMsg->next = NULL;
    return pMsg;
}
//卸载消息
int freeMsg(struct msg* pMsg) {
    if(pMsg != NULL) {
        free(pMsg);
        pMsg = NULL;
        return 0;
    }
    return -1;
}
//构建消息队列
struct msgQ* buildMsgQ(void) {
    struct msgQ* pMsgQ = (struct msgQ*)malloc(sizeof(struct msgQ));
    if(pMsgQ == NULL) return NULL;
    pMsgQ->head = NULL;
    pMsgQ->tail = NULL;
    return pMsgQ;
}
//卸载消息队列
int freeMsgQ(struct msgQ* pMsgQ) {
    struct msg* pMsg, *tmp;
    if(pMsgQ != NULL) {
        pMsg = pMsgQ->head;
        while(pMsg != NULL) {
            tmp = pMsg->next;
            free(pMsgQ);
            pMsg = tmp;
        }
        free(pMsgQ);
        pMsgQ = NULL;
        return 0;
    }
    return -1;
}
//获取消息队列头部消息
struct msg* getFromMsgQ(struct msgQ* pMsgQ) {
    struct msg* pHead;
    if(pMsgQ == NULL) return NULL;
    if(pMsgQ->head == NULL) return NULL;
    pHead = pMsgQ->head;
    if(pMsgQ->head == pMsgQ->tail)
        pMsgQ->head = pMsgQ->tail = NULL;
    else
        pMsgQ->head = pMsgQ->head->next;
    return pHead;
}
//在消息队列尾部加入消息队列
int appToMsgQ(struct msgQ* pMsgQ, struct msg* pMsg) {
    if(pMsgQ == NULL || pMsg == NULL) return -1;
    if(pMsgQ->head == NULL)
        pMsgQ->head = pMsgQ->tail = pMsg;
    pMsgQ->tail->next = pMsg; //此处应有问题
    pMsgQ->tail = pMsg;
}


