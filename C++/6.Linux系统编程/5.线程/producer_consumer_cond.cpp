#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <queue>

#define PNUM 2
#define CNUM 3

pthread_mutex_t mutex;
pthread_cond_t cond;
std::queue<int> q;

void* Producer(void* arg)
{
    int num;

    while(true)
    {
        pthread_mutex_lock(&::mutex);
        num = rand() % 1000 + 1;
        printf("Producer%d: %d\n", arg, num);
        q.push(num);
        pthread_mutex_unlock(&::mutex);
        pthread_cond_broadcast(&cond);

        sleep(1);
    }

    pthread_exit(nullptr);
}

void* Consumer(void* arg)
{
    while(true)
    {
        pthread_mutex_lock(&::mutex);
        while(q.empty())
        {
            pthread_cond_wait(&cond, &::mutex);     //若队列为空则阻塞等待 极大减小cpu占用
            printf("\t%d wake\n", arg);
        }
        printf("\tConsumer%d: %d\n", arg, q.front());
        q.pop();
        pthread_mutex_unlock(&::mutex);

        usleep(1);  //避免优先唤醒
    }

    pthread_exit(nullptr);
}

int main()
{
    srand(time(nullptr));

    pthread_mutex_init(&::mutex, nullptr);
    pthread_cond_init(&cond, nullptr);

    pthread_t p_tid[PNUM], c_tid[CNUM];
    for(int i = 0; i < PNUM; i++)
    {
        pthread_create(p_tid + i, nullptr, Producer, (void*)(i + 1));
    }
    for(int i = 0; i < CNUM; i++)
    {
        pthread_create(p_tid + i, nullptr, Consumer, (void*)(i + 1));
    }

    for(auto i : p_tid)
    {
        pthread_join(i, nullptr);
    }
    for(auto i : c_tid)
    {
        pthread_join(i, nullptr);
    }

    pthread_mutex_destroy(&::mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
