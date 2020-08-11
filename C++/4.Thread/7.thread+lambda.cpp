#include <iostream>
#include <thread>
using namespace std;

int main()
{
    cout << "主线程开始--------------------\t" << endl;
    cout << endl;

    auto lambda = []()
    {
        cout << "Thread" << endl;
    };

    thread t(lambda);
    t.join();
    cout << endl;

    cout << "主线程结束--------------------" << endl;

    return 0;
}