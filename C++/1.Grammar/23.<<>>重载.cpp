#include <iostream>
using namespace std;

class Student
{
    //>>重载 必须类外重载 否则object >> cin
    friend istream& operator>>(istream& is, Student& stu);
    //<<重载 必须类外重载 否则object << cout
    friend ostream& operator<<(ostream& os, Student& stu);

public:
    Student()
    {
        this->num = 0;
    }

private:
    int num;
};

istream& operator>>(istream& is, Student& stu)
{
    is >> stu.num;
    return is;  //返回引用实现连续运算
}

ostream& operator<<(ostream& os, Student& stu)
{
    os << stu.num;
    return os;  //返回引用实现连续运算
}

int main()
{
    Student stu;
    cin >> stu;
    cout << stu << endl;

    return 0;
}
