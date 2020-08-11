#include <iostream>
#include <tuple>    //元组 不同类型 变长模板实现
using namespace std;

int main()
{
    //初始化
    tuple<int, double, char, const char*> t(10, 3.14, 'A', "hello_world");
    //auto t = make_tuple(10, 3.14, 'A', "hello world");

    //取值
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << endl;
    cout << endl;

    //tuple大小
    cout << tuple_size<decltype(t)>::value << endl;
    cout << endl;

    //元素类型
    typedef tuple_element<0, decltype(t)>::type T1;
    typedef tuple_element<1, decltype(t)>::type T2;
    typedef tuple_element<2, decltype(t)>::type T3;
    typedef tuple_element<3, decltype(t)>::type T4;
    cout << typeid(T1).name() << " " << typeid(T2).name() << " "
         << typeid(T3).name() << " " << typeid(T4).name() << endl;
    cout << endl;

    //分割元素
    int i;
    double d;
    char c;
    const char* str;
    tie(i, d, c, str) = t;
    cout << i << " " << d << " " << c << " " << str << endl;
    cout << endl;

    //拼接tuple
    auto t1 = make_tuple(20);
    auto t2 = make_tuple(6.66);
    auto t3 = make_tuple('B');
    auto t4 = make_tuple("hello");
    auto t_cat = tuple_cat(t1, t2, t3, t4);
    cout << get<0>(t_cat) << " " << get<1>(t_cat) << " " << get<2>(t_cat) << " " << get<3>(t_cat) << endl;
    cout << endl;

    //交换 必须类型对应
    cout << "t:" << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << endl;
    cout << "t_cat:" << get<0>(t_cat) << " " << get<1>(t_cat) << " " << get<2>(t_cat) << " " << get<3>(t_cat) << endl;
    t.swap(t_cat);
    cout << "t:" << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << endl;
    cout << "t_cat:" << get<0>(t_cat) << " " << get<1>(t_cat) << " " << get<2>(t_cat) << " " << get<3>(t_cat) << endl;

    return 0;
}