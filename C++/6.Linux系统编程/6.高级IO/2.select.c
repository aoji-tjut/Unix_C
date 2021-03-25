#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define F1 "/dev/tty11"
#define F2 "/dev/tty12"

//select以事件为单位组织文件描述符

//优点
//可移植性好
//超时时间微秒为单位更精准

//缺点
//fd数量被限制
//监视的事件过于单一
//需要维护一个用来存放大量fd的数据结构 导致用户空间和内核空间在传递该结构时复制开销大
//事件存放位置和结果存放位置一致 select返回后除感兴趣集合之外的集合全部置空 需要重新设置集合
//对fd进行扫描时是线性扫描 fd剧增后IO效率较低

enum
{
    STATE_R,
    STATE_W,
    STATE_AUTO,
    STATE_EX,
    STATE_T
};

struct fsm_st
{
    int state;
    int src_fd;
    int dst_fd;
    char buf[BUFSIZ];
    size_t read_size;
    size_t pos;
    char* err;
};

void FsmDriver(struct fsm_st* fsm)
{
    size_t write_size;

    switch(fsm->state)
    {
        case STATE_R:
            fsm->read_size = read(fsm->src_fd, fsm->buf, BUFSIZ);

            if(fsm->read_size == 0)
            {
                fsm->state = STATE_T;
            }
            else if(fsm->read_size < 0)
            {
                if(errno == EAGAIN)
                {
                    fsm->state = STATE_R;
                }
                else
                {
                    fsm->err = "read";
                    fsm->state = STATE_EX;
                }
            }
            else
            {
                fsm->pos = 0;
                fsm->state = STATE_W;
            }
            break;

        case STATE_W:
            write_size = write(fsm->dst_fd, fsm->buf + fsm->pos, fsm->read_size);

            if(write_size < 0)
            {
                if(errno == EAGAIN)
                {
                    fsm->state = STATE_W;
                }
                else
                {
                    fsm->err = "write";
                    fsm->state = STATE_EX;
                }
            }
            else
            {
                fsm->pos += write_size;
                fsm->read_size -= write_size;

                if(fsm->read_size == 0)
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
    fd_set read_set, write_set;     //文件描述符集合

    //保存旧文件描述符状态 增加非阻塞标志 若没读到数据则设置errno为EAGAIN
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
        //布置监视任务
        FD_ZERO(&read_set);
        FD_ZERO(&write_set);
        if(fsm12.state == STATE_R)
        {
            FD_SET(fsm12.src_fd, &read_set);
        }
        if(fsm12.state == STATE_W)
        {
            FD_SET(fsm12.dst_fd, &write_set);
        }
        if(fsm21.state == STATE_R)
        {
            FD_SET(fsm21.src_fd, &read_set);
        }
        if(fsm21.state == STATE_W)
        {
            FD_SET(fsm21.dst_fd, &write_set);
        }

        //监视
        if(fsm12.state < STATE_AUTO || fsm21.state < STATE_AUTO)
        {
            //最大的文件描述符+1 读集合 写集合 异常集合 超时时间 返回感兴趣文件描述符个数
            if(select((fd1 > fd2 ? fd1 : fd2) + 1, &read_set, &write_set, NULL, NULL) < 0)  //超时(阻塞)监视
            {
                if(errno == EINTR)  //被信号打断 假错
                {
                    continue;
                }
                else
                {
                    perror("select");
                    exit(-1);
                }
            }
        }

        //查看监视结果
        if(FD_ISSET(fd1, &read_set) || FD_ISSET(fd2, &write_set) || fsm12.state > STATE_AUTO)
        {
            FsmDriver(&fsm12);
        }
        if(FD_ISSET(fd2, &read_set) || FD_ISSET(fd1, &write_set) || fsm21.state > STATE_AUTO)
        {
            FsmDriver(&fsm21);
        }
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
