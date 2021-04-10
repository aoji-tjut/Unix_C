#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/epoll.h>

#define F1 "/dev/tty11"
#define F2 "/dev/tty12"

//epoll以文件描述符为单位组织事件 红黑树形式存储fd

//水平触发LT：如果报告了fd后事件没有被处理或数据没有被全部读取 epoll会立即再报告该fd(不停触发 直至处理完毕)
//边缘触发ET：如果报告了fd后事件没有被处理或数据没有被全部读取 epoll会下次再报告该fd(只触发一次 因此需要设置一次性处理完毕 效率高 必须使用非阻塞函数)

//执行epoll_create时 创建了红黑树和就绪链表
//执行epoll_ctl时 如果增加socket句柄 则检查在红黑树中是否存在 存在立即返回 不存在则添加到树干上 然后向内核注册回调函数 用于当中断事件来临时向准备就绪链表中插入数据
//执行epoll_wait时 把触发事件的fd重排到最前面 立刻返回准备就绪链表里的数据

//优点
//本身没有最大并发连接的限制 仅受系统中进程能打开的最大文件数目限制
//效率提升 只有活跃的socket才会主动的去调用callback函数
//使用mmap内存映射机制 避免fd在用户态和内核态之间的复制
//函数返回后会把触发事件的fd排列到最前面 无需遍历所有fd

//缺点
//不可移植

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
    int epoll_fd;
    struct epoll_event ev;  //事件结构体

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

    //打开epoll
    epoll_fd = epoll_create(1);     //任意大于0的值
    if(epoll_fd < 0)
    {
        perror("epoll_create");
    }

    //设置epoll实例
    //epoll实例 操作 文件描述符 事件结构体
    ev.events = 0;
    ev.data.fd = fd1;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd1, &ev);
    ev.events = 0;
    ev.data.fd = fd2;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd2, &ev);

    //执行
    while(fsm12.state != STATE_T || fsm21.state != STATE_T)
    {
        //布置监视任务
        ev.events = 0;
        ev.data.fd = fd1;
        if(fsm12.state == STATE_R)
        {
            ev.events |= EPOLLIN;
        }
        if(fsm21.state == STATE_W)
        {
            ev.events |= EPOLLOUT;
        }
        epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd1, &ev);
        ev.events = 0;
        ev.data.fd = fd2;
        if(fsm21.state == STATE_R)
        {
            ev.events |= EPOLLIN;
        }
        if(fsm12.state == STATE_W)
        {
            ev.events |= EPOLLOUT;
        }
        epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd2, &ev);

        //监视
        if(fsm12.state < STATE_AUTO || fsm21.state < STATE_AUTO)
        {
            //epoll实例 事件结构体地址 结构体个数 超时时间 返回触发事件fd的个数
            while(epoll_wait(epoll_fd, &ev, 1, -1) < 0)     //超时(阻塞)监视
            {
                if(errno == EINTR)  //被信号打断 假错
                {
                    continue;
                }
                else
                {
                    perror("epoll_wait");
                    exit(-1);
                }
            }
        }

        //查看监视结果
        if((ev.data.fd == fd1 && (ev.events & EPOLLIN) ||
            (ev.data.fd == fd2 && (ev.events & EPOLLOUT)) ||
            fsm12.state > STATE_AUTO)
        {
            FsmDriver(&fsm12);
        }
        if((ev.data.fd == fd2 && (ev.events & EPOLLIN)) ||
           (ev.data.fd == fd1 && (ev.events & EPOLLOUT)) ||
           fsm12.state > STATE_AUTO)
        {
            FsmDriver(&fsm21);
        }
    }

    //关闭epoll
    close(epoll_fd);

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
