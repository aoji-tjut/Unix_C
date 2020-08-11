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
        v.push_back(i);
    }
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    bool result = binary_search(v.begin(), v.end(), 5);     //二分查找5 必须有序 返回bool
    if(result)
    {
        cout << "找到" << endl;
    } else
    {
        cout << "未找到" << endl;
    }

    return 0;
}