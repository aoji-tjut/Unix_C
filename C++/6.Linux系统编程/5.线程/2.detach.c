#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int i = 0;

void* Thread(void* arg)
{
    while(i++ < 10)
    {
        puts("Thread");
        sleep(1);
    }

    puts("Thread exit");

    pthread_exit(NULL);
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, Thread, NULL);

    sleep(5);
    pthread_detach(tid);

    puts("Thread detach");
    puts("Main thread exit");

    pthread_exit(NULL);
}
