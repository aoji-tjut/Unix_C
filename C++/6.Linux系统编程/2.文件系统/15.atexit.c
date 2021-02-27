#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[])
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
