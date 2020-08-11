#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
class Father
{
public:
    Father(T t)
    {
        this->t = t;
    }

    void PrintValue()
    {
        cout << "Father::PrintValue" << endl;
        cout << typeid(t).name() << " " << t << endl;
    }

private:
    T t;
};

template<typename T>
class Son : public Father<T>
{
public:
    Son(T t) : Father<T>(t)     //初始化列表
    {
        this->t = t;
    }

    //覆盖
    void PrintValue()
    {
        cout << "Son::PrintValue" << endl;
        cout << typeid(t).name() << " " << t << endl;
    }

private:
    T t;
};

int main()
{
    Father<int> father(5);
    father.PrintValue();

    Son<int> son(5);
    son.PrintValue();

    return 0;
}