#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>

#define NUM 1024

//pthread_mutex_init
//pthread_mutex_destroy
//pthread_mutex_lock
//pthread_mutex_trylock
//pthread_mutex_unlock

pthread_mutex_t mutex;

void* Thread()
{
    FILE* fp;
    char str[BUFSIZ];

    fp = fopen("./a", "r+");
    if(fp == NULL)
    {
        perror("fopen");
        exit(-1);
    }

    pthread_mutex_lock(&mutex);
    fgets(str, BUFSIZ, fp);
    rewind(fp);
    fprintf(fp, "%d\n", atoi(str) + 1);
    fclose(fp);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main()
{
    int fd = open("./a", O_RDWR | O_CREAT | O_TRUNC, 0644);
    write(fd, "0\n", sizeof("0"));
    close(fd);

    pthread_mutex_init(&mutex, NULL);

    pthread_t tid[NUM];
    for(int i = 0; i < NUM; i++)
    {
        int error = pthread_create(tid + i, NULL, Thread, NULL);
        if(error)
        {
            fprintf(stderr, "pthread_create: %s\n", strerror(error));
        }
    }

    for(int i = 0; i < NUM; i++)
    {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
