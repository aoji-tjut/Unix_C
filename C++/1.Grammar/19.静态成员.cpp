#include <iostream>
using namespace std;

class Student
{
public:
    Student()
    {
        cout << "构造函数 " << ++this->num << endl;
    }

    //静态成员函数 属于类本身 不属于对象 只能访问静态数据成员
    static void Static()
    {
        cout << num << endl;
        cout << "静态成员函数" << endl;
    }

    static int num;     //静态数据成员必须类外初始化 属于类本身 不属于对象
};

int Student::num = 0;   //注意格式：类型 类名::成员 = 值

int main()
{
    cout << Student::num << endl;
    Student::Static();
    cout << endl;

    Student stu[10];

    return 0;
}