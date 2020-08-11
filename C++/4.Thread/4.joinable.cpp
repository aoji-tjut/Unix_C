#include <iostream>
#include <thread>
using namespace std;

void Thread()
{
    for(int i = 0; i < 10; i++)
    {
        cout << "Thread:" << i << endl;
    }
}

int main()
{
    cout << "主线程开始--------------------" << endl;
    cout << endl;

    thread t(Thread);   //每个子线程join与detach不能共用 且选定后不能改变
    if(t.joinable())    //判断是否可以join或detach 返回bool
    {
        cout << "Thread:True" << endl;
        t.join();
    } else
    {
        cout << "Thread:False" << endl;
    }

    if(t.joinable())
    {
        cout << "Thread:True" << endl;
    } else
    {
        cout << "Thread:False" << endl;
    }

    cout << endl;
    cout << "主线程结束--------------------" << endl;

    return 0;
}