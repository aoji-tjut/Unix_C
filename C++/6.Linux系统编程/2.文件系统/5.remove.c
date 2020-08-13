#include <stdio.h>
#include <stdlib.h>

//终端运行 传入文件名
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("argc error");
        exit(-1);
    }

    if(remove(argv[1]) < 0)     //rm命令 删除文件
    {
        perror("remove error");
        exit(-1);
    }

    return 0;
}