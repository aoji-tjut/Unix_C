#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//终端运行 传入目录
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("argc error");
        exit(-1);
    }

    char buf[BUFSIZ];
    if(!getcwd(buf, sizeof(buf)))   //pwd命令 获取绝对路径
    {
        perror("getcwd error");
        exit(-1);
    }
    printf("%s\n", buf);
    memset(buf, 0, sizeof(buf));

    if(chdir(argv[1]) < 0)  //cd命令 更改目录
    {
        perror("chdir error");
        exit(-1);
    }
    if(!getcwd(buf, sizeof(buf)))
    {
        perror("getcwd error");
        exit(-1);
    }
    printf("%s\n", buf);

    return 0;
}