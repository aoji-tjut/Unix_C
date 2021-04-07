#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int fd;

void Close()
{
	close(fd);
}

void* RecvThread(void* arg)
{	
	char buf[BUFSIZ];
	struct sockaddr_in remote_addr;
	socklen_t addr_len = sizeof(remote_addr);
	char remote_ip[32];
	int remote_port;
	while(1)
	{
		recvfrom(fd, &buf, sizeof(buf), 0, (void*) &remote_addr, &addr_len);

		inet_ntop(AF_INET, &remote_addr.sin_addr, remote_ip, sizeof(remote_ip));
		remote_port = ntohs(remote_addr.sin_port);
		printf("[%s/%d]: %s\n", remote_ip, remote_port, buf);

		if(strcmp(buf, "exit") == 0)
		{
			exit(0);
		}
	}

	pthread_exit(NULL);
}

//终端运行 输入port
int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "arg error\n");
		exit(-1);
	}

	//获取socket
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd < 0)
	{
		perror("socket");
		exit(-1);
	}
	atexit(Close);

	//绑定地址
	struct sockaddr_in local_addr;
	local_addr.sin_family = AF_INET;
	local_addr.sin_addr.s_addr = INADDR_ANY;
	local_addr.sin_port = htons(atoi(argv[1]));
	int ret = bind(fd, (void*) &local_addr, sizeof(local_addr));
	if(ret < 0)
	{
		perror("bind");
		exit(-1);
	}

	//接收线程
	pthread_t pid;
	pthread_create(&pid, NULL, RecvThread, NULL);

	//通信
	char buf[BUFSIZ];
	char remote_port[8];
	printf("remote port: ");
	gets(remote_port);
	struct sockaddr_in remote_addr;
	remote_addr.sin_family = AF_INET;
	remote_addr.sin_port = ntohs(atoi(remote_port));
	remote_addr.sin_addr.s_addr = INADDR_ANY;
	while(1)
	{
		gets(buf);
		sendto(fd, buf, sizeof(buf), 0, (void*) &remote_addr, sizeof(remote_addr));

		if(strcmp(buf, "exit") == 0)
		{
			exit(0);
		}
	}

	return 0;
}
