#include <stdio.h>
#include <signal.h>
#include <pthread.h>

//pthread_cond_init         初始化条件变量
//pthread_cond_destroy      销毁条件变量
//pthread_cond_broadcast    唤醒所有等待的条件变量
//pthread_cond_signal       唤醒任意一个等待的条件变量
//pthread_cond_wait         阻塞等待 解锁->等待唤醒->抢锁->加锁
//pthread_cond_timedwait    超时等待

pthread_mutex_t mutex;
pthread_cond_t cond;

void* Thread1(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        puts("Thread1");
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void* Thread2(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        puts("Thread2");
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void DealSignal()
{
    pthread_cond_signal(&cond);
}

//终端运行
int main()
{
    signal(SIGINT, DealSignal);

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, Thread1, NULL);
    pthread_create(&tid2, NULL, Thread2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
