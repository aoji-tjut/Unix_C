#include <iostream>
#include <thread>
#include <memory>
using namespace std;

class A
{
public:
    A(int value) : value(value)
    {
        cout << "构造函数\t\t" << this << " " << endl;
    }

    ~A()
    {
        cout << "析构函数\t\t" << this << " " << endl;
    }

    int value;
};

void Thread(unique_ptr<A> p)
{
    cout << "Thread\t\t" << p << " " << p->value << endl;
}

int main()
{
    cout << "主线程开始--------------------" << endl;
    cout << endl;

    unique_ptr<A> p(new A(100));
    cout << "main\t\t" << p << " " << p->value << endl;

    thread t(Thread, move(p));      //move后p指向空
    t.join();

    cout << endl;
    cout << "主线程结束--------------------" << endl;

    return 0;
}
