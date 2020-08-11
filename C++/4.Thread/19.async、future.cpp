#include <iostream>
#include <thread>
#include <unistd.h>
#include <future>   //用于多个线程之间通信
using namespace std;

int Thread(int i)
{
    cout << "Thread:\t\t\t\t\t\t" << this_thread::get_id() << endl;
    cout << "Thread执行3s......" << endl;
    sleep(3);

    return i;
}

class A
{
public:
    int Thread(int i)
    {
        cout << "Thread:\t\t\t\t\t\t" << this_thread::get_id() << endl;
        cout << "Thread执行3s......" << endl;
        sleep(3);

        return i;
    }
};

int main()
{
    cout << "主线程开始--------------------" << this_thread::get_id() << endl;
    cout << endl;

    //thread一定创建新线程 若系统资源紧张则创建线程失败 程序崩溃 不能接收返回值
    //async创建异步任务 不一定创建新线程  可以接收返回值

    //launch::async    创建异步任务(新线程) 主线程继续执行 返回future<>值
    //launch::deferred 延迟创建同步任务(非新线程) 直到调用wait或get时才执行(在主线程中执行) 返回future<>值
    //默认值 launch::async | launch::deferred 具体调用形式由系统决定 使用future<>::wait_for()返回的future_status判断

    future<int> f1 = async(launch::async, Thread, 10);
    //f1.wait();  //主线程阻塞 等待Thread返回 不返回结果
    int value1 = f1.get();  //主线程阻塞 等待Thread返回 返回结果 get只能使用一次(移动语义 get后result为空)
    cout << "Thread返回值:" << value1 << endl;
    cout << endl;
    sleep(1);

    future<int> f2 = async(launch::deferred, Thread, 20);
    cout << "Thread延迟1s执行" << endl;
    sleep(1);
    int value2 = f2.get();
    cout << "Thread返回值:" << value2 << endl;
    cout << endl;
    sleep(1);

    A a;
    future<int> f3 = async(&A::Thread, &a, 30);
    int value3 = f3.get();
    cout << "A::Thread返回值:" << value3 << endl;
    cout << endl;

    cout << "主线程结束--------------------" << endl;

    return 0;
}
