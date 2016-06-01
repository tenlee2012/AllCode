#include"server.h"
#include"msg.h"

//UDP服务器端套接字
int    sockFd;
//地址链表
struct addrItem* addrHead;
struct addrItem* addrTail;
//函数声明
struct addrItem* createNewAddrItem(struct sockaddr_in* addr);
int broadcastMsg(struct msg* msg);
//主线程
int main(int argc,char* argv[])
{
	//计数
	int n;
	//IP字符串转换缓冲区
	char addrBuf[16];
	//套接字用
	socklen_t slen;
	//消息及账户格式
	struct msg* pMsg;
	if(argc != 2)
		errexit("USAGE:%s port.\n", argv[0]);
	sockFd = passiveSock(argv[1], "udp", 0);
	slen = sizeof(struct sockaddr_in);

	while(1)
	{		
		pMsg = buildMsg("");
		if((n = recvfrom(sockFd, pMsg->content, MSG_LEN, 0,
				(struct sockaddr*)&pMsg->addr, &slen)) < 0)
			errexit("recvfrom error");
		inet_ntop(AF_INET, (void *)&pMsg->addr.sin_addr, addrBuf, 16);
		printf("来自%s(%d)的消息：%s",
				addrBuf,ntohs(pMsg->addr.sin_port), pMsg->content);
		createNewAddrItem(&pMsg->addr);
		broadcastMsg(pMsg);	
		memset(&pMsg,0,sizeof(pMsg));	
	}
}
//保存地址 
struct addrItem* createNewAddrItem(struct sockaddr_in* addr)
{
	struct addrItem* ai=(struct addrItem*)malloc(sizeof(struct addrItem));
	struct addrItem* p;
	if(addr == NULL)
		return NULL;
	for(p = addrHead; p!=NULL; p=p->next)
	{
		if(p->addr.sin_addr.s_addr==addr->sin_addr.s_addr &&
		                     p->addr.sin_port==addr->sin_port)
		{
			//已保存该地址，直接返回
			return p; 
		}
	}
	//未保存该地址，加入地址列表中 
	ai=(struct addrItem*)malloc(sizeof(struct addrItem));
	ai->addr = *addr;
	ai->next = NULL;
	if(addrHead == NULL)
		addrHead = addrTail = ai;
	else
	{
		addrTail->next = ai;
		addrTail = ai;
	}
	return ai;
}

//群发消息
int broadcastMsg(struct msg* msg)
{
	struct addrItem* p,*ptmp;
    char content[1000];
	char addrBuf[16];

	if(msg == NULL)
		return -1;

	inet_ntop(AF_INET, (void *)&msg->addr.sin_addr, addrBuf, 16);
    sprintf(content, "来自%s(%d)发送的消息：%s",
			    addrBuf,ntohs(msg->addr.sin_port), msg->content);
    strcpy(msg->content, content);

	for(p=addrHead; p!=NULL; p=p->next)
	{
		sendto(sockFd, msg->content, sizeof(struct msg), 0,
				(struct sockaddr*)&p->addr, sizeof(struct sockaddr));
	}
	return 0;	
}
