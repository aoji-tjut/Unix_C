#include <iostream>
using namespace std;

class A
{
public:
    //捕捉this
    void Fun()
    {
        [this]()
        {
            cout << "捕捉this" << endl;
            cout << this << endl;
        }();
    }
};

void Test1()
{
    int i = 0;

    auto fun = [i]()mutable
    {
        cout << i << endl;
        i++;
    };

    i = 100;

    fun();
    fun();
    fun();

    cout << i << endl;
}

void Test2()
{
    int i = 0;

    auto fun = [&i]()
    {
        cout << i << endl;
        i++;
    };

    i = 100;

    fun();
    fun();
    fun();

    cout << i << endl;
}

int main()
{
    //[捕捉](参数)mutable/throwSpec->返回值类型{函数体}

    //无名
    []() { cout << "lambda" << endl; }();
    cout << endl;

    //有参
    [](const char* str) { cout << str << endl; }("lambda");
    cout << endl;

    //有名
    auto fun1 = []() { cout << "lambda" << endl; };
    fun1();
    cout << endl;

    //返回值
    auto fun2 = []() -> int
    {
        cout << "lambda" << endl;
        return 1;
    };
    cout << fun2() << endl;
    cout << endl;

    int i = 1, j = 2;
    cout << "\t\t\t\t" << &i << " " << i << endl;
    cout << "\t\t\t\t" << &j << " " << j << endl;

    //赋值捕捉
    auto fun3 = [=]()
    {
        cout << "赋值捕捉" << endl;
        cout << &i << " " << i << endl;
        cout << &j << " " << j << endl;
    };
    fun3();
    cout << endl;

    //引用捕捉
    auto fun4 = [&]()
    {
        cout << "引用捕捉" << endl;
        cout << &i << " " << i << endl;
        cout << &j << " " << j << endl;
    };
    fun4();
    cout << endl;

    //只赋值捕捉a
    auto fun5 = [i]()
    {
        cout << "只赋值捕捉a" << endl;
        cout << &i << " " << i << endl;
    };
    fun5();
    cout << endl;

    //只引用捕捉a
    auto fun6 = [&i]()
    {
        cout << "只引用捕捉a" << endl;
        cout << &i << " " << i << endl;
    };
    fun6();
    cout << endl;

    //赋值捕捉 但引用捕捉a
    auto fun7 = [=, &i]()
    {
        cout << "赋值捕捉 但引用捕捉a" << endl;
        cout << &i << " " << i << endl;
        cout << &j << " " << j << endl;
    };
    fun7();
    cout << endl;

    //引用捕捉 但赋值捕捉a
    auto fun8 = [&, i]()
    {
        cout << "引用捕捉 但赋值捕捉a" << endl;
        cout << &i << " " << i << endl;
        cout << &j << " " << j << endl;
    };
    fun8();
    cout << endl;

    A a;
    cout << &a << endl;
    a.Fun();
    cout << endl;

    Test1();
    cout << endl;

    Test2();
    cout << endl;

    return 0;
}