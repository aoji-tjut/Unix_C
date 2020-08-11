#include <iostream>
#include <thread>
#include <unistd.h>
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

    thread t(Thread);   //创建子线程 主线程与子线程并行执行 会产生异常 若主线程执行完毕时子线程未执行完毕则强行终止子线程

    sleep(1);           //延时1s
    cout << endl;
    cout << "主线程结束--------------------" << endl;

    return 0;
}