#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Main %d begin\n", getpid());

    for(int i = 0; i < 3; i++)
    {
        pid_t pid = fork();
        if(pid == 0)
        {

            printf("Child %d begin\n", getpid());
            sleep(2);
            printf("Child %d end\n", getpid());
            exit(0);
        }
    }

    int status;
    for(int i = 0; i < 3; i++)
    {
        pid_t pid = wait(&status);  //等待子进程结束
        printf("Wait: pid = %d, status = %d\n", pid, status);
    }

    printf("Main %d end\n", getpid());

    return 0;
}
