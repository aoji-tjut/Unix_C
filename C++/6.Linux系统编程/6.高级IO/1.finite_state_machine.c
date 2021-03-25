#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define F1 "/dev/tty11"
#define F2 "/dev/tty12"

enum
{
    STATE_R,
    STATE_W,
    STATE_EX,
    STATE_T
};

struct fsm_st
{
    int state;          //状态
    int src_fd;         //源文件
    int dst_fd;         //目标文件
    char buf[BUFSIZ];   //缓冲区
    size_t read_size;   //读取字节数
    size_t pos;         //当前位置
    char* err;          //出错
};

void FsmDriver(struct fsm_st* fsm)
{
    size_t write_size;

    switch(fsm->state)
    {
        case STATE_R:
            fsm->read_size = read(fsm->src_fd, fsm->buf, BUFSIZ);

            if(fsm->read_size == 0)     //读结束
            {
                fsm->state = STATE_T;
            }
            else if(fsm->read_size < 0)     //出错
            {
                if(errno == EAGAIN)     //没读到数据 假错
                {
                    fsm->state = STATE_R;
                }
                else
                {
                    fsm->err = "read";
                    fsm->state = STATE_EX;
                }
            }
            else    //读成功
            {
                fsm->pos = 0;
                fsm->state = STATE_W;
            }
            break;

        case STATE_W:
            write_size = write(fsm->dst_fd, fsm->buf + fsm->pos, fsm->read_size);

            if(write_size < 0)  //出错
            {
                if(errno == EAGAIN)     //没写到数据 假错
                {
                    fsm->state = STATE_W;
                }
                else
                {
                    fsm->err = "write";
                    fsm->state = STATE_EX;
                }
            }
            else    //写成功
            {
                fsm->pos += write_size;
                fsm->read_size -= write_size;

                if(fsm->read_size == 0)     //写结束
                {
                    fsm->state = STATE_R;
                }
                else
                {
                    fsm->state = STATE_W;
                }
            }
            break;

        case STATE_EX:
            perror(fsm->err);
            fsm->state = STATE_T;
            break;

        case STATE_T:
            exit(-1);
            break;
    }
}

void Relay(int fd1, int fd2)
{
    int fd1_save, fd2_save;
    struct fsm_st fsm12, fsm21;

    //保存旧文件描述符状态 增加非阻塞标志 若内容据则设置errno为EAGAIN
    fd1_save = fcntl(fd1, F_GETFL);
    fcntl(fd1, F_SETFL, fd1_save | O_NONBLOCK);
    fd2_save = fcntl(fd2, F_GETFL);
    fcntl(fd2, F_SETFL, fd2_save | O_NONBLOCK);

    //初始化状态机
    fsm12.state = STATE_R;
    fsm12.src_fd = fd1;
    fsm12.dst_fd = fd2;
    fsm21.state = STATE_R;
    fsm21.src_fd = fd2;
    fsm21.dst_fd = fd1;

    //执行
    while(fsm12.state != STATE_T || fsm21.state != STATE_T)
    {
        FsmDriver(&fsm12);
        FsmDriver(&fsm21);
    }

    //还原旧文件描述符状态
    fcntl(fd1, F_SETFL, fd1_save);
    fcntl(fd2, F_SETFL, fd2_save);
}

int main()
{
    int fd1, fd2;

    fd1 = open(F1, O_RDWR);
    if(fd1 < 0)
    {
        perror("open");
        exit(-1);
    }
    write(fd1, "fd1\n", 4);

    fd2 = open(F2, O_RDWR);
    if(fd2 < 0)
    {
        perror("open");
        exit(-1);
    }
    write(fd2, "fd2\n", 4);

    Relay(fd1, fd2);

    close(fd2);
    close(fd1);

    return 0;
}
