#include <stdio.h>
#include <stdlib.h>

//终端运行 传入源文件、目标文件
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        perror("argc error");
        exit(-1);
    }

    if(rename(argv[1], argv[2]) < 0)    //mv命令 移动/重命名
    {
        perror("rename error");
        exit(-1);
    }

    return 0;
}