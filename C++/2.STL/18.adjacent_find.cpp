#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 5);
    }
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    auto it1 = adjacent_find(v.begin(), v.end());     //查找相邻重复元素 返回第一个元素位置迭代器
    if(it1 == v.end())
    {
        cout << "未找到" << endl;
    } else
    {
        cout << "找到：" << *it1 << endl;
    }

    return 0;
}