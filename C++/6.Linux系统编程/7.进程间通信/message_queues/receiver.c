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

    int msg_id = msgget(key, IPC_CREAT | 0644);     //创建消息队列 权限644
    if(msg_id < 0)
    {
        perror("msgget");
        exit(-1);
    }

    struct msg_st buf;
    while(1)
    {
        if(msgrcv(msg_id, &buf, sizeof(buf) - sizeof(long), 0, 0) < 0)  //接收消息
        {
            perror("msgrcv");
            exit(-1);
        }

        puts(buf.msg);

        if(strcmp(buf.msg, "exit") == 0)
        {
            break;
        }
    }

    msgctl(msg_id, IPC_RMID, NULL);     //销毁

    return 0;
}
