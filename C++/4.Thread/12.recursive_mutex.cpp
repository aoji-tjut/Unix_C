#include <iostream>
#include <thread>
using namespace std;

class A
{
public:
    void Thread()
    {
        cout << "Thread开始" << endl;
        lock_guard<recursive_mutex> lg_rm(rm);
        SubThread();
        cout << "Thread结束" << endl;
    }

    void SubThread()
    {
        cout << "SubThread开始" << endl;
        lock_guard<recursive_mutex> lg_rm(rm);
        cout << "SubThread结束" << endl;
    }

private:
    recursive_mutex rm;     //递归锁 同一个锁可以嵌套加锁
};

int main()
{
    A obj;
    thread t(&A::Thread, &obj);
    t.join();

    return 0;
}