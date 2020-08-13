#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

//终端运行 传入文件名
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("argc error");
        exit(-1);
    }

    if(chmod(argv[1], 0777) < 0)    //chmod命令 通过文件名修改权限rwxrwxrwx
    {
        perror("chmod error");
        exit(-1);
    }

    int fd = open(argv[1], O_RDONLY);
    if(fchmod(fd, 0755) < 0)    //通过文件描述符修改权限rwxr-xr-x
    {
        perror("fchmod error");
        exit(-1);
    }
    close(fd);

    return 0;
}