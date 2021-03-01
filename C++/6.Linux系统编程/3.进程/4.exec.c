#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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

        execlp("ls", "ls", "-l", NULL);     //运行ls可执行文件 ls -l 切换到新的进程映像 pid不变 执行成功不会返回
        perror("execlp");
        exit(-1);
    }

    wait(NULL);     //等待子进程结束

    puts("End");

    return 0;
}
