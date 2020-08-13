#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <string.h>

#define PATH "*"

//出错路径、出错原因
int ErrFunc(const char* epath, int eerrno)
{
    puts(epath);
    perror(strerror(eerrno));

    return 0;
}

int main(int argc, char* argv[])
{
    glob_t glob_res;    //匹配文件的结果
    if(glob(PATH, 0, ErrFunc, &glob_res) != 0)  //通配符 特殊标志 出错函数指针
    {
        perror("glob error");
        exit(-1);
    }

    for(int i = 0; i < glob_res.gl_pathc; i++)
    {
        puts(glob_res.gl_pathv[i]);
    }

    return 0;
}