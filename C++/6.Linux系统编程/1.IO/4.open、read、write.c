#include <stdio.h>      //标准IO  合并系统调用  响应速度慢 吞吐量大 返回文件指针
#include <unistd.h>     //系统IO              响应速度快 吞吐量小 返回文件描述符
#include <stdlib.h>
#include <fcntl.h>

//文件描述符是存储文件指针的数组的下标 0->stdin 1->stdout 2->stderr
//fileno() 文件指针->文件描述符 即标准IO->系统IO
//fdopen() 文件描述符->文件指针 即系统IO->标准IO

//终端运行 传入源文件、目标文件
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        perror("argc error");
        exit(-1);
    }

    int src_fd, dst_fd;

    src_fd = open(argv[1], O_RDONLY);     //只读打开
    if(src_fd < 0)
    {
        perror("src_fd open error");
        exit(-1);
    }

    dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);   //只写打开 无则创建 有则清空 644权限
    if(dst_fd < 0)
    {
        close(src_fd);
        perror("dst_fd open error");
        exit(-1);
    }

    char buf[BUFSIZ];
    int len, ret, pos;
    while(1)
    {
        len = read(src_fd, buf, sizeof(buf));
        if(len < 0)
        {
            perror("read error");
            break;
        }
        else if(len == 0)
        {
            break;
        }

        //避免写入字符小于读取字符
        pos = 0;
        while(len > 0)
        {
            ret = write(dst_fd, buf + pos, len);
            if(ret < 0)
            {
                perror("write error");
                exit(-1);   //小量内存泄漏
            }

            pos += ret;
            len -= ret;
        }
    }

    close(dst_fd);
    close(src_fd);

    return 0;
}
