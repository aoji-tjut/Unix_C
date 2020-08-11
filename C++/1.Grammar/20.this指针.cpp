#include <iostream>
using namespace std;

class Student
{
public:
    //普通函数内this指针类型 指针常量 Student* const this 指针指向不可修改 指向的值可以修改
    Student* This()
    {
        cout << "This" << endl;
        cout << typeid(this).name() << endl;
        return this;
    }

    //常函数内this指针类型 常量指针常量 const Student* const this
    void Const() const
    {
        cout << "Const " << endl;
        cout << typeid(this).name() << endl;
        cout << this << endl;
    }

    //静态函数没有this指针
    static void Static()
    {
        cout << "Static" << endl;
    }
};

int main()
{
    Student stu;
    cout << &stu << endl;
    cout << endl;

    cout << stu.This() << endl;
    cout << endl;

    stu.Const();
    cout << endl;

    stu.Static();

    return 0;
}