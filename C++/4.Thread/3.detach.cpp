#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

void Thread1()
{
    for(int i = 0; i < 10; i++)
    {
        cout << "Thread1:" << i << endl;
        usleep(1);      //延时1us
    }
}

void Thread2()
{
    for(int i = 0; i < 10; i++)
    {
        cout << "Thread2:" << i << endl;
        usleep(1);      //延时1us
    }
}

int main()
{
    cout << "主线程开始--------------------" << endl;

    thread t1(Thread1);
    t1.detach();    //主线程与子线程分离 子线程后台运行 主线程无法重新控制子线程 主线程结束后由运行时库清理子线程资源(守护线程)

    thread t2(Thread2);
    t2.detach();

    cout << "主线程结束--------------------" << endl;

    return 0;
}