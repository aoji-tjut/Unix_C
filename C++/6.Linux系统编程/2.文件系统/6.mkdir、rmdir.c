#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

//终端运行 传入目录
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("argc error");
        exit(-1);
    }

    if(mkdir(argv[1], 0755) < 0)    //mkdir命令 创建目录
    {
        perror("mkdir error");
        exit(-1);
    }

    if(rmdir(argv[1]) < 0)  //rmdir命令 删除空目录
    {
        perror("rmdir error");
        exit(-1);
    }

    return 0;
}