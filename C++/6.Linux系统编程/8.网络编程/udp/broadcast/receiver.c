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

    //打开广播属性
    int flag = 1;
    setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag));

    //绑定地址
    struct sockaddr_in local_addr;                          //本地地址结构体
    local_addr.sin_family = AF_INET;                        //协议族
    local_addr.sin_port = htons(atoi(argv[1]));             //主机字节序转网络字节序
    inet_pton(AF_INET, "0.0.0.0", &local_addr.sin_addr);    //把点分十进制地址转化为网络字节序地址 0.0.0.0自动识别本地ip
    bind(fd, (void*) &local_addr, sizeof(local_addr));

    //通信
    char buf[BUFSIZ];
    struct sockaddr_in remote_addr;             //对方地址结构体
    socklen_t addr_len = sizeof(remote_addr);   //对方地址结构体大小 初始化很重要
    char remote_ip[32];                         //对方主机字节序ip
    int remote_port;                            //对方主机字节序端口
    fd_set set;
    FD_ZERO(&set);
    while(1)
    {
        FD_SET(fd, &set);
        select(fd + 1, &set, NULL, NULL, NULL);

        if(FD_ISSET(fd, &set))
        {
            recvfrom(fd, &buf, sizeof(buf), 0, (void*) &remote_addr, &addr_len);

            inet_ntop(AF_INET, &remote_addr.sin_addr, remote_ip, sizeof(remote_ip));
            remote_port = ntohs(remote_addr.sin_port);
            printf("[%s/%d]: %s\n", remote_ip, remote_port, buf);

            if(strcmp(buf, "exit") == 0)
            {
                break;
            }
        }
    }

    close(fd);

    return 0;
}
