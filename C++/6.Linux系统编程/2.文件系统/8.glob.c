#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <string.h>

//出错路径、出错原因
int ErrFunc(const char* epath, int eerrno)
{
    puts(epath);
    perror(strerror(eerrno));

    return 0;
}

int main(int argc, char* argv[])
{
    printf("输入目录+通配符\n");
    char path[BUFSIZ];  //目录+通配符
    scanf("%s", path);

    glob_t glob_res;    //匹配文件的结果
    if(glob(path, 0, ErrFunc, &glob_res) != 0)  //目录+通配符 特殊标志 出错函数指针 结构体指针
    {
        perror("glob error");
        exit(-1);
    }

    for(int i = 0; i < glob_res.gl_pathc; i++)
    {
        puts(glob_res.gl_pathv[i]);
    }

    globfree(&glob_res);

    return 0;
}