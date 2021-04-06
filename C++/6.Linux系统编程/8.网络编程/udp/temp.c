#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void* SendThread(void* arg)
{
	int fd = *(int*)arg;
	char port[8];
	char msg[BUFSIZ];
	struct sockaddr_in remote_addr;
	remote_addr.sin_family = AF_INET;
	remote_addr.sin_addr.s_addr = INADDR_ANY;
	while(1)
	{
		remote_addr.sin_port = htons(atoi(port));
		
		puts("-------------------");
		memset(port, '\0', sizeof(port));
		scanf("%s", port);
		memset(msg, '\0', sizeof(msg));
		scanf("%s", msg);

		sendto(fd, msg, sizeof(msg), 0, (void*) &remote_addr, sizeof(remote_addr));

		if(strcmp(msg, "exit") == 0)
		{
			break;
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
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd < 0)
	{
		perror("socket");
		exit(-1);
	}

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

	pthread_t pid;
	pthread_create(&pid, NULL, SendThread, (void*)&fd);

	//通信
	char buf[BUFSIZ];
	struct sockaddr_in remote_addr;
	socklen_t addr_len = sizeof(remote_addr);
	char remote_ip[32];
	int remote_port;
	while(1)
	{
		recvfrom(fd, &buf, sizeof(buf), 0, (void*) &remote_addr, &addr_len);

		inet_ntop(AF_INET, &remote_addr.sin_addr, remote_ip, sizeof(remote_ip));    //把网络字节序地址转化为点分十进制地址
		remote_port = ntohs(remote_addr.sin_port);
		printf("[%s/%d]: %s\n", remote_ip, remote_port, buf);

		if(strcmp(buf, "exit") == 0)
		{
			pthread_cancel(pid);
			break;
		}
	}

	close(fd);

	return 0;
}
