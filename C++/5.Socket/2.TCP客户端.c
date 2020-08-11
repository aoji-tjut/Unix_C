#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    printf("-----------------------------------\n");
    printf("开始建立客户端...\n");

    int clit_fd;    //客户端socket描述符
    clit_fd = socket(AF_INET, SOCK_STREAM, 0);  //协议域 socket类型 协议
    if(clit_fd == -1)
    {
        perror("socket error");
        printf("-----------------------------------\n");
        exit(-1);
    }
    printf("客户端建立成功，正在与服务器连接...\n");

    int cnct;
    char ip[16];
    int port;
    printf("输入服务器IP：");
    scanf("%s", ip);
    printf("输入服务器端口号：");
    scanf("%d", &port);
    struct sockaddr_in serv_addr;   //服务器地址结构
    serv_addr.sin_family = AF_INET;                     //协议域
    inet_pton(AF_INET, ip, &serv_addr.sin_addr.s_addr); //IP地址 点分十进制字符串->网络字节顺序
    serv_addr.sin_port = htons(port);                   //端口号 主机字节顺序->网络字节顺序
    cnct = connect(clit_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));  //socket描述符 协议地址 地址长度
    if(cnct == -1)
    {
        perror("connect error");
        printf("-----------------------------------\n");
        exit(-1);
    }
    printf("服务器与客户端连接成功!\n");
    printf("-----------------------------------\n");

    ssize_t length;    //读取字节数
    char send_buf[BUFSIZ];
    char recv_buf[BUFSIZ];
    int guess_num;
    printf("0 ~ 100\n");
    while(strcmp(recv_buf, "猜对啦！\n"))
    {
        fflush(stdin);
        memset(send_buf, 0, sizeof(send_buf));
        memset(recv_buf, 0, sizeof(recv_buf));

        if(!scanf("%d", &guess_num))
        {
            printf("让你输入整数数字，你干你妈呢？\n\n");
            continue;
        }
        sprintf(send_buf, "%d", guess_num);
        send(clit_fd, send_buf, sizeof(send_buf), 0);   //客户端socket描述符 缓冲区 缓冲区大小 0

        length = recv(clit_fd, recv_buf, sizeof(recv_buf), 0);  //客户端socket描述符 缓冲区 缓冲区大小 0
        if(length == -1)
        {
            perror("recv error");
            printf("-----------------------------------\n");
            exit(-1);
        }
        printf("%s\n", recv_buf);
    }

    printf("客户端关闭！\n");
    close(clit_fd);

    return 0;
}