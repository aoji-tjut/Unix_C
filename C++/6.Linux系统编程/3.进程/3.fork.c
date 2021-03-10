#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//fork相当于复制了一份相同的进程 子进程从fork处继续执行
//父子进程读时共享写时复制 若只进行读操作则共用一份空间 若进行写操作谁写谁单独复制空间
//一般情况下父子进程之间互不影响 但父子进程共享文件描述符和mmap映射区
//fork后父子进程区别：fork返回值不同 pid不同 ppid不同 未决信号和文件锁不继承 资源利用率清零
//调度器调度策略决定哪个进程先运行

//init进程：即1号进程 是所有进程的祖先进程
//孤儿进程：父进程结束 子进程未结束 子进程成为孤儿进程 会被init进程接管
//僵尸进程：子进程结束 父进程未回收子进程pid 子进程成为僵尸进程 删除僵尸进程的唯一方法是终止其父进程 之后被init进程接管并自动调用wait

int main()
{
    printf("%d Begin\n", getpid());

    fflush(NULL);   //fork前最好要刷新所有流 避免缓冲区内容被fork复制

    //fork成功 父进程中返回子进程pid
    //fork成功 子进程中返回0
    //fork失败 返回-1
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork");
        exit(-1);
    }
    else if(pid == 0)   //子进程结束后要及时exit()
    {
        printf("This is child, pid = %d\n", getpid());
        printf("%d End\n", getpid());
        exit(0);
    }
    else
    {
        printf("This is parent, pid = %d\n", getpid());
    }

    printf("%d End\n", getpid());

    return 0;
}
