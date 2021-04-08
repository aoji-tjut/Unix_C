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
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    //连接
    struct sockaddr_in remote_addr;
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, "0.0.0.0", &remote_addr.sin_addr);
    connect(fd, (void*) &remote_addr, sizeof(remote_addr));

    //通信
    char buf[BUFSIZ];
    while(1)
    {
        memset(buf, '\0', sizeof(buf));
        gets(buf);

        send(fd, buf, sizeof(buf), 0);

        if(strcmp(buf, "exit") == 0)
        {
            break;
        }
    }

    close(fd);

    return 0;
}
