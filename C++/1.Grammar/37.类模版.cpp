#include <iostream>
using namespace std;

//类模版 可以有默认类型 仅对下面第一个类有效
//使用类模版时 除定义类以外 都需要声明模版参数列表：class<...>
template<typename T=int>
class Student
{
public:
    Student(T t)
    {
        this->t = t;
    }

    void PrintValue();

private:
    T t;
};

//类外实现需要使用函数模版
template<typename T>
void Student<T>::PrintValue()
{
    cout << typeid(t).name() << " " << t << endl;
}

int main()
{
    Student<int> stu1(5);
    stu1.PrintValue();

    Student<double> stu2(5.5);
    stu2.PrintValue();

    Student<char> stu3('A');
    stu3.PrintValue();

    Student<char>* p = new Student<char>('A');
    p->PrintValue();
    delete p;

    Student<> stu4('A');    //使用默认类型
    stu4.PrintValue();

    return 0;
}