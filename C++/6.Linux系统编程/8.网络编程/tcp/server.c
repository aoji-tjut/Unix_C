#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <arpa/inet.h>

struct thread_arg
{
    int epoll_fd;
    int client_fd;
};

void DealSignal(int arg)
{
    puts("SIGINT");
    exit(0);
}

void Error(const char* str, int line)
{
    fprintf(stderr, "%s(%d): %s\n", str, line, strerror(errno));
    exit(-1);
}

void* Recv(void* args)
{
    struct thread_arg arg = *(struct thread_arg*)args;
    char buf[5];
    int ret;

    while(1)
    {
        memset(buf, '\0', sizeof(buf));
        ret = recv(arg.client_fd, buf, sizeof(buf), 0);

        if(ret <= 0)
        {
            if(errno == EAGAIN) pthread_exit(NULL);

            ret = epoll_ctl(arg.epoll_fd, EPOLL_CTL_DEL, arg.client_fd, NULL);
            if(ret < 0) Error("epoll_ctl", __LINE__);

            ret = close(arg.client_fd);
            if(ret < 0) Error("close", __LINE__);
            printf("fd=%d exit\n", arg.client_fd);

            pthread_exit(NULL);
        }
        else
        {
            printf("fd=%d: %s\n", arg.client_fd, buf);
        }
    }
}

void CloseFd(int status, void* arg)
{
    close(*(int*)arg);
}

int CreateSocket(int port)
{
    int ret;

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_fd < 0) Error("socket", __LINE__);
    on_exit(CloseFd, (void*)&listen_fd);

    int flag = 1;
    ret = setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
    if(ret < 0) Error("setsockopt", __LINE__);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ret = bind(listen_fd, (void*)&server_addr, sizeof(server_addr));
    if(ret < 0) Error("bind", __LINE__);

    ret = listen(listen_fd, 1024);
    if(ret < 0) Error("listen", __LINE__);

    return listen_fd;
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "port\n");
        exit(-1);
    }

    signal(SIGINT, DealSignal);

    int ret;

    int listen_fd = CreateSocket(atoi(argv[1]));

    int epoll_fd = epoll_create(1);
    if(epoll_fd < 0) Error("epoll_create", __LINE__);
    on_exit(CloseFd, (void*)&epoll_fd);

    struct epoll_event event;
    struct epoll_event wait_event[1024];
    event.data.fd = listen_fd;
    event.events = EPOLLIN | EPOLLET;
    ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &event);
    if(ret < 0) Error("epoll_ctl", __LINE__);

    int num;
    int client_fd;
    int client_port;
    char client_ip[32];
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t tid;
    struct thread_arg arg;
    arg.epoll_fd = epoll_fd;

    while(1)
    {
        num = epoll_wait(epoll_fd, wait_event, sizeof(wait_event), -1);
        if(num < 0) Error("epoll_wait", __LINE__);

        for(int i = 0; i < num; i++)
        {
            if(wait_event[i].data.fd == listen_fd)
            {
                client_fd = accept(listen_fd, (void*)&client_addr, &client_addr_len);
                if(client_fd < 0) Error("accept", __LINE__);

                inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
                client_port = ntohs(client_addr.sin_port);
                printf("new connect [%d-%s-%d]\n", client_fd, client_ip, client_port);

                ret = fcntl(client_fd, F_SETFL, fcntl(client_fd, F_GETFL) | O_NONBLOCK);
                if(ret < 0) Error("fcntl", __LINE__);

                event.data.fd = client_fd;
                ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event);
                if(ret < 0) Error("epoll_ctl", __LINE__);
            }
            else
            {
                arg.client_fd = wait_event[i].data.fd;
                pthread_create(&tid, NULL, Recv, (void*)&arg);
                pthread_detach(tid);
            }
        }
    }

    return 0;
}
