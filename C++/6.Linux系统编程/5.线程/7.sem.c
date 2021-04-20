#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM 1000

//sem_init          初始化信号量 信号量初始值决定了占用信号量的线程个数
//sem_destroy       销毁信号量
//sem_wait          阻塞加锁 信号量-1 信号量为0时阻塞
//sem_trywait       非阻塞尝试加锁
//sem_timedwait     超时锁
//sem_post          解锁 信号量+1
//sem_getvalue      获取信号量值

int num = 0;
sem_t sem;
pthread_mutex_t mutex;

void* Thread(void* arg)
{
    int sval;

    sem_wait(&sem);
    pthread_mutex_lock(&mutex);
    printf("Thread %d\n", (int)arg);
    sem_getvalue(&sem, &sval);
    printf("sval = %d\n", sval);
    num++;
    pthread_mutex_unlock(&mutex);
    sem_post(&sem);

    pthread_exit(NULL);
}

int main()
{
    sem_init(&sem, 0, 5);   //线程间通信 最多同时运行5个线程
    pthread_mutex_init(&mutex, NULL);

    pthread_t tid[NUM];
    for(int i = 0; i < NUM; i++)
    {
        pthread_create(tid + i, NULL, Thread, (void*)(i + 1));
    }

    for(int i = 0; i < NUM; i++)
    {
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&sem);
    pthread_mutex_destroy(&mutex);

    printf("%d\n", num);

    return 0;
}
