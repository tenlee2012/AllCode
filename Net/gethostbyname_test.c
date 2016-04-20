#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>


int main(int argc, char **argv)
{
    int i, sockfd;
    struct hostent *host;
    struct sockaddr_in serv_addr;

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("gethostbyname error\n");
        exit(0);
    }

    printf("official name: %s\n\n", host->h_name);
    printf("address length: %d bytes\n\n", host->h_length);

    printf("host name alias: \n");
    for (i = 0; host->h_aliases[i]; i++) {
        printf("%s\n", host->h_aliases[i]);
    }
    printf("\naddress list: \n");

    for (i = 0; host->h_addr_list[i]; i++) {
        /* h_addr_list[i]指向in_addr类型 */
        serv_addr.sin_addr = *((struct in_addr *)host->h_addr_list[i]);
        const char *ip = inet_ntoa(serv_addr.sin_addr);
        printf("%s\n", ip);
    }

    /*
    for (i = 0; host->h_addr_list[i]; i++) {
        if ((sockfd = socket(AF_INET, SOCK_STREAM,0)) == -1) {
            printf("socket error\n");
            exit(0);
        }
        // 先清零，然后用struct sockaddr_in来填值
        bzero(&serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(SERVPORT);
        /* h_addr_list[i]指向in_addr类型 *//*
        serv_addr.sin_addr = *((struct in_addr *)host->h_addr_list[i]);
        const char *ip = inet_ntoa(serv_addr.sin_addr);
        printf("connect to %s  ", ip);

        // 系统调用的时候，把sockaddr_in转换成sockaddr
        if (connect(sockfd, (struct sockaddr *)&serv_addr, \
                    sizeof(struct sockaddr)) == -1) {
            printf("error\n");
            exit(0);
        }
        printf("success\n");
    }
    */
    return 0;
}
