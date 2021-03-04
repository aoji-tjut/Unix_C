#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <glob.h>
#include <sys/wait.h>

#define DELIM " \t\n"

struct cmd_st
{
    glob_t glob_res;
};

int Parse(char* buf, struct cmd_st* cmd)
{
    char* token = NULL;
    int flag = 0;

    while(1)
    {
        token = strsep(&buf, DELIM);
        if(token == NULL)
        {
            break;
        }
        if(token[0] == '\0')    //空串则继续解析
        {
            continue;
        }

        //通过glob.gl_pathv处理不定长的命令和选项
        glob(token, GLOB_NOCHECK | GLOB_APPEND * flag, NULL, &cmd->glob_res);   //没有匹配的通配符则返回原串 第一次后进行追加
        flag = 1;
    }

    return 1;
}

int main()
{
    int res;
    char* buf = NULL;
    size_t size;
    struct cmd_st cmd;

    while(1)
    {
        printf("[linux shell]$ ");

        res = getline(&buf, &size, stdin);
        if(res == -1)
        {
            perror("getline");
            exit(-1);
        }

        res = Parse(buf, &cmd);     //解析命令
        if(res == 0)    //内部命令
        {

        }
        else    //外部命令
        {
            fflush(NULL);

            pid_t pid = fork();
            if(pid == -1)
            {
                perror("fork");
                exit(-1);
            }

            //子进程
            if(pid == 0)
            {
                execvp(cmd.glob_res.gl_pathv[0], cmd.glob_res.gl_pathv);
                perror("execvp");
                exit(-1);
            }

            //父进程
            wait(NULL);
        }
    }

    return 0;
}
