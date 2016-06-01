#include"server.h"
#include"sockutil.h"
#include"socklink.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<sys/signal.h>
#include<sys/select.h>

int sockFd;
pthread_mutex_t linkLock = PTHREAD_MUTEX_INITIALIZER;
void sigint_handler(int sig)
{
	close(sockFd);
	printf("\nConnection has closed.\n");
	exit(0);
}

void* commWithClient(void* arg)
{
	char buf[BUFSIZE] = {0};
    char msg[BUFSIZE] = {0};
	char* strWelcome="欢迎来到聊天室\n";
	int n, ret, sock = (int)arg;
	pSockEle p, tmp=0;
	send(sock, strWelcome, strlen(strWelcome), 0);
	while(1)
	{
		while((n=recv(sock, buf, BUFSIZE,0)) > 0)
		{
			pthread_mutex_lock(&linkLock);
			for(p=linkHead; p!=NULL; p=p->next)
			{
				printf("send to %d\n",p->sock);
                sprintf(msg, "%d say: %s", p->sock, buf);
				if((ret=send(p->sock, msg, strlen(msg), 0)) < n)
						tmp = p;
			}
			if(tmp != 0)
			{
				printf("error:%s.\n", strerror(errno));
				linkDelete(tmp->sock);
				pthread_cancel(tmp->tid);
				tmp=0;
			}
			pthread_mutex_unlock(&linkLock);
		}		
		if(n < 0)
			errexit("recv err");
	}
}
int main(int argc,char* argv[])
{
	int newFd,err;
	unsigned int alen;
	struct sockaddr_in addr;
	pthread_t tid;
	char IPBuf[16];
	if(argc != 2)
		errexit("Usage:%s port.\n",argv[0]);
	sockFd = passiveSock(argv[1], "tcp", QLEN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGINT, sigint_handler);
	while(1)
	{
		newFd = accept(sockFd, (struct sockaddr*)&addr, &alen);
        //创建线程,参数为新线程标识符,线程属性类型变量,函数指针即线程要执行的代码,指向线程参数的指针
		err = pthread_create(&tid, NULL, commWithClient, (void*)newFd);
		pthread_mutex_lock(&linkLock);
		linkInsert(newFd, tid);
		pthread_mutex_unlock(&linkLock);
		if(err != 0)
			errexit("pthread create err");
        printf("一个新用户进来了%s",inet_ntop(AF_INET,&(addr.sin_addr.s_addr),IPBuf,16));
        int port = ntohs(addr.sin_port);
        printf(":%d", port);
        printf("\n");
	}
}
