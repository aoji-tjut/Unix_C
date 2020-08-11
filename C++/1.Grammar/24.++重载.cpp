#include <iostream>
using namespace std;

class Student
{
    friend ostream& operator<<(ostream& os, Student& stu);

public:
    Student()
    {
        this->num = 0;
    }

    int GetNum()
    {
        cout << this << endl;
        return this->num;
    }

    //前置++重载
    Student& operator++();
    //后置++重载
    Student operator++(int);    //占位参数 产生重载效果

private:
    int num;
};

ostream& operator<<(ostream& os, Student& stu)
{
    os << stu.num;
    return os;
}

Student& Student::operator++()      //返回对象引用可对对象本身连续操作
{
    cout << this << endl;
    this->num++;
    return *this;
}

Student Student::operator++(int)
{
    cout << this << endl;
    Student temp = *this;
    this->num++;
    return temp;    //不能返回局部变量引用
}

int main()
{
    Student stu1;
    Student stu2;
    cout << &stu1 << endl;
    cout << &stu2 << endl;
    cout << endl;

    //前置++ 返回对象引用
    cout << ++stu1 << endl;
    cout << stu1 << endl;
    cout << ++(++stu1) << endl;
    cout << stu1 << endl;
    cout << endl;

    //后置++ 返回对象拷贝
    cout << (stu2++).GetNum() << endl;
    cout << stu2 << endl;
    cout << ((stu2++)++).GetNum() << endl;
    cout << stu2 << endl;

    return 0;
}
