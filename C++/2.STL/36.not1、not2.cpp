#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>   //not1、not2函数适配器
using namespace std;

void Print(int i)
{
    cout << i << " ";
}

bool Compare(int i, int j)
{
    return i < j;
}

int main()
{
    vector<int> v{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    cout << count_if(v.begin(), v.end(), not1(bind2nd(less<int>(), 8))) << endl;    //统计x>=8的个数

    sort(v.begin(), v.end(), not2(function<bool(int, int)>(Compare)));  //降序排序
    for_each(v.begin(), v.end(), Print);

    return 0;
}