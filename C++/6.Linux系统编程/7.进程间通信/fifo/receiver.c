#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "protocol.h"

int main()
{
    unlink(FIFO);   //若管道存在则删除

    int fifo = mkfifo(FIFO, O_RDWR | 0644);     //创建有名管道
    if(fifo < 0)
    {
        perror("mkfifo");
        exit(-1);
    }

    int fd = open(FIFO, O_RDWR);
    if(fd < 0)
    {
        perror("open");
        exit(-1);
    }

    fd_set set;
    FD_ZERO(&set);

    while(1)
    {
        FD_SET(fd, &set);

        if(select(fd + 1, &set, NULL, NULL, NULL) < 0)
        {
            perror("select");
            exit(-1);
        }

        if(FD_ISSET(fd, &set))
        {
            if(read(fd, msg, BUFSIZ) < 0)
            {
                perror("read");
                exit(-1);
            }

            puts(msg);

            if(strcmp(msg, "exit") == 0)
            {
                break;
            }
        }

    }

    close(fd);

    return 0;
}
