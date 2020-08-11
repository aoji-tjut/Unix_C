#include <iostream>
#include <thread>
#include <unistd.h>
#include <future>
using namespace std;

void Thread1(promise<int>& temp, int value)
{
    cout << "Thread1:" << endl;
    cout << "计算3s......" << endl;
    sleep(3);

    value *= 10;            //线程对value进行操作
    temp.set_value(value);  //value保存在temp
}

void Thread2(future<int>& f)
{
    cout << "Thread2:" << endl;

    int value = f.get();
    cout << "result=" << value << endl;
}

int main()
{
    promise<int> temp;      //保存线程的值

    thread t1(Thread1, ref(temp), 10);
    t1.join();
    future<int> f = temp.get_future();     //得到Thread1的值
    cout << endl;

    thread t2(Thread2, ref(f));    //Thread1的值传入Thread2
    t2.join();

    return 0;
}
