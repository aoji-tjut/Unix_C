#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Fun1
{
public:
    //仿函数 一元谓词 大于5返回真
    bool operator()(int i)
    {
        return i > 5;
    }
};

class Fun2
{
public:
    //仿函数 二元谓词 降序返回真
    bool operator()(int i, int j)
    {
        return i > j;
    }
};

void One()
{
    vector<int> v;
    v.reserve(10);  //申请10个空间
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    auto it = find_if(v.begin(), v.end(), Fun1());     //传入匿名对象 返回迭代器
    if(it == v.end())
    {
        cout << "未找到" << endl;
    } else
    {
        cout << "找到：" << *it << endl;
    }
}

void Two()
{
    vector<int> v;
    v.reserve(10);  //申请10个空间
    for(int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 100);
    }
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), Fun2());   //传入匿名对象 降序
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    One();
    Two();

    return 0;
}