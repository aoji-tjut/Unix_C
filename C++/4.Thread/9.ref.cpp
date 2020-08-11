#include <iostream>
#include <thread>
using namespace std;

class A
{
public:
    A(int value) : value(value)
    {
        cout << "构造函数\t\t\t" << this << " " << endl;
    }

    A(const A& a) : value(a.value)
    {
        cout << "拷贝构造函数\t\t" << this << " " << endl;
    }

    ~A()
    {
        cout << "析构函数\t\t\t" << this << " " << endl;
    }

    mutable int value;  //声明mutable后可以在任何地方修改value
};

void Thread1(const A& a)
{
    cout << "Thread1\t\t\t" << &a << " " << a.value << endl;
    a.value = 200;
}

void Thread2(A& a)
{
    cout << "Thread2\t\t\t" << &a << " " << a.value << endl;
    a.value = 200;
}

int main()
{
    cout << "主线程开始--------------------" << endl;
    cout << endl;

    A a(100);
    cout << "main\t\t\t" << &a << " " << a.value << endl;
    cout << endl;

    thread t1(Thread1, a);       //直接传入a会调用拷贝构造 不是同一块内存
    t1.join();
    cout << "main\t\t\t" << &a << " " << a.value << endl;
    cout << endl;

    thread t2(Thread2, ref(a));  //传入ref(a)则传入同一块内存 使用ref不要使用detach 使用ref后形参可以不用const修饰
    t2.join();
    cout << "main\t\t\t" << &a << " " << a.value << endl;
    cout << endl;

    cout << "主线程结束--------------------" << endl;

    return 0;
}
