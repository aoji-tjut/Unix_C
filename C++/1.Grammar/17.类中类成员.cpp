#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A构造函数" << endl;
    }

    ~A()
    {
        cout << "A析构函数" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B构造函数" << endl;
    }

    ~B()
    {
        cout << "B析构函数" << endl;
    }

private:
    A a;    //类数据成员
};

int main()
{
    B b;    //先类成员后类本身

    return 0;
}