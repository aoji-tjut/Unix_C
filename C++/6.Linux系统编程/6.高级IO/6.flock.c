#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/file.h>

#define NUM 1000

//flock只能锁住整个文件
//lockf可以锁住文件的一部分内容

void Fun()
{
    FILE* fp = fopen("./a", "r+");
    if(fp == NULL)
    {
        perror("fopen");
        exit(-1);
    }

    int fd = fileno(fp);

    flock(fd, LOCK_EX);     //互斥锁定整个文件
    char buf[BUFSIZ];
    fgets(buf, BUFSIZ, fp);
    rewind(fp);
    fprintf(fp, "%d\n", atoi(buf) + 1);
    fflush(fp);
    flock(fd, LOCK_UN);

    fclose(fp);
}

int main()
{
    int fd = open("./a", O_CREAT | O_RDWR | O_TRUNC, 0644);
    if(fd < 0)
    {
        perror("open");
        exit(-1);
    }
    write(fd, "0", 1);
    close(fd);

    pid_t pid;

    for(int i = 0; i < NUM; i++)
    {
        pid = fork();
        if(pid < 0)
        {
            perror("fork");
            exit(-1);
        }

        if(pid == 0)
        {
            Fun();
            exit(0);
        }
    }

    for(int i = 0; i < NUM; i++)
    {
        wait(NULL);
    }

    return 0;
}
