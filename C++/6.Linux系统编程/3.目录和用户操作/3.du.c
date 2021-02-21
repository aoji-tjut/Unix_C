#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int64_t Du(const char* path)
{
    struct stat st;

    if(lstat(path, &st) < 0)
    {
        perror("stat error");
        exit(-1);
    }

    if(S_ISDIR(st.st_mode))     //目录
    {

    }
    else                        //非目录
    {
        return st.st_blocks / 2;
    }

}

//终端运行 传入目录
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("argc error");
        exit(-1);
    }

    printf("%lld\n",Du(argv[1]));

    return 0;
}