#include <iostream>
using namespace std;

class Student
{
public:
    //静态成员不属于对象成员 可以通过类名作用域调用
    static Student* CreateObject()
    {
        if(flag)
        {
            flag = 0;
            return new Student;
        } else
        {
            cout << "创建对象失败" << endl;
            return nullptr;
        }
    }

    ~Student()
    {
        cout << "析构函数" << endl;
        flag = 1;
    }

private:
    static int flag;

    Student()
    {
        cout << "构造函数" << endl;
    }
};

int Student::flag = 1;

int main()
{
    //单例模式每次只能创建一个实例
    Student* p = Student::CreateObject();   //返回Student指针
    cout << p << endl;
    Student* q = Student::CreateObject();   //返回空指针
    cout << q << endl;

    delete p;                               //执行析构函数
    delete q;                               //不执行析构函数
    cout << endl;

    Student* r = Student::CreateObject();
    cout << r << endl;
    delete r;

    return 0;
}