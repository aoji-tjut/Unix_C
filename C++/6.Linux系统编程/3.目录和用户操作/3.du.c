#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <glob.h>
#include <dirent.h>

int NoLoop(const char* path)
{
    //path=.../.../.../.../.../...
    char* pos = strrchr(path, '/');     //查找最右边的'/'字符位置
    if(!pos)
    {
        perror("strrchr error");
        exit(-1);
    }

    pos++;
    if(strcmp(pos, ".") == 0 || strcmp(pos, "..") == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int64_t Du(const char* path)
{
    static struct stat stat_res;
    if(lstat(path, &stat_res) < 0)
    {
        perror("stat error");
        exit(-1);
    }

    //非目录文件
    if(!S_ISDIR(stat_res.st_mode))
    {
        printf("%lld KB\t%s\n", stat_res.st_blocks / 2, path);
        return stat_res.st_blocks;
    }

    //目录文件
    static char next_path[BUFSIZ];
    glob_t glob_res;

    strncpy(next_path, path, BUFSIZ);
    strncat(next_path, "/*", BUFSIZ);
    if(glob(next_path, 0, NULL, &glob_res) != 0)    //非隐藏文件
    {
        perror("glob error");
        exit(-1);
    }

    strncpy(next_path, path, BUFSIZ);
    strncat(next_path, "/.*", BUFSIZ);
    if(glob(next_path, GLOB_APPEND, NULL, &glob_res) != 0)  //隐藏文件 追加到glob_res
    {
        perror("glob error");
        exit(-1);
    }

    int64_t ret = stat_res.st_blocks;
    for(int i = 0; i < glob_res.gl_pathc; i++)
    {
        if(NoLoop(glob_res.gl_pathv[i]))    //解析非.和..文件
        {
            ret += Du(glob_res.gl_pathv[i]);
        }
    }

    globfree(&glob_res);
    printf("%lld KB\t%s\n", ret / 2, path);

    return ret;
}

//终端运行 传入目录
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("argc error");
        exit(-1);
    }

    const char* path = argv[1];
    printf("%lld KB\t%s\n", Du(path) / 2, path);    //st_blocks除以2是kb

    return 0;
}