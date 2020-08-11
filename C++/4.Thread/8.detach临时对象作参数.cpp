#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

class A
{
public:
    A(int value) : value(value)
    {
        cout << "构造函数\t\t\t" << this << " " << this_thread::get_id() << endl;
    }

    A(const A& a) : value(a.value)
    {
        cout << "拷贝构造函数\t\t" << this << " " << this_thread::get_id() << endl;
    }

    ~A()
    {
        cout << "析构函数\t\t\t" << this << " " << this_thread::get_id() << endl;
    }

    int value;
};

void Thread1(const int& value, const char* buf)     //引用作参数必须用const 虽然是引用但不是真正的引用 不是同一块内存
{
    cout << "Thread1 value\t" << &value << " " << this_thread::get_id() << endl;
    cout << "Thread1 buf\t\t" << &buf << " " << this_thread::get_id() << endl;
}

void Thread2(const int value, const A& a)
{
    cout << "Thread2 value\t" << &value << " " << this_thread::get_id() << endl;
    cout << "Thread2 a\t\t" << &a << " " << this_thread::get_id() << endl;
}

int main()
{
    cout << "主线程开始--------------------   " << this_thread::get_id() << endl;
    cout << endl;

    int value = 1;
    char buf[] = "Thread";

    cout << "主线程 value\t\t" << &value << endl;
    cout << "主线程 buf\t\t" << &buf << endl;

    thread t1(Thread1, value, buf);         //子线程函数后面的参数为线程函数参数
    t1.detach();                            //detach情况下禁止直接传递引用和指针
    sleep(1);
    cout << endl;

    thread t2(Thread2, value, A(value));    //使用临时对象传递参数 在主线程构造对象 可以保证在主线程结束前传递成功 使用引用接收
    t2.detach();                            //最后一个拷贝构造函数对应的析构函数在子线程执行
    sleep(1);
    cout << endl;

    cout << "主线程结束--------------------" << endl;

    return 0;
}
