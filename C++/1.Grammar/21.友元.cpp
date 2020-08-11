#include <iostream>
using namespace std;

class A
{
    //声明友元函数 可以访问A所有成员 不属于类内函数成员
    friend void Friend();

    //声明友元类 可以访问A所有成员 不属于类内数据成员
    friend class B;

    int age = 20;
};

class B
{
public:
    B()
    {
        cout << "友元类" << endl;
        cout << a.age << endl;
    }

private:
    A a;
};

void Friend()
{
    cout << "友元函数" << endl;
    A a;
    cout << a.age << endl;
}

int main()
{
    Friend();
    cout << endl;

    B b;

    return 0;
}