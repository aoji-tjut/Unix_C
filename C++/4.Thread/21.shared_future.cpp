#include <iostream>
#include <thread>
#include <unistd.h>
#include <future>
using namespace std;

int Thread1(int i)
{
    cout << "Thread1:\t\t\t\t\t" << this_thread::get_id() << endl;
    cout << "Thread执行3s......" << endl;
    sleep(3);

    return i;
}

void Thread2(shared_future<int>& sf)
{
    cout << "Thread2:\t\t\t\t\t" << this_thread::get_id() << endl;

    int value = sf.get();
    cout << "value=" << value << endl;
}

void Thread3(shared_future<int>& sf)
{
    cout << "Thread3:\t\t\t\t\t" << this_thread::get_id() << endl;

    int value = sf.get();
    cout << "value=" << value << endl;
}

int main()
{
    cout << "主线程开始--------------------" << this_thread::get_id() << endl;
    cout << endl;

    future<int> f = async(launch::async, Thread1, 10);
    cout << endl;

    cout << "f是否有值:" << (f.valid() > 0 ? "true" : "false") << endl;
    shared_future<int> sf(move(f));     //通过future构造shared_future必须传入右值或传入f.share() shared_future可以get多次
    cout << "f是否有值:" << (f.valid() > 0 ? "true" : "false") << endl;
    cout << endl;

    thread t2(Thread2, ref(sf));
    t2.join();
    thread t3(Thread3, ref(sf));
    t3.join();
    cout << endl;

    cout << "主线程结束--------------------" << endl;

    return 0;
}
