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

    virtual void PrintValue()
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

    //重写
    void PrintValue() override
    {
        cout << "Son::PrintValue" << endl;
        cout << typeid(t).name() << " " << t << endl;
    }

private:
    T t;
};

int main()
{
    Father<int>* p = new Son<int>(5);
    p->PrintValue();
    p->Father::PrintValue();
    delete p;

    return 0;
}