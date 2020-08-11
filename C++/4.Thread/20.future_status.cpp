#include <iostream>
#include <thread>
#include <unistd.h>
#include <future>
using namespace std;

int Thread(int i)
{
    cout << "Thread:" << endl;
    cout << "Thread执行3s......" << endl;
    sleep(3);

    return i;
}

int main()
{
    future<int> f = async(launch::async, Thread, 10);
    future_status fs = f.wait_for(1s);  //主线程阻塞 等待1s

    if(fs == future_status::timeout)
    {
        cout << "future_status::timeout Thread没有执行完毕" << endl;
    } else if(fs == future_status::ready)
    {
        cout << "future_status::ready Thread执行完毕" << endl;
        auto value = f.get();
        cout << "result=" << value << endl;
    } else if(fs == future_status::deferred)    //使用launch::deferred时有此状态
    {
        cout << "future_status::deferred Thread延迟执行" << endl;
        auto value = f.get();
        cout << "result=" << value << endl;
    }

    return 0;
}
