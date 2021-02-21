#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    printf("输入目录\n");
    char path[BUFSIZ];  //目录
    scanf("%s", path);

    DIR* pdir = opendir(path);  //打开目录 返回目录指针
    if(!pdir)
    {
        perror("opendir error");
        exit(-1);
    }

    struct dirent* cur;     //当前目录信息
    cur = readdir(pdir);    //读取目录 成功返回目录信息 失败返回NULL
    while(cur)
    {
        puts(cur->d_name);
        cur = readdir(pdir);
    }

    closedir(pdir);     //关闭目录

    return 0;
}