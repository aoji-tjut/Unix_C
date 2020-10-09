#include <iostream>
using namespace std;

class Temp
{
public:
    Temp(int i)
    {
        cout << "Temp" << endl;
    }
};

class Father1
{
public:
    Father1(int num)
    {
        cout << "Father1" << endl;
        this->num = num;
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
    Father2(int num)
    {
        cout << "Father2" << endl;
        this->num = num;
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
class Son : public Father1, public Father2
{
public:
    Son(int father1, int father2, int son) : temp(0), Father2(father2), Father1(father1)
    {
        cout << "Son" << endl;
        this->num = son;
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
    Temp temp;
    int num;
};

int main()
{
//    Father1 father1(30);
//    Father2 father2(20);
    Son son(30, 20, 10);  //构造函数同声明顺序
    cout << endl;

//    cout << sizeof(father1) << endl;
//    cout << sizeof(father2) << endl;
    cout << sizeof(son) << endl;
    cout << endl;

//    father1.PrintNum();
//    father2.PrintNum();
    son.PrintNum();

    return 0;
}
