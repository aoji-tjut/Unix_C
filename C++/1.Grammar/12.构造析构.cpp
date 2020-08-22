#include <iostream>
using namespace std;

class Student
{
public:
    //构造函数 无返回值 可以有参数 可重载
    Student()
    {
        cout << "构造函数" << endl;
        this->age = 20;
    }

    //析构函数 无返回值 无参数 不可重载
    ~Student()
    {
        cout << "析构函数" << endl;
    }

    void Show()
    {
        cout << this->age << endl;
    }

private:
    int age;
};

int main()
{
    Student().Show();           //临时对象
    cout << endl;

    Student stu;                //定义栈区对象调用构造
    stu.Show();
    cout << endl;

    Student* p;                 //指针指向对象不调用构造
    p = &stu;
    p->Show();
    cout << endl;

    Student* q = new Student;   //定义堆区对象调用构造
    q->Show();
    delete q;                   //堆区对象调用析构
    cout << endl;

    return 0;
}                               //栈区对象调用析构