#include <iostream>
using namespace std;

class A
{
public:
    A(int i)
    {
        this->i = i;
    }

    int i;
};

class B
{
public:
    //声明explicit避免隐式调用构造函数
    //explicit关键字只能用于类内部的构造函数声明上
    //explicit关键字作用于单个参数的构造函数
    //被explicit修饰的构造函数的类 不能发生相应的隐式类型转换
    explicit B(int i)
    {
        this->i = i;
    }

    int i;
};

int main()
{
    A a1(10);
    A a2 = 20;
    cout << a1.i << " " << a2.i << endl;

    B b(30);
    cout << b.i << endl;

    return 0;
}