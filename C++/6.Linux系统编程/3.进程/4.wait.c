#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    puts("Begin");

    for(int i = 0; i < 3; i++)  //fork三次
    {
        pid_t pid = fork();
        if(pid == 0)
        {
            printf("Child %d begin\n", getpid());
            sleep(i + 1);
            printf("Child %d end\n", getpid());
            exit(i + 1);
        }
    }

    int status;
    for(int i = 0; i < 3; i++)  //wait三次
    {
        pid_t pid = wait(&status);  //阻塞等待一个子进程终止 回收子进程 获取子进程状态 返回子进程pid
        if(pid == -1)
        {
            perror("wait");
            exit(-1);
        }

        if(WIFEXITED(status))   //正常终止
        {
            printf("Wait: pid = %d, normal termination, exit num is %d.\n", pid, WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status)) //异常终止(信号终止)
        {
            printf("Wait: pid = %d, abnormal termination, signal num is %d.\n", pid, WTERMSIG(status));
        }
    }

    puts("End");

    return 0;
}
