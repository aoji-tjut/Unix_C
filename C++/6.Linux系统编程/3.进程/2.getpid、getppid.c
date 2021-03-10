#include <stdio.h>
#include <unistd.h>

//进程号依次向下使用 1、2、3...

int main()
{

    pid_t pid = getpid();   //进程id
    pid_t ppid = getppid(); //父进程id

    printf("pid = %d\n", pid);
    printf("ppid = %d\n", ppid);

    getchar();
    return 0;
}
