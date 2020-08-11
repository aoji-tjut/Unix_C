#include <iostream>
#include <thread>
#include <atomic>   //原子操作 仅能操作单个变量 不能操作一段代码 比互斥量效率高
using namespace std;

void Thread1(atomic<int>& a)
{
    for(int i = 0; i < 10000000; i++)
    {
        a++;    //原子操作运算符只支持++/--/+=/-=...... 不支持a = ...

        //a.load();   //读
        //a.store(100);   //写
    }
}

void Thread2(atomic<int>& a)
{
    while(a!=20000000)
    {
        cout << a << endl;      //此语句不是原子操作
    }
}

int main()
{
    atomic<int> a(0);   //整形原子量 类似于互斥量锁住了a 多个线程之间不会干扰

    thread t1(Thread1, ref(a));
    thread t2(Thread1, ref(a));
    thread t3(Thread2, ref(a));
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
