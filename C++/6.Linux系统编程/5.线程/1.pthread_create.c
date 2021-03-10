#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

//线程的调度取决于调度器的调度策略

void* Thread()
{
    puts("Thread");

    return NULL;
}

int main()
{
    puts("Begin");

    int error;
    pthread_t tid;
    error = pthread_create(&tid, NULL, Thread, NULL);   //线程标识 线程属性 线程函数 线程参数
    if(error)
    {
        fprintf(stderr, "pthread_create:%s\n", strerror(error));
        exit(-1);
    }

    sleep(1);

    puts("End");

    return 0;
}
