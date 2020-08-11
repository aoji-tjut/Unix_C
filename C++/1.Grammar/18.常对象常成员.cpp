#include <iostream>
using namespace std;

class Student
{
public:
    //常数据成员必须使用初始化列表初始化
    Student(int age) : age(age)
    {
        cout << "构造函数" << endl;
    }

    //常函数 只能访问数据成员 不能修改数据成员
    void Const() const
    {
        cout << "常成员函数" << endl;
        cout << this->age << endl;
    }

private:
    const int age;  //常数据成员
};

int main()
{
    const Student stu(20);  //常对象只能调用常函数
    stu.Const();

    return 0;
}