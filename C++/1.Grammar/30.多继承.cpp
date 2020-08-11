#include <iostream>
using namespace std;

class Father1
{
public:
    Father1()
    {
        cout << "Father1" << endl;
        this->num = 30;
    }

    void PrintNum()
    {
        cout << "Father1::PrintNum" << endl;
        cout << this->num << endl;
    }

protected:
    int num;
};

class Father2
{
public:
    Father2()
    {
        cout << "Father2" << endl;
        this->num = 20;
    }

    void PrintNum()
    {
        cout << "Father2::PrintNum" << endl;
        cout << this->num << endl;
    }

protected:
    int num;
};

//多继承 Son同时继承Father1和Father2
class Son : public Father2, public Father1
{
public:
    Son()
    {
        cout << "Son" << endl;
        this->num = 10;
    }

    void PrintNum()
    {
        //使用类名作用域 避免同名冲突
        cout << "Son::PrintNum" << endl;
        cout << this->Father1::num << endl;
        cout << this->Father2::num << endl;
        cout << this->num << endl;
    }

private:
    int num;
};

int main()
{
    Father1 father1;
    Father2 father2;
    Son son;    //构造函数同声明顺序
    cout << endl;

    cout << sizeof(father1) << endl;
    cout << sizeof(father2) << endl;
    cout << sizeof(son) << endl;
    cout << endl;

    father1.PrintNum();
    father2.PrintNum();
    son.PrintNum();

    return 0;
}
