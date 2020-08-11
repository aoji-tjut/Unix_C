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
            lock(m1, m2);   //同时锁两个 若一个加锁成功另一个加锁失败 则把已加锁的解锁 重新加锁
            cout << "Push->m1/m2->lock" << endl;

            {
                lock_guard<mutex> lg_m1(m1, adopt_lock);    //使用adopt_lock后不加锁
                lock_guard<mutex> lg_m2(m2, adopt_lock);

                l.push_back(i);
                cout << "Push:" << i << endl;
            }   //解锁

            cout << "Push->m1/m2->unlock" << endl;
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

            lock(m1, m2);
            cout << "Pop->m1/m2->lock" << endl;

            {
                lock_guard<mutex> lg_m1(m1, adopt_lock);
                lock_guard<mutex> lg_m2(m2, adopt_lock);

                if(l.empty())
                {
                    cout << "链表为空" << endl;
                    exit(0);
                } else
                {
                    value = l.front();
                    l.pop_front();
                    cout << "----------Pop:" << value << endl;
                }
            }

            cout << "Pop->m1/m2->unlock" << endl;
            cout << endl;
        }
    }

private:
    list<int> l;
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


