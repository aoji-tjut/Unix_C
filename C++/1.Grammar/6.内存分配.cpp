#include <iostream>
using namespace std;

int g_i = 0;    //全局区

int main()
{
    static int s_i = 0;     //全局/静态区
    int i = 0;              //栈区
    int* p = new int(0);    //堆区

    cout << "全局 " << &g_i << endl;
    cout << "静态 " << &s_i << endl;
    cout << "局部 " << &i << endl;
    cout << "动态 " << p << endl;

    delete p;

    return 0;
}