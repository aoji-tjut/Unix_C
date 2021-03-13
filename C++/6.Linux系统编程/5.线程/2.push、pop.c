#include <stdio.h>
#include <pthread.h>
#include <string.h>

//线程清理
//pthread_cleanup_push和pthread_cleanup_pop是宏 必须成对使用 类似钩子函数

void Push(void* val)
{
    puts(val);
}

void* Thread()
{
    puts("Thread begin");

    //挂钩子 函数名 传参
    pthread_cleanup_push(Push, "1");
        pthread_cleanup_push(Push, "2");
            pthread_cleanup_push(Push, "3");
                puts("Thread push finish");

                //卸钩子 1调用Push函数 0不调用Push函数
            pthread_cleanup_pop(1);
        pthread_cleanup_pop(1);
    pthread_cleanup_pop(0);
    puts("Thread pop finish");

    puts("Thread end");

    pthread_exit(NULL);
}

int main()
{
    puts("Main begin");

    pthread_t tid;
    pthread_create(&tid, NULL, Thread, NULL);
    pthread_join(tid, NULL);

    puts("Main end");

    return 0;
}
