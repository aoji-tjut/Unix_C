#include <iostream>
using namespace std;

class A
{
public:
    virtual void Fun1()
    {
        cout << "A::Fun1" << endl;
    }

    virtual void Fun2() final   //声明子类无法重写此虚函数 final只能修饰虚函数和类
    {
        cout << "A::Fun2" << endl;
    }
};

class B final : public A    //声明B类不可以再被其他类继承 B类下没有子类
{
public:
    void Fun1() override    //声明子类重写此函数 override只能修饰虚函数
    {
        cout << "B::Fun1" << endl;
    }
};

void Fun() noexcept     //声明不会抛出异常 若抛出异常会调用std::terminate()终止程序运行
{
    cout << "Fun" << endl;
}

int main()
{
    Fun();

    A a;
    a.Fun1();
    a.Fun2();

    B b;
    b.Fun1();
    b.Fun2();

    return 0;
}