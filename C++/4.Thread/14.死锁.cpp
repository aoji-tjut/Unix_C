#include <iostream>
#include <thread>
#include <unistd.h>
#include <list>
#include <mutex>
using namespace std;

#define NUM 200

class Thread
{
public:
    void Push()
    {
        for(int i = 1; i <= NUM; i++)
        {
            m1.lock();
            cout << "Push->m1->lock" << endl;
            m2.lock();
            cout << "Push->m2->lock" << endl;

            l.push_back(i);
            cout << "Push:" << i << endl;

            m2.unlock();
            cout << "Push->m2->unlock" << endl;
            m1.unlock();
            cout << "Push->m1->unlock" << endl;
            cout << endl;

            usleep(10000);
        }
    }

    void Pop()
    {
        int value = 0;

        while(true)
        {
            usleep(20000);

            m2.lock();
            cout << "Pop->m2->lock" << endl;
            m1.lock();
            cout << "Pop->m1->lock" << endl;

            if(l.empty())
            {
                cout << "链表为空" << endl;

                m1.unlock();
                cout << "Pop->m1->unlock" << endl;
                m2.unlock();
                cout << "Pop->m2->unlock" << endl;

                exit(0);
            } else
            {
                value = l.front();
                l.pop_front();
                cout << "----------Pop:" << value << endl;

                m1.unlock();
                cout << "Pop->m1->unlock" << endl;
                m2.unlock();
                cout << "Pop->m2->unlock" << endl;
                cout << endl;
            }
        }
    }

private:
    list<int> l;

    //多个线程多个互斥量 线程加锁的顺序不同 可能产生死锁
    //每个线程加锁顺序一致可避免死锁
    mutex m1;
    mutex m2;
};

int main()
{
    Thread obj;
    thread thread_push(&Thread::Push, &obj);
    thread thread_pop(&Thread::Pop, &obj);

    thread_push.join();
    thread_pop.join();

    return 0;
}
