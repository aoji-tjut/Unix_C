#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//int kill(pid_t pid, int sig) 给指定进程发送指定信号
//int raise(int sig) 给当前进程或线程发送指定信号
//unsigned int alarm(unsigned int seconds) 经过seconds秒后给当前进程发送SIGALRM信号
//int pause() 阻塞进程 等待被一个信号打断
//void abort() 给当前进程发送SIGABRT信号

void KillSignal()
{
    puts("Kill Signal");
}

void RaiseSignal()
{
    puts("Raise Signal");
}

void AlarmSignal()
{
    puts("Alarm Signal");
}

void AbortSignal()
{
    puts("Abort Signal");
}

int main()
{
    signal(1, KillSignal);
    signal(4, RaiseSignal);
    signal(SIGALRM, AlarmSignal);
    signal(SIGABRT, AbortSignal);

    kill(getpid(), 1);
    raise(4);

    for(int i = 0; i < 5; i++)
    {
        puts("-----");
        alarm(1);   //设置1秒闹钟信号
        pause();    //等待信号
    }

    abort();

    return 0;
}
