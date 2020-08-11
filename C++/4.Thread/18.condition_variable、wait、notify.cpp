#include <iostream>
#include <thread>
#include <unistd.h>
#include <list>
#include <mutex>
using namespace std;

#define NUM 10000

class Thread
{
public:
    void Push()
    {
        sleep(1);   //延迟1s保证Pop线程先执行 堵塞在wait

        for(int i = 1; i <= NUM; i++)
        {
            unique_lock<mutex> ul_m(m);
            cout << "Push 加锁" << endl;

            l.push_back(i);
            cout << "Push:" << i << endl;

            cv.notify_one();    //尝试把wait唤醒 只有堵塞在wait才会被唤醒 否则唤醒没有作用 每次只能唤醒一个wait
            //cv.notify_all();    //唤醒全部wait
            cout << "尝试唤醒 wait" << endl;

            cout << "Push 解锁" << endl;
            ul_m.unlock();      //提前解锁

            //usleep(5e5);        //保证Pop每次唤醒前都堵塞在wait 则会一次Push一次Pop
        }

        sleep(1);   //等待所有元素Pop
        exit(0);
    }

    void Pop()
    {
        int value = 0;

        while(true)
        {
            unique_lock<mutex> ul_m(m);

            //第二个参数:谓词
            //若返回true 继续向下执行
            //若返回false wait将解锁互斥量并堵塞在wait 直到其他线程调用notify解除堵塞
            //若没有第二个参数 按返回false处理
            //wait被notify_one唤醒后 不断尝试加锁 直到加锁成功 继续向下执行
            //因此wait一旦向下执行 一定是加锁成功

            cout << "wait 堵塞" << endl;
            cout << endl;
            cv.wait(ul_m, [this]() { return !l.empty(); });     //被唤醒且返回true后解除堵塞 尝试加锁
            cout << "wait 解除堵塞" << endl;

            if(ul_m.owns_lock())
            {
                cout << "Pop加锁" << endl;
            }

            cout << "--------------------size=" << l.size() << endl;
            value = l.front();
            l.pop_front();
            cout << "----------Pop:" << value << endl;

            cout << "Pop解锁" << endl;
            ul_m.unlock();      //可以提前解锁
        }
    }

private:
    list<int> l;
    mutex m;
    condition_variable cv;  //条件变量对象
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
