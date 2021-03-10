#include <stdio.h>
#include <stdlib.h>

//进程正常终止：
//从main函数返回 返回值交给父进程 shell中$?查看进程终止状态
//调用exit (库函数) 执行钩子函数、刷新IO...
//调用_exit或_Exit (系统调用) 不执行钩子函数、不刷新IO...
//最后一个线程从其启动例程返回
//最后一个线程调用pthread_exit

//进程异常终止：
//调用abort
//接到一个信号并终止
//最后一个线程对其取消请求做出响应

void Fun1()
{
    puts("Fun1");
}

void Fun2()
{
    puts("Fun2");
}

void Fun3()
{
    puts("Fun3");
}

int main()
{
    puts("Begin");

    //钩子函数 类似析构函数 用于资源释放
    //函数挂入钩子
    atexit(Fun1);
    atexit(Fun2);
    atexit(Fun3);

    puts("End");

    return 0;   //进程结束前逆序调用钩子函数
}
