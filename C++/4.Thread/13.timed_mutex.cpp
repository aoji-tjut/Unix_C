#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

class A
{
public:
    void Thread1()
    {
        cout << "Thread1开始" << endl;

        rm.lock();
        cout << "Thread1加锁成功" << endl;
        cout << "Thread1延时2s......" << endl;
        sleep(2);   //2s后Thread1解锁 Thread2尝试加锁
        cout << "Thread1解锁成功" << endl;
        rm.unlock();

        cout << "Thread1结束" << endl;
    }

    void Thread2()
    {
        cout << "Thread2开始" << endl;

        //if(rm.try_lock_until(chrono::steady_clock::now() + 3s))
        if(rm.try_lock_for(3s))     //在3s内尝试加锁 阻塞3s
        {
            cout << "Thread2加锁成功" << endl;
            cout << "Thread2解锁成功" << endl;
        } else      //超时3s后加锁失败 解除堵塞
        {
            cout << "Thread2加锁失败" << endl;
        }

        cout << "Thread2结束" << endl;
    }

private:
    timed_mutex rm;     //定时锁 一定时间内没有加锁成功则不会堵塞线程
};

int main()
{
    A obj;
    thread t1(&A::Thread1, &obj);
    sleep(1);   //1s后启动Thread2线程
    thread t2(&A::Thread2, &obj);

    t1.join();
    t2.join();

    return 0;
}