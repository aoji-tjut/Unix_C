#include <iostream>
#include <thread>
#include <unistd.h>
#include <list>
#include <mutex>
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
                //unique_lock<mutex> ul_m(mt);            //仅一个对象拥有mt的所有权
                //unique_lock<mutex> temp = move(ul_m);   //mt所有权转移给temp ul_mt与mt无关
                //mutex* pm = temp.release();             //释放ul_mt与mt的绑定关系后 返回mt指针 需要手动解锁
                //pm->unlock();                           //手动解锁

                //第二个参数
                //使用adopt_lock后不加锁 需要手动在unique_lock前加锁
                //使用try_to_lock后尝试加锁 线程不会因等锁而阻塞
                unique_lock<mutex> ul_m(m, try_to_lock);

                if(ul_m.owns_lock())    //判断是否加锁成功
                {
                    cout << "加锁成功，";
                    l.push_back(i);
                    cout << "Push:" << i << "成功。" << endl;
                } else
                {
                    cout << "加锁失败，";
                    cout << "Push:" << i << "失败，";
                    cout << "等待重新加锁。" << endl;
                }
            }   //析构解锁

            sleep(1);
        }
    }

    void Pop()
    {
        int value = 0;

        while(true)
        {
            sleep(2);

            {
                //使用defer_lock后初始化了一个没有加锁的m 需要手动加锁
                unique_lock<mutex> ul_m(m, defer_lock);
                ul_m.lock();    //手动加锁

                //if (ul_m.try_lock())    //用法同try_to_lock 不阻塞线程
                //{
                //   ...
                //}

                sleep(1);   //unique_lock加锁后sleep Push线程不会因等锁而阻塞

                if(l.empty())
                {
                    cout << "链表为空。" << endl;
                    exit(0);
                } else
                {
                    value = l.front();
                    l.pop_front();
                    cout << "----------Pop:" << value << "成功。" << endl;
                }

                ul_m.unlock();      //手动解锁 也可不手动解锁 使用析构解锁
            }   //若没有手动解锁 则析构解锁
        }
    }

private:
    list<int> l;
    mutex m;
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
