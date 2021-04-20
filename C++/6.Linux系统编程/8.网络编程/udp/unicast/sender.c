#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

//终端运行 输入port
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "arg error\n");
        exit(-1);
    }

    //获取socket
    int fd = socket(AF_INET, SOCK_DGRAM, 0);

    //通信
    char buf[BUFSIZ];
    struct sockaddr_in remote_addr;                         //对方地址结构体
    remote_addr.sin_family = AF_INET;                       //协议族
    remote_addr.sin_port = htons(atoi(argv[2]));            //主机字节序转网络字节序
    inet_pton(AF_INET, “0.0.0.0”, &remote_addr.sin_addr);   //把点分十进制地址转化为网络字节序地址
    while(1)
    {
        memset(buf, '\0', sizeof(buf));
        gets(buf);

        sendto(fd, buf, sizeof(buf), 0, (void*)&remote_addr, sizeof(remote_addr));

        if(strcmp(buf, "exit") == 0)
        {
            break;
        }
    }

    close(fd);

    return 0;
}
