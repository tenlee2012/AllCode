#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/select.h>
#include"client.h"
#include"sockutil.h"

int main(int argc,char* argv[])
{
	int ret, n;
	int sockFd;
	struct sockaddr_in servAddr;
	fd_set oset, nset;
	char strBuf[BUFSIZE];
	//UDP地址绑定到服务器
	if(argc != 3)
		errexit("USAGE:%s hostname port",argv[0]);

	sockFd = connectSock(argv[1], argv[2], "udp");
	//初始化fd_set对象
	FD_ZERO(&oset);
	FD_SET(STDIN_FILENO,&oset);
	FD_SET(sockFd,&oset);
	nset = oset;
	while(1)
	{
		ret = select(4, &nset, NULL, NULL, 0);
		if(FD_ISSET(sockFd, &nset))
		{
			memset(strBuf, 0, BUFSIZE);
			recv(sockFd, strBuf, BUFSIZE, 0);
			printf("%s", strBuf);
		}
		if(FD_ISSET(STDIN_FILENO, &nset))
		{
			fgets(strBuf, BUFSIZE, stdin);
			send(sockFd, strBuf, sizeof(strBuf), 0);
			memset(strBuf, 0, BUFSIZE);
		}
		nset = oset;
	}
    return 0;
}
