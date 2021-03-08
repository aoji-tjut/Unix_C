#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//int kill(pid_t pid, int sig) 给指定进程发送信号
//int raise(int sig) 给当前进程或线程发送信号
//unsigned int alarm(unsigned int seconds) 经过seconds秒后终止当前进程 不能实现多任务计时
//int pause() 阻塞进程 等待被一个信号打断

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

int main()
{
    signal(1, KillSignal);
    signal(4, RaiseSignal);
    signal(SIGALRM, AlarmSignal);

    kill(getpid(), 1);
    raise(4);

    while(1)
    {
        alarm(1);   //设置1秒闹钟信号
        puts("-----");
        pause();    //等待信号
    }

    return 0;
}
