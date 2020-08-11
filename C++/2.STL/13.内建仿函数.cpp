#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//算数仿函数
void Fun1()
{
    negate<int> n;      //一元运算
    cout << n(10) << endl;

    plus<int> p;        //二元运算
    cout << p(10, 20) << endl;
}

//关系仿函数
void Fun2()
{
    vector<int> v;
    v.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 100);
    }
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());   //"大于"仿函数
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//逻辑仿函数
void Fun3()
{
    vector<bool> v1;
    v1.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(rand() % 2);
    }
    for(auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<bool> v2(v1.size());     //开辟同大小空间
    transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());   //搬运 取反
    for(auto it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<bool> v3(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), logical_or<bool>());   //搬运 或
    for(auto it = v3.begin(); it != v3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    Fun1();
    Fun2();
    Fun3();

    return 0;
}