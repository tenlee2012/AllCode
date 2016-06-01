#include"client.h"
#include"sockutil.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/signal.h>
#include<sys/select.h>

int sockFd;

void sigint_handler(int sig)
{
	close(sockFd);
	printf("\nConnection has closed.\n");
	exit(0);
}

int main(int argc,char* argv[])
{
	int n;
	fd_set oset,nset;
	char buf[BUFSIZE];
	if(argc!=3)
		errexit("Usage:%s hostname port.\n",argv[0]);
	sockFd=connectSock(argv[1],argv[2],"tcp");
	FD_ZERO(&oset);
	FD_SET(STDIN_FILENO,&oset);
	FD_SET(sockFd,&oset);
	nset=oset;
	signal(SIGPIPE,SIG_IGN);
	signal(SIGINT,sigint_handler);
	while(1)
	{
		if(select(4,&nset,NULL,NULL,0)<0)
				errexit("select err");
		if(FD_ISSET(sockFd,&nset))
		{
			n=recv(sockFd,buf,BUFSIZE,0);
			if(n<0)
				errexit("recv err");
			if(n>0 && write(STDOUT_FILENO,buf,n)!=n)
					errexit("write err");
		}
		if(FD_ISSET(STDIN_FILENO,&nset))
		{
			fgets(buf,BUFSIZE,stdin);
			if((n=send(sockFd,buf,strlen(buf),0))<0)
				errexit("send err");
		}
		nset=oset;
	}
}
