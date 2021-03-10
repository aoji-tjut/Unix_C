#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void DealSignal()
{
    puts("Alarm Signal");
}

int main()
{
    signal(SIGALRM, DealSignal);

    struct itimerval itv;

    //it_value递减为0时 it_interval赋值给it_value
    itv.it_interval.tv_sec = 0;
    itv.it_interval.tv_usec = 500000;

    //初相位 时间递减
    itv.it_value.tv_sec = 2;
    itv.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &itv, NULL);     //使用itv定时 误差小

    while(1)
    {
        puts("-----");
        pause();
    }

    return 0;
}
