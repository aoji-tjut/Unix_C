#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>   //bind1st、bind2nd函数适配器
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << count_if(v.begin(), v.end(), bind1st(less<int>(), 8)) << endl;  //绑定第一个为固定参数 统计8<x的个数
    cout << count_if(v.begin(), v.end(), bind2nd(less<int>(), 8)) << endl;  //绑定第二个为固定参数 统计x<8的个数

    return 0;
}