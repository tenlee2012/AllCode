#include "sockutil.h"

int main() {
    int sock, serverSock, clientSock;
    struct sockaddr_in addr;
    char buf[BUFSIZE] = {0};
    int n;
    pid_t pid;
    socklen_t len = sizeof(struct sockaddr_in);
    /*在本部分调用passiveSock接口，为服务器分配套接字*/
    sock = passiveSock("8890", "tcp", 10);
    if((pid=fork())< 0) {
        errexit("fork error");
    } else if (pid == 0) {
        sleep(2);
        /*在本部分调用connectSock接口为客户端分配套接字*/
        clientSock = connectSock("localhost", "8890", "tcp");
        /*循环调用recv接口接收数据*/
        while((n=recv(clientSock, buf, BUFSIZE, 0)) > 0) {
            if(write(STDOUT_FILENO, buf, n) < 0)
                errexit("write error");
        }
        printf("client get data: %s\n", buf);
        if (n < 0) 
            errexit("recv error");
    } else {
        /*调用accept将服务器置于阻塞状态*/
        serverSock = accept(sock, (struct sockaddr*)&addr, &len);
        /*按实验要求输出子进程的id号*/
        sprintf(buf, "新进程的id号为%d\n", pid);
        /*调用send接口发送数据*/
        send(serverSock, buf, sizeof(buf), 0);
        /*调用close接口结束通信*/
        close(serverSock);
        wait(NULL);
    }
    exit(0);
}
