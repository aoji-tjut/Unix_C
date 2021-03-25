#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

//终端运行 传入文件
int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "arg\n");
		exit(-1);
	}
	
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		exit(-1);
	}

	struct stat stat_res;
	if(fstat(fd, &stat_res) < 0)
	{
		perror("stat");
		exit(-1);
	}
	
	//共享内存
	//映射起始地址 映射长度 权限 标志 文件描述符 偏移量 返回映射首地址
	char* str = mmap(NULL, stat_res.st_size, PROT_READ, MAP_SHARED, fd, SEEK_SET);
	if(str == MAP_FAILED)
	{
		perror("mmap");
		exit(-1);
	}
	close(fd);

	char* c = str;
	while(*c != '\0')
	{
		printf("%c", *c);
		fflush(stdout);
		c++;
		usleep(10000);
	}

	munmap(str, stat_res.st_size);

	return 0;
}
