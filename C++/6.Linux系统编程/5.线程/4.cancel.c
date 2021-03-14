#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

//线程取消有两种状态：允许 不允许
//允许取消分为异步取消和推迟取消(默认 推迟至取消点响应)
//取消点：POSIX定义的取消点都是可能引发阻塞的系统调用
//pthread_cancel取消制定线程
//pthread_setcancelstate设置是否允许取消
//pthread_setcanceltype设置取消方式
//pthread_testcancel设置取消点

void* Thread()
{
    puts("Thread begin");

    while(1)
    {
        puts("-----");
        sleep(1);
    }

    puts("Thread end");

    pthread_exit(NULL);
}

int main()
{
    puts("Main begin");

    pthread_t tid;
    pthread_create(&tid, NULL, Thread, NULL);
    sleep(3);
    pthread_cancel(tid);    //线程取消 先取消再收尸
    puts("Thread cancel");

    puts("Main end");

    return 0;
}
