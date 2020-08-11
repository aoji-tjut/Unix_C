#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>   //bind函数适配器
using namespace std;
using namespace placeholders;

double Divide(double i, double j)
{
    return i / j;
}

class Op
{
public:
    Op(double i, double j)
    {
        this->i = i;
        this->j = j;
    }

    double Divide()
    {
        return this->i / this->j;
    }

    double i, j;
};

int main()
{
    auto a1 = bind(Divide, 10, 2);          //绑定函数Divide 第一参数10 第二参数2
    cout << a1() << endl;

    auto a2 = bind(Divide, _1, 2);          //绑定函数Divide 第一占位参数 第二参数2
    cout << a2(8) << endl;                  //传入第一参数

    auto a3 = bind(Divide, _1, _2);         //绑定函数Divide 第一占位参数 第二占位参数
    cout << a3(10, 3) << endl;              //传入第一参数、第二参数

    auto a4 = bind<int>(Divide, _1, _2);    //指定返回值int
    cout << a4(10, 3) << endl;
    cout << endl;

    Op op(10, 2);
    auto a5 = bind(&Op::Divide, op);        //绑定成员函数Op::Divide 第一参数op
    cout << a5() << endl;

    auto a6 = bind(&Op::Divide, _1);        //绑定成员函数Op::Divide 第一占位参数
    cout << a6(op) << endl;                 //传入第一参数

    auto a7 = bind(&Op::i, op);             //绑定数据成员Op::i 第一参数op
    cout << a7() << endl;

    auto a8 = bind(&Op::i, _1);             //绑定数据成员Op::i 第一占位参数
    cout << a8(op) << endl;                 //传入第一参数
    cout << endl;

    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << count_if(v.begin(), v.end(), bind(less<int>(), _1, 8)) << endl;  //_1是比较函数的第一个占位参数 bind返回一个函数对象

    return 0;
}