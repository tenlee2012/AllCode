#include "sockutil.h"

int main() {
    int a = 1, b = 2;
    printf("%d\n", f1(a, b));
    int sock, serverSock, clientSock;
    struct sockaddr_in addr;
    char buf[BUFSIZE] = {0};
    int n;
    pid_t pid;
    socklen_t len = sizeof(struct sockaddr_in);
    sock = passiveSock("8899", "tcp", 10);
    if((pid=fork())< 0) {
        errexit("fork error");
    } else if (pid == 0) {
        sleep(2);
        clientSock = connectSock("localhost", "8899", "tcp");
        while((n=recv(clientSock, buf, BUFSIZE, 0)) > 0) {
            if(write(STDOUT_FILENO, buf, n) < 0)
                errexit("write error");
        }
        if (n < 0) 
            errexit("recv error");
    } else {
        serverSock = accept(sock, (struct sockaddr*)&addr, &len);
        sprintf(buf, "Child Pid = %d\n", pid);
        send(serverSock, buf, sizeof(buf), 0);
        close(serverSock);
        wait(NULL);
    }
    exit(0);
}
