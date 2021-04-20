#include <stdio.h>
#include <pthread.h>

#define NUM 1000

//pthread_mutex_init        初始化互斥锁
//pthread_mutex_destroy     销毁互斥锁
//pthread_mutex_lock        阻塞加锁
//pthread_mutex_trylock     非阻塞尝试加锁
//pthread_mutex_unlock      解锁

int num = 0;
pthread_mutex_t mutex;

void* Thread(void* arg)
{
    pthread_mutex_lock(&mutex);
    printf("Thread %d\n", (int)arg);
    num++;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main()
{
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

    pthread_mutex_destroy(&mutex);

    printf("%d\n", num);

    return 0;
}

