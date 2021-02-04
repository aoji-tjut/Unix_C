#include <iostream>
using namespace std;

class Father
{
public:
    Father()
    {
        cout << "Father构造函数" << endl;
    }

    void Fun()
    {
        cout << "Father::Fun" << endl;
    }

    //虚函数 父类声明虚函数后子类对应函数默认都变为虚函数
    //每个虚函数会创建一个vfptr虚函数指针指向vftable虚函数表
    //虚函数表是全局共享的元素 全局仅有一个 在编译时就构造完成
    //虚函数表存储虚函数的地址 虚函数表的元素是指向类成员函数的指针
    //类中虚函数的个数在编译时期可以确定 虚函数表的大小可以确定 不必动态分配内存空间存储虚函数表
    //虚函数表存放在全局数据区
    virtual void VirtualFun()
    {
        cout << "Father::VirtualFun" << endl;
    }

    //虚析构函数 实现多态时 父类析构函数设置为虚函数才会调用子类析构函数
    virtual ~Father()
    {
        cout << "Father析构函数" << endl;
    }
};

class Son1 : public Father
{
public:
    Son1()
    {
        cout << "Son1构造函数" << endl;
    }

    void Fun()
    {
        cout << "Son1::Fun" << endl;
    }

    //重写虚函数 要求函数名、返回值、形参完全相同
    //每次重写虚函数时新的vfptr会替换vftable中旧的vfptr
    void VirtualFun() override
    {
        cout << "Son1::VirtualFun" << endl;
    }

    ~Son1() override
    {
        cout << "Son1析构函数" << endl;
    }
};

class Son2 : public Father
{
public:
    Son2()
    {
        cout << "Son2构造函数" << endl;
    }

    void Fun()
    {
        cout << "Son2::Fun" << endl;
    }

    void VirtualFun() override
    {
        cout << "Son2::VirtualFun" << endl;
    }

    ~Son2() override
    {
        cout << "Son2析构函数" << endl;
    }
};

int main()
{
    Father* p = new Father;
    p->Fun();
    p->VirtualFun();
    delete p;
    cout << endl;

    p = new Son1;   //父类指针或引用指向子类对象
    p->Fun();
    p->VirtualFun();
    p->Father::VirtualFun();
    delete p;
    cout << endl;

    p = new Son2;           //重新指向
    p->Fun();
    p->VirtualFun();
    p->Father::VirtualFun();
    delete p;

    return 0;
}