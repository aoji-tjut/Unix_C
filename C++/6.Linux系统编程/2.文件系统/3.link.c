#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//终端运行 传入源文件、目标文件
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        perror("argc error");
        exit(-1);
    }

    link(argv[1], argv[2]);

    return 0;
}