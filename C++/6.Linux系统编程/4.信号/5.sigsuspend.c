#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void DealSignal()
{
    printf("|");
}

//终端运行 实现功能：每行打印结束后暂定在下一行行首 暂停时触发信号或上一行触发信号将会继续打印
int main()
{
    signal(SIGINT, DealSignal);

    sigset_t set, old_set, save_set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    sigprocmask(SIG_UNBLOCK, &set, &save_set);  //设置set非阻塞 保存之前状态save_set(未知)
    sigprocmask(SIG_BLOCK, &set, &old_set);     //设置set阻塞 保存之前状态old_set(非阻塞)

    while(1)
    {
        for(int i = 0; i < 5; i++)
        {
            printf("-");
            fflush(stdout);
            sleep(1);
        }

        printf("\n");

        sigsuspend(&old_set);   //进入old_set(非阻塞)状态后 马上进入到等待信号阶段 原子操作

        //sigsuspend相当于以下4行的原子操作
        //sigset_t temp_set;
        //sigprocmask(SIG_SETMASK, &old_set, &temp_set);
        //pause();
        //sigprocmask(SIG_SETMASK, &temp_set, NULL);
    }

    sigprocmask(SIG_SETMASK, &save_set, NULL);  //恢复save_set状态(未知)

    return 0;
}
