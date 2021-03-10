#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void DealSignal(int s)
{
    if(s == SIGINT)
    {
        for(int i = 0; i < 5; i++)
        {
            puts("SIGINT");
            sleep(1);
        }
    }

    if(s == SIGQUIT)
    {
        for(int i = 0; i < 5; i++)
        {
            puts("SIGQUIT");
            sleep(1);
        }
    }
}

//终端运行
int main()
{
    struct sigaction sa;
    sa.sa_handler = DealSignal;         //信号处理函数
    sigemptyset(&sa.sa_mask);           //信号屏蔽集合置空
    sigaddset(&sa.sa_mask, SIGINT);     //阻塞SIGINT信号
    sigaddset(&sa.sa_mask, SIGQUIT);    //阻塞SIGQUIT信号
    sa.sa_flags = 0;

    //sigaction可以避免函数重入
    sigaction(SIGINT, &sa, NULL);   //处理SIGINT信号
    sigaction(SIGQUIT, &sa, NULL);  //处理SIGQUIT信号

    while(1)
    {
        puts("-----");
        sleep(1);
    }

    return 0;
}
