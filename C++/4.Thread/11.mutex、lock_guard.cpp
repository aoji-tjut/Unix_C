#include <iostream>
#include <thread>
#include <unistd.h>
#include <list>
#include <mutex>    //互斥量 仅仅保护共享数据代码 锁住代码越少效率越高
using namespace std;

#define NUM 20

class Thread
{
public:
    void Push()
    {
        for(int i = 1; i <= NUM; i++)
        {
            {
                lock_guard<mutex> lg_m(m);      //使用lock_guard后不再使用lock和unlock lock_guard构造函数加锁 析构函数解锁
                l.push_back(i);
                cout << "Push:" << i << endl;
            }   //此处lock_guard析构函数解锁

            sleep(1);   //必须在sleep之前解锁 否则sleep过程中其他线程仍拿不到锁 sleep后解锁可能马上又被Push加锁
        }
    }

    void Pop()
    {
        int value = 0;

        while(true)
        {
            sleep(2);

            m.lock();   //加锁

            if(l.empty())
            {
                cout << "链表为空" << endl;
                m.unlock();     //解锁
                exit(0);
            } else
            {
                value = l.front();
                l.pop_front();
                cout << "----------Pop:" << value << endl;
                m.unlock();     //解锁
            }
        }
    }

    void Read()
    {
        while(true)
        {
            sleep(2);

            m.lock();           //加锁

            if(l.empty())
            {
                cout << "链表为空" << endl;
                m.unlock();     //解锁
                exit(0);
            } else
            {
                cout << "--------------------Read:";
                for(auto it = l.begin(); it != l.end(); it++)
                {
                    cout << *it << " ";
                }
                cout << endl << endl;
                m.unlock();     //解锁
            }
        }
    }

private:
    list<int> l;    //双向循环链表
    mutex m;        //独占锁 同一个锁只能加锁一次
};

int main()
{
    Thread obj;
    thread thread_push(&Thread::Push, &obj);    //相当于传入this
    thread thread_pop(&Thread::Pop, &obj);
    thread thread_read(&Thread::Read, &obj);

    thread_push.join();
    thread_pop.join();
    thread_read.join();

    return 0;
}
