#include <iostream>
using namespace std;

typedef int (* pFun)(int, int);     //pFun是函数指针的类型

int Add(int i, int j)
{
    return i + j;
}

int Sub(int i, int j)
{
    return i - j;
}

void CallBack(pFun p)
{
    int i = 5, j = 3;
    cout << p(i, j) << endl;
}

int main()
{
    int i = 5, j = 3;
    int (* p)(int, int);    //函数指针 指向函数的首地址

    p = Add;    //函数指针指向add函数
    cout << p(i, j) << endl;
    p = Sub;    //函数指针指向sub函数
    cout << p(i, j) << endl;
    cout << endl;

    CallBack(Add);
    CallBack(Sub);

    return 0;
}
