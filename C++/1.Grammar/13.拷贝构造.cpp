#include <iostream>
using namespace std;

class Student
{
public:
    Student()
    {
        cout << "无参构造函数" << endl;
    }

    Student(int age)
    {
        cout << "有参构造函数" << endl;
        this->age = age;
    }

    //拷贝构造函数 如果自定义了拷贝构造 系统不会保留默认的构造函数 需要自己定义
    Student(const Student& stu)
    {
        cout << "拷贝构造函数" << endl;
        this->age = stu.age;
    }

    void Show()
    {
        cout << this->age << endl;
    }

private:
    int age;
};

Student Fun1(Student stu)
{
    cout << &stu << endl;
    return stu;
}

Student& Fun2(Student& stu)
{
    cout << &stu << endl;
    return stu;
}

int main()
{
    Student stu(20);                //调用有参构造
    Student stu1(stu);              //调用拷贝构造
    Student stu2 = stu;             //调用拷贝构造
    Student stu3 = Student(stu);    //调用拷贝构造
    Student stu4;                   //调用无参构造
    stu4 = stu;                     //赋值运算不调用拷贝构造
    cout << endl;

    stu.Show();
    stu1.Show();
    stu2.Show();
    stu3.Show();
    stu4.Show();
    cout << endl;

    Student* p = new Student(stu);  //调用拷贝构造
    p->Show();
    delete p;
    cout << endl;

    cout << &stu << endl;
    Student temp = Fun1(stu);       //参数和返回值是对象时调用拷贝构造 关闭优化-fno-elide-constructors
    cout << &temp << endl;
    cout << endl;

    cout << &stu << endl;
    cout << &Fun2(stu) << endl;     //参数和返回值是对象的引用时不调用拷贝构造

    return 0;
}