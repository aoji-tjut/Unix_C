#include <iostream>
using namespace std;

//泛化函数模版 同一函数可以传入不同类型 仅对下面第一个函数有效 可以发生重载 可以有默认参数类型
template<typename T>
void Fun(T i)
{
    cout << "函数模版" << endl;
    cout << typeid(i).name() << " " << i << endl;
}

//特化函数模版 特殊处理某种类型的参数
template<>
void Fun<double>(double d)
{
    cout << "函数模版具体化" << endl;
    cout << typeid(d).name() << " " << d << endl;
}

void Fun(char c)
{
    cout << "常规函数" << endl;
    cout << typeid(c).name() << " " << c << endl;
}

int main()
{
    //优先级：常规函数 > 特化函数模版 > 泛化函数模版
    Fun(5);             //自动推断类型
    Fun<float>(5.5);    //可以指定类型
    Fun(5.5);           //特化函数模版
    Fun('A');           //常规函数
    Fun<>('A');         //空参数列表可以强制调用模版

    return 0;
}