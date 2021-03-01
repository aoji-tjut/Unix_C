#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//0->stdin 1->stdout 2->stderr

//终端运行 传入文件名、写入文件的内容...
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("argc error");
        exit(-1);
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);  //fd占用3下标
    if(fd < 0)
    {
        perror("open error");
        exit(-1);
    }

    for(int i = 2; i < argc; i++)
    {
        puts(argv[i]);  //stdout输出
    }

    //非原子操作
//    close(1);   //关闭stdout文件描述符 下标1为空
//    dup(fd);    //复制一份fd到当前可用最小下标：1 并返回复制后的文件描述符
//    close(fd);  //关闭fd文件描述符 下标3为空
//    for(int i = 2; i < argc; i++)
//    {
//        puts(argv[i]);  //fd(下标为1)输出
//    }

    //原子操作 dup2 = close + dup
    int new_fd = 1;
    dup2(fd, new_fd);   //关闭下标new_fd的文件描述符 把fd的位置复制到new_fd的位置(下标1的文件描述符复制为fd)并返回new_fd (若fd==new_fd则不会关闭new_fd 直接返回new_fd)
    if(fd != new_fd)
    {
        close(fd);  //关闭下标3的fd
    }

    for(int i = 2; i < argc; i++)
    {
        puts(argv[i]);  //new_fd(下标为1)输出
    }

    return 0;
}
