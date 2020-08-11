#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex g_m;
once_flag g_flag;

//单例类
class Singleton
{
public:
    static void CreateInstance()
    {
        cout << "CreateInstance()" << endl;
        instance = new Singleton;
        static Release release;
    }

    static Singleton* GetInstance()
    {
        /*
        //双重锁定 提高效率 只有instance为空时才加锁
        if(instance == nullptr)
        {
            unique_lock<mutex> ul_m(g_m);
            if(instance == nullptr)
            {
                instance = new Singleton;
                static Release release;
            }
        }
        */

        call_once(g_flag, CreateInstance);   //g_flag类似锁 CreateInstance只执行一次

        return instance;
    }

private:
    Singleton()
    {
        cout << "单例模式构造函数" << endl;
    }

    class Release
    {
    public:
        ~Release()
        {
            if(Singleton::instance)
            {
                cout << "单例模式析构函数" << endl;
                delete Singleton::instance;
                Singleton::instance = nullptr;
            }
        }
    };

    static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;//静态成员初始化


void Thread()
{
    cout << "Thread" << endl;
    Singleton* obj = Singleton::GetInstance();
    cout << obj << endl;
}

int main()
{
    vector<thread> v;
    v.reserve(10);
    for(int i = 0; i < 100; i++)
    {
        v.emplace_back(Thread);
    }
    for(auto it = v.begin(); it != v.end(); it++)
    {
        it->join();
    }

    return 0;
}



