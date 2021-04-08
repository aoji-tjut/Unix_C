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
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    //绑定地址
    struct sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, "0.0.0.0", &local_addr.sin_addr);
    bind(server_fd, (void*) &local_addr, sizeof(local_addr));

    //监听
    listen(server_fd, 10);  //连接最大上限

    //接受连接
    struct sockaddr_in remote_addr;
    socklen_t addr_len = sizeof(remote_addr);
    int client_fd = accept(server_fd, (void*) &remote_addr, &addr_len);

    //通信
    char buf[BUFSIZ];
    char remote_ip[32];
    int remote_port;
    while(1)
    {
        inet_ntop(AF_INET, &remote_addr.sin_addr, remote_ip, sizeof(remote_ip));
        remote_port = ntohs(remote_addr.sin_port);

        recv(client_fd, buf, sizeof(buf), 0);

        printf("[%s/%d]: %s\n", remote_ip, remote_port, buf);

        if(strcmp(buf, "exit") == 0)
        {
            break;
        }
    }

    close(client_fd);
    close(server_fd);

    return 0;
}
