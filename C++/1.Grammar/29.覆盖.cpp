#include <iostream>
using namespace std;

class Father
{
public:
    Father()
    {
        this->age = 40;
    }

    void PrintAge()
    {
        cout << "Father::PrintAge" << endl;
        cout << this->age << endl;
    }

protected:
    int age;
};

class Son : public Father
{
public:
    Son()
    {
        this->age = 10;
    }

    //同名函数成员 子类覆盖父类 父类函数与子类函数不形成函数重载关系
    void PrintAge()
    {
        cout << "Son::PrintAge" << endl;
        cout << this->Father::age << endl;
        cout << this->age << endl;
    }

private:
    int age;    //同名数据成员 子类覆盖父类
};

int main()
{
    Son son;
    son.PrintAge();             //调用子类
    son.Father::PrintAge();     //调用父类

    return 0;
}
