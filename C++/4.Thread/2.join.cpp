#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

void Thread1()
{
    for(int i = 0; i < 10; i++)
    {
        cout << "Thread1:" << i << endl;
        usleep(500000);    //延迟500ms
    }
}

void Thread2()
{
    for(int i = 0; i < 10; i++)
    {
        cout << "Thread2:" << i << endl;
        usleep(500000);
    }
}

int main()
{
    cout << "主线程开始--------------------" << endl;
    cout << endl;

    thread t1(Thread1);     //执行此行后子线程就开始执行
    t1.join();      //主线程与子线程结合 阻塞主线程 等待子线程执行完毕
    cout << endl;

    thread t2(Thread2);
    t2.join();
    cout << endl;

    cout << "主线程结束--------------------" << endl;

    return 0;
}