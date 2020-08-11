#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//仿函数
class Fun1
{
public:
    void operator()(int i)
    {
        cout << i << " ";
    }
};

//回调函数
void Fun2(int i)
{
    cout << i << " ";
}

int main()
{
    vector<int> v;
    v.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), Fun1());   //仿函数
    cout << endl;

    for_each(v.begin(), v.end(), Fun2);     //普通函数
    cout << endl;

    return 0;
}