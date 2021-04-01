#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "protocol.h"

int main()
{
    int fifo = open(FIFO, O_RDWR);
    if(fifo < 0)
    {
        perror("open");
        exit(-1);
    }

    while(1)
    {
        gets(msg);

        if(write(fifo, msg, BUFSIZ) < 0)
        {
            perror("write");
            exit(-1);
        }

        if(strcmp(msg, "exit") == 0)
        {
            break;
        }
    }

    close(fifo);
    unlink(FIFO);   //删除管道

    return 0;
}
