#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <queue>
using namespace std;

pthread_mutex_t mutex;
queue<int> q;

void* Producer(void* arg)
{
    int num;

    while(1)
    {
        pthread_mutex_lock(&::mutex);
        num = rand() % 1000 + 1;
        cout << "Producer: " << num << endl;
        q.push(num);
        pthread_mutex_unlock(&::mutex);

        usleep(100000);
    }

    pthread_exit(nullptr);
}

void* Consumer1(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&::mutex);
        if(q.empty())
        {
            pthread_mutex_unlock(&::mutex);
            continue;
        }
        cout << "\tConsumer1: " << q.front() << endl;
        q.pop();
        pthread_mutex_unlock(&::mutex);

        usleep(1);  //避免优先唤醒
    }

    pthread_exit(nullptr);
}

void* Consumer2(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&::mutex);
        if(q.empty())
        {
            pthread_mutex_unlock(&::mutex);
            continue;
        }
        cout << "\tConsumer2: " << q.front() << endl;
        q.pop();
        pthread_mutex_unlock(&::mutex);

        usleep(1);
    }

    pthread_exit(nullptr);
}

void* Consumer3(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&::mutex);
        if(q.empty())
        {
            pthread_mutex_unlock(&::mutex);
            continue;
        }
        cout << "\tConsumer3: " << q.front() << endl;
        q.pop();
        pthread_mutex_unlock(&::mutex);

        usleep(1);
    }

    pthread_exit(nullptr);
}

int main()
{
    srand(time(nullptr));

    pthread_mutex_init(&::mutex, nullptr);

    pthread_t p_tid, c_tid1, c_tid2, c_tid3;
    pthread_create(&p_tid, nullptr, Producer, nullptr);
    sleep(1);
    pthread_create(&c_tid1, nullptr, Consumer1, nullptr);
    pthread_create(&c_tid2, nullptr, Consumer2, nullptr);
    pthread_create(&c_tid3, nullptr, Consumer3, nullptr);
    pthread_join(p_tid, nullptr);
    pthread_join(c_tid1, nullptr);
    pthread_join(c_tid2, nullptr);
    pthread_join(c_tid3, nullptr);

    pthread_mutex_destroy(&::mutex);

    return 0;
}
