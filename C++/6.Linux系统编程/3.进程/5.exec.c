#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//exec用于执行一个进程 执行exec后切换到新的进程映像 并不创建新的进程 pid不变 成功不返回 失败返回-1
//system函数执行原理：execl("/bin/sh", "sh", "-c", "......", NULL)

int main()
{
    puts("Begin");

    fflush(NULL);   //exec函数族类似fork 使用前要刷新所有流

    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork");
    }

    if(pid == 0)
    {

        execlp("ls", "ls", "-l", NULL);     //运行ls可执行文件 第二个参数从argv[0]开始传入 NULL结束
        perror("execlp");
        exit(-1);
    }

    wait(NULL);//父进程等待子进程结束

    puts("End");

    return 0;
}
