#include <iostream>
#include <thread>
using namespace std;

class Thread
{
public:
    Thread()
    {
        this->flag = true;
        cout << "构造函数" << "\t\t\t\t " << this << " " << this_thread::get_id() << endl;
    }

    Thread(const Thread& t)
    {
        this->flag = false;
        cout << "拷贝构造函数" << "\t\t\t " << this << " " << this_thread::get_id() << endl;
    }

    ~Thread()
    {
        if(flag)
        {
            cout << "构造函数析构函数\t\t" << " " << this << " " << this_thread::get_id() << endl;
        } else
        {
            cout << "拷贝构造函数析构函数\t" << " " << this << " " << this_thread::get_id() << endl;
        }
    }

    void Fun(int value)
    {
        cout << "成员函数 " << value << endl;
    }

    bool flag;  //记录析构函数的种类
};

int main()
{
    cout << "主线程开始--------------------\t\t" << this_thread::get_id() << endl;
    cout << endl;

    Thread obj;
    cout << endl;

    thread t1(&Thread::Fun, obj, 100);      //成员函数地址 类对象 成员函数参数
    t1.join();
    cout << endl;

    thread t2(&Thread::Fun, &obj, 200);     //成员函数地址 this 成员函数参数
    t2.join();
    cout << endl;

    cout << "主线程结束--------------------" << endl;

    return 0;
}