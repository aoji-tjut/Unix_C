#include <iostream>
#include <thread>
#include <unistd.h>
#include <future>
using namespace std;

int Thread(int i)
{
    cout << "Thread:\t\t\t\t\t\t" << this_thread::get_id() << endl;
    cout << "Thread执行3s......" << endl;
    sleep(3);

    return i;
}

int main()
{
    cout << "主线程开始--------------------" << this_thread::get_id() << endl;
    cout << endl;

    packaged_task<int(int)> pt1(Thread);     //把函数Thread通过package_task包装起来 返回值int 参数int
    thread t1(ref(pt1), 10);     //参数10
    t1.join();
    future<int> f1 = pt1.get_future();
    int value1 = f1.get();
    cout << "Thread返回值:" << value1 << endl;
    cout << endl;
    sleep(1);

    packaged_task<int(int)> pt2([](int i)
                                {
                                    cout << "Thread:\t\t\t\t\t\t" << this_thread::get_id() << endl;
                                    cout << "Thread执行3s......" << endl;
                                    sleep(3);

                                    return i;
                                });     //packaged_task包装lambda
    thread t2(ref(pt2), 20);
    t2.join();
    future<int> f2 = pt2.get_future();
    int value2 = f2.get();
    cout << "Thread返回值:" << value2 << endl;
    cout << endl;
    sleep(1);

    packaged_task<int(int)> pt3(Thread);
    pt3(30);    //pt3作为函数直接调用 在主线程中执行
    future<int> f3 = pt3.get_future();
    int value3 = f3.get();
    cout << "Thread返回值:" << value3 << endl;
    cout << endl;

    cout << "主线程结束--------------------" << endl;

    return 0;
}
