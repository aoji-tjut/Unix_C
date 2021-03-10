#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//int kill(pid_t pid, int sig) 给指定进程发送指定信号
//int raise(int sig) 给当前进程或线程发送指定信号
//unsigned int alarm(unsigned int seconds) 经过seconds秒后给当前进程发送SIGALRM信号
//int pause() 阻塞进程 等待被一个信号打断
//void abort() 给当前进程发送SIGABRT信号

void DealSignal(int s)
{
    switch(s)
    {
        case 1:
            puts("Kill Signal");
            break;
        case 2:
            puts("Raise Signal");
            break;
        case SIGALRM:
            puts("Alarm Signal");
            break;
        case SIGABRT:
            puts("Abort Signal");
            break;
    }
}

int main()
{
    signal(1, DealSignal);
    signal(2, DealSignal);
    signal(SIGALRM, DealSignal);
    signal(SIGABRT, DealSignal);

    kill(getpid(), 1);
    raise(2);

    for(int i = 0; i < 5; i++)
    {
        puts("-----");
        alarm(1);   //设置1秒闹钟信号
        pause();    //等待信号
    }

    abort();

    return 0;
}
