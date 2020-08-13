#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

//终端运行 传入文件名
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("argc error");
        exit(-1);
    }

    chmod(argv[1], 0777);   //通过文件名修改权限rwxrwxrwx

    int fd = open(argv[1], O_RDONLY);
    fchmod(fd, 0755);   //通过文件描述符修改权限rwxr-xr-x
    close(fd);

    return 0;
}