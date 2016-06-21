#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

/*本函数被调用时，说明父进程接收到SIGCHLD信号，有子进程退出*/
void sigchld_handler(int sig)
{
	int state;
	printf("Catch SIGCHLD.\n");
}

int main()
{
	pid_t pid1;
    pid_t pid2;
	signal(SIGCHLD, sigchld_handler);//设置信号处理函数
	//创建子进程
	if((pid1 = fork()) < 0) {
		//创建出错
        printf("create process1 error\n");
	}
	else if(pid1 == 0) {
        if((pid2=fork()) < 0) {
            printf("create process2 error\n");
        }
        else if(pid2 == 0) {
            printf("pid2 = %d\n", getpid());
            exit(0);
        }
        wait(NULL);
        printf("pid1 = %d\n", getpid());
		exit(0);//子进程退出
	}
	else{
		pause();
	}
    wait(NULL);
    printf("parent pid = %d\n", getpid());
	exit(0);
}
