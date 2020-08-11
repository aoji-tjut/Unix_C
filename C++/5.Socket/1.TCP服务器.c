#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERV_PORT 6666

int main()
{
    printf("-----------------------------------\n");
    printf("开始建立服务器...\n");

    int ls_fd;  //监听socket描述符
    ls_fd = socket(AF_INET, SOCK_STREAM, 0);    //协议域 socket类型 协议
    if(ls_fd == -1)
    {
        perror("socket error");
        printf("-----------------------------------\n");
        exit(-1);
    }

    int bd;
    struct sockaddr_in serv_addr;   //服务器地址结构
    serv_addr.sin_family = AF_INET;                 //协议域
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //IP地址 主机字节顺序->网络字节顺序
    serv_addr.sin_port = htons(SERV_PORT);          //端口号 主机字节顺序->网络字节顺序
    bd = bind(ls_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)); //socket描述符 协议地址 地址长度
    if(bd == -1)
    {
        perror("bind error");
        printf("-----------------------------------\n");
        exit(-1);
    }

    int ls;
    ls = listen(ls_fd, 5);  //socket描述符 监听最大上限(最多同时5个客户端与服务器连接)
    if(ls == -1)
    {
        perror("listen error");
        printf("-----------------------------------\n");
        exit(-1);
    }
    printf("服务器建立成功，等待客户端连接...\n");

    int clit_fd;    //客户端socket描述符
    struct sockaddr_in clit_addr;  //客户端地址结构
    clit_addr.sin_family = AF_INET;                 //协议域
    clit_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //IP地址 主机字节顺序->网络字节顺序
    clit_addr.sin_port = htons(SERV_PORT);          //端口号 主机字节顺序->网络字节顺序
    socklen_t clit_addr_len = sizeof(clit_addr);
    clit_fd = accept(ls_fd, (struct sockaddr*) &clit_addr, &clit_addr_len); //socket描述符 协议地址(传出参数) 地址长度(传出参数)
    if(clit_fd == -1)
    {
        perror("accept error");
        printf("-----------------------------------\n");
        exit(-1);
    }
    printf("服务器与客户端连接成功!\n");
    char clit_IP[BUFSIZ];
    int clit_port;
    inet_ntop(AF_INET, &clit_addr.sin_addr.s_addr, clit_IP, sizeof(clit_IP));   //网络字节序IP->点分十进制字符串IP
    clit_port = ntohs(clit_addr.sin_port);  //网络字节顺序端口号->主机字节顺序端口号
    printf("客户端IP：%s\n", clit_IP);
    printf("客户端端口号：%d\n", clit_port);
    printf("-----------------------------------\n");

    ssize_t length;     //读取字节数
    char send_buf[BUFSIZ];
    char recv_buf[BUFSIZ];
    srand(time(NULL));
    int rand_num = rand() % 100;
    int guess_num = -1;
    int min = 0, max = 100;
    while(guess_num != rand_num)
    {
        memset(send_buf, 0, sizeof(send_buf));
        memset(recv_buf, 0, sizeof(recv_buf));

        length = recv(clit_fd, recv_buf, sizeof(recv_buf), 0);  //客户端socket描述符 缓冲区 缓冲区大小 0
        if(length == -1)
        {
            perror("recv error");
            printf("-----------------------------------\n");
            exit(-1);
        }

        guess_num = atoi(recv_buf);
        if(guess_num > max || guess_num < min)
        {
            sprintf(send_buf, "都他妈告诉你%d ~ %d了！傻逼吗！\n", min, max);
        }
        else if(guess_num > rand_num)
        {
            max = guess_num - 1;
            sprintf(send_buf, "%d ~ %d\n", min, max);
        }
        else if(guess_num < rand_num)
        {
            min = guess_num + 1;
            sprintf(send_buf, "%d ~ %d\n", min, max);
        }
        else if(guess_num == rand_num)
        {
            strcpy(send_buf, "猜对啦！\n");
            printf("客户端猜对啦！\n");
        }

        send(clit_fd, send_buf, sizeof(send_buf), 0);   //客户端socket描述符 缓冲区 缓冲区大小 0
    }

    printf("服务器关闭！\n");
    close(ls_fd);
    close(clit_fd);

    return 0;
}