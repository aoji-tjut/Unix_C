#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int& j = i;     //j是i的引用=取别名 j与i指向同一块内存 引用必须初始化 引用之后不能改变 引用本质是指针常量

    cout << &i << " " << i << endl;
    cout << &j << " " << j << endl;

    i = 5;      //i改变j也改变
    cout << i << " " << j << endl;

    j = 10;     //j改变i也改变
    cout << i << " " << j << endl;

    return 0;
}