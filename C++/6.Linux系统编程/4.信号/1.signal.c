#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//信号是软件中断
//信号的响应依赖于中断
//信号从kernel态到user态的过程中响应 位图进行按位与操作mask&pending mask负责响应信号 pending负责接收信号 
//信号会打断阻塞的系统调用
//可重入函数：第一次调用为结束第二次调用开始 所有的系统调用都是可重入的 一部分函数..._r()是可重入的

//typedef void (*sighandler_t)(int);
//sighandler_t signal(int signum, sighandler_t handler) = void (*signal(int signum, void (*pfun)(int)))(int)

void fun()
{
    puts("|");
}

//终端运行
int main()
{
    signal(SIGINT, fun);    //对中断信号ctrl+c进行fun操作

    for(int i = 0; i < 10; i++)
    {
        puts("-");
        sleep(1);
    }

    return 0;
}
