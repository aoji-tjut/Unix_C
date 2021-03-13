#include <iostream>
using namespace std;

class A
{
public:
    A() = default;      //指定默认构造函数

    A(int i)
    {
        cout << i << endl;
    }

    A(char c) = delete;         //禁用字符构造

    A(const A& a) = delete;     //禁用拷贝构造函数

    void Fun()
    {
        cout << "Fun" << endl;
    }
};

class B : public A
{
public:
    void Fun() = delete;   //B类中禁用Fun
};

int main()
{
    A a;
    a.Fun();

    return 0;
}