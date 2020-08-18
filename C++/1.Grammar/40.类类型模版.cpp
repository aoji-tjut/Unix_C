#include <iostream>
using namespace std;

//T为int类型
template<typename T>
class A
{
public:
    A(T t)
    {
        cout << "A构造函数" << endl;
        this->t = t;
    }

    A(const A& a)
    {
        cout << "A拷贝构造函数" << endl;
        this->t = a.t;
    }

    T GetValue()
    {
        return t;
    }

private:
    T t;
};

//T为A类型
template<typename T>
class B
{
public:
    B(T& t) : t(t)   //对象做形参使用引用 必须使用初始化列表
    {
        cout << "B构造函数" << endl;
    }

    void PrintValue()
    {
        cout << typeid(t.GetValue()).name() << " " << t.GetValue() << endl;
    }

private:
    T t;
};

int main()
{
    A<char> a('A');         //A类 传入char类型
    B<A<char>> b(a);        //B类 传入A类类型
    b.PrintValue();

    return 0;
}