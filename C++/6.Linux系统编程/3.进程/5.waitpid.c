#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    puts("Begin");

    pid_t pid_arr[3] = {0};
    for(int i = 0; i < 3; i++)  //fork三次
    {
        pid_arr[i] = fork();
        if(pid_arr[i] == 0)
        {
            printf("Child %d begin\n", getpid());
            sleep(3 - i);
            printf("Child %d end\n", getpid());
            exit(i + 1);
        }
    }

    int status;
    for(int i = 0; i < 3; i++)  //waitpid三次
    {
        pid_t pid = waitpid(pid_arr[2 - i], &status, 0);    //(阻塞/非阻塞)等待指定子进程(组)终止 回收子进程 获取子进程状态 返回子进程pid
        if(pid == -1)
        {
            perror("waitpid");
            exit(-1);
        }

        if(WIFEXITED(status))   //正常终止
        {
            printf("Waitpid: pid = %d, normal termination, exit num is %d.\n", pid, WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status)) //异常终止(信号终止)
        {
            printf("Waitpid: pid = %d, abnormal termination, signal num is %d.\n", pid, WTERMSIG(status));
        }
    }

    puts("End");

    return 0;
}
