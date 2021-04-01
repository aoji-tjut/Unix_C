#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//匿名管道仅用于有亲缘关系的进程间通信

int main()
{
    int pipe_fd[2];
    if(pipe(pipe_fd) < 0)   //pipe_fd[0]读 pipe_fd[1]写
    {
        perror("pipe");
        exit(-1);
    }

    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(-1);
    }

    char buf[BUFSIZ];
    if(pid == 0)
    {
        sleep(1);
        puts("Child read");
        close(pipe_fd[1]);
        int len = read(pipe_fd[0], buf, BUFSIZ);
        write(1, buf, len);
        close(pipe_fd[0]);
        exit(0);
    }
    else
    {
        puts("Parent write");
        close(pipe_fd[0]);
        write(pipe_fd[1], "hello\n", 6);
        close(pipe_fd[1]);
        wait(NULL);
        exit(0);
    }

    return 0;
}
