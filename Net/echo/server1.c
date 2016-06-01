#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include<stdarg.h>
#include <netdb.h>

const int EPOLL_SIZE=5000;
const int EVENT_ARR=5000;
const int PORT=8003;
const int BUF_SIZE=5000;
const int BACK_QUEUE=100;
void setnoblock(int sockFd)         //设置非阻塞模式
{
    int opt;
    if((opt=fcntl(sockFd,F_GETFL))<0)  //获取原来的flag;
    {
        printf("GET FL failed!\n");
        exit(-1);
     }
    opt|=O_NONBLOCK;
    if(fcntl(sockFd,F_SETFL,opt)<0)
    {
        printf("SET FL failed!\n");
        exit(-1);
    }
}

int main()
{
    int serverFd;
    serverFd=socket(AF_INET,SOCK_STREAM,0); //创建服务器fd
    setnoblock(serverFd);                   //设置为非阻塞模式

    //创建epoll，并将serverFd放入监听队列
    int epFd=epoll_create(EPOLL_SIZE);
    struct epoll_event ev,evs[EVENT_ARR];
    ev.data.fd=serverFd;
    ev.events=EPOLLIN|EPOLLET;
    epoll_ctl(epFd,EPOLL_CTL_ADD,serverFd,&ev);

    //绑定服务器端口
    struct sockaddr_in serverAddr;
    socklen_t serverlen=sizeof(struct sockaddr_in);
    serverAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    serverAddr.sin_port=htons(PORT);
    if(bind(serverFd,(struct sockaddr*)&serverAddr,serverlen))
    {
        printf("BIND failed!\n");
        exit(-1);
    }

    //打开监听
    if(listen(serverFd,BACK_QUEUE))
    {
        printf("Listen failed!\n");
        exit(-1);
    }

    //服务处理
    int clientFd;
    struct sockaddr_in clientAddr;
    socklen_t clientlen;
    char buf[BUF_SIZE];
    while(1)
    {
        //等待epoll事件到来，最多取EVENT_ARR个事件
        int nfds=epoll_wait(epFd,evs,EVENT_ARR,-1);
        //处理事件
        for(int i=0;i<nfds;i++)
        {
            if(evs[i].data.fd==serverFd&&evs[i].events&EPOLLIN)
            {
                //如果是serverFd，表明有新连接连入
                if((clientFd=accept(serverFd,(struct sockaddr*)&clientAddr,&clientlen))<0)
                {
                    printf("ACCEPT  failed\n");
                }
                printf("Connect from %s:%d\n",inet_ntoa(clientAddr.sin_addr),htons(clientAddr.sin_port));
                setnoblock(clientFd);
                //注册accept()到的连接
                ev.data.fd=clientFd;
                ev.events=EPOLLIN|EPOLLET;
                epoll_ctl(epFd,EPOLL_CTL_ADD,clientFd,&ev);
            }
            else if(evs[i].events&EPOLLIN)
            {
                //如果不是serverFd,则是client的可读
                printf("client can write!\n");
                if((clientFd=evs[i].data.fd)>0)
                {
                    //先进行试探性读取
                    int len=read(clientFd,buf,BUF_SIZE);
                    if(len>0)
                    {
                        //有数据可读,Echo写入
                        do{
                            if(write(clientFd,buf,len)<0)
                            {
                                printf("Write failed\n");
                            }
                            len=read(clientFd,buf,BUF_SIZE);
                        }while(len>0);
                    }
                    else if(len==0)
                    {
                        //触发了EPOLL事件，却没有读取，表示断线
                        printf("Client closed at %s\n",inet_ntoa(clientAddr.sin_addr));
                        epoll_ctl(epFd,EPOLL_CTL_DEL,clientFd,&ev);
                        close(clientFd);
                        evs[i].data.fd=-1;
                        break;
                    }
                    else if(len==EAGAIN)
                    {
                        printf("socket huan cun man le!\n");
                        continue;
                    }
                    else
                    {
                        //client读取出错
                        printf("Client read failed!\n");
                    }
                }
                else 
                    printf("other error!\n");
            }
        }
    }
    return 0;
}
