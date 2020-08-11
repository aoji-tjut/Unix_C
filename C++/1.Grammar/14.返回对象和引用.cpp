#include <iostream>
using namespace std;

class Student
{
public:
    Student()
    {
        cout << "构造函数" << endl;
    }

    Student(const Student& stu)
    {
        cout << "拷贝构造函数" << endl;
    }

    Student(Student&& stu)
    {
        cout << "移动构造函数" << endl;
    }
};

//无参 返回局部对象
Student Fun1()
{
    Student stu;
    cout << &stu << endl;
    return stu;     //stu是临时对象 返回时调用移动构造
}

//无参 返回局部对象引用
Student& Fun2()
{
    Student stu;
    cout << &stu << endl;
    return stu;
}

//传入对象 返回形参对象
Student Fun3(Student stu)
{
    cout << &stu << endl;
    return stu;     //stu是临时对象 返回时调用移动构造
}

//传入对象 返回形参对象引用
Student& Fun4(Student stu)
{
    cout << &stu << endl;
    return stu;
}

//传入对象引用 返回形参对象
Student Fun5(Student& stu)
{
    cout << &stu << endl;
    return stu;     //stu不是临时对象 返回时调用拷贝构造
}

//传入对象引用 返回形参对象引用
Student& Fun6(Student& stu)
{
    cout << &stu << endl;
    return stu;
}

int main()
{
    Student stu;
    cout << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //无参 返回局部对象(临时对象) 不能直接输出临时对象地址 需要临时变量接收
    Student temp1 = Fun1();     //C++98执行2次拷贝构造 C++11执行2次移动构造函数
    cout << &temp1 << endl;     //因编译器优化所以地址相同
    cout << endl;

    //无参 返回局部对象引用
    cout << &Fun2() << endl;
    cout << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //传入对象 返回形参对象(临时对象) 不能直接输出临时对象地址 需要临时变量接收
    cout << &stu << endl;
    Student temp2 = Fun3(stu);  //C++98执行3次拷贝构造 C++11执行1次拷贝构造2次移动构造
    cout << &temp2 << endl;
    cout << endl;

    //传入对象 返回形参对象引用
    cout << &stu << endl;
    cout << &Fun4(stu) << endl;
    cout << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //传入对象引用 返回形参对象(临时对象) 不能直接输出临时对象地址 需要临时变量接收
    cout << &stu << endl;
    Student temp3 = Fun5(stu);  //C++98执行2次拷贝构造 C++11执行1次拷贝构造1次移动构造
    cout << &temp3 << endl;
    cout << endl;

    //传入对象引用 返回形参对象引用
    cout << &stu << endl;
    cout << &Fun6(stu) << endl;
    cout << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}
//-fno-elide-constructors 取消优化返回值