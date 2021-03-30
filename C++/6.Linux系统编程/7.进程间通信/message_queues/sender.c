#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "protocol.h"

int main()
{
    key_t key = ftok(KEYPATH, KEYPROJ);     //得到通信的key
    if(key < 0)
    {
        perror("ftok");
        exit(-1);
    }

    int msg_id = msgget(key, 0);    //得到已创建好的消息队列
    if(msg_id < 0)
    {
        perror("msgget");
        exit(-1);
    }

    struct msg_st buf;
    buf.mtype = 1;
    while(1)
    {
        gets(buf.msg);

        if(msgsnd(msg_id, &buf, sizeof(buf) - sizeof(long), 0) < 0)     //发送消息
        {
            perror("msgsnd");
            exit(-1);
        }

        if(strcmp(buf.msg, "exit") == 0)
        {
            break;
        }
    }

    return 0;
}
