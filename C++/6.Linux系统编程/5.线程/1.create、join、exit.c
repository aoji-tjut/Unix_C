#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

//线程的调度取决于调度器的调度策略

//线程终止方式
//线程从启动例程返回 返回值就是线程的退出码
//线程被同一进程中的其他线程取消
//线程调用pthread_exit函数

void* Thread(void* arg)
{
    puts("Thread begin");
    printf("Thread arg: %d\n", (int)arg);
    puts("Thread end");

    pthread_exit((void*)888);
}

int main()
{
    puts("Main begin");

    int error;
    pthread_t tid;
    int arg = 666;

    error = pthread_create(&tid, NULL, Thread, (void*)arg);    //线程标识 线程属性 线程函数 线程参数
    if(error)
    {
        fprintf(stderr, "pthread_create: %s\n", strerror(error));
        exit(-1);
    }

    void* retval = NULL;
    pthread_join(tid, &retval);     //阻塞等待线程结束 获取线程返回值 作用同waitpid
    printf("Thread return: %d\n", (int)retval);

    puts("Main end");

    return 0;
}
