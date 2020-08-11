#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

class Thread
{
public:
    Thread(int num)     //不能使用引用传参 在detach情况下 若主线程在子线程前结束 会因main中局部变量释放而产生bug
    {
        this->num = num;
        this->flag = true;
        cout << "构造函数" << this->num << "\t\t\t " << this << " " << this_thread::get_id() << endl;
    }

    Thread(const Thread& t)
    {
        this->num = t.num;
        this->flag = false;
        cout << "拷贝构造函数" << this->num << "\t\t\t " << this << " " << this_thread::get_id() << endl;
    }

    ~Thread()
    {
        if(flag)
        {
            cout << "构造函数" << num << "析构函数" << "\t\t " << this << " " << this_thread::get_id() << endl;
        } else
        {
            cout << "拷贝构造函数" << num << "析构函数" << "\t " << this << " " << this_thread::get_id() << endl;
        }
    }

    void operator()() const
    {
        for(int i = 0; i < 10; i++)
        {
            cout << "Thread" << num << ":" << i << endl;
            usleep(1);  //延迟1us
        }
    }

    int num;    //记录对象
    bool flag;  //记录析构函数的种类
};

int main()
{
    cout << "主线程开始--------------------\t\t" << this_thread::get_id() << endl;

    Thread obj1(1);
    thread t1(obj1);    //obj对象以拷贝构造方式传入线程 不会发生临时对象obj释放导致子线程调度失败的现象
    t1.join();
    cout << endl;

    Thread obj2(2);
    thread t2(obj2);
    t2.detach();    //detach情况下子线程在后台进行 若主线程在子线程前结束 控制台可能看不到子线程析构函数的调用

    cout << "主线程结束--------------------" << endl;

    return 0;
}