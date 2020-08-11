#include <iostream>
#include <vector>
#include <algorithm>    //链表使用容器自带的sort
using namespace std;

void Print(int i)
{
    cout << i << " ";
}

bool Fun(int i, int j)
{
    return i > j;
}

int main()
{
    vector<int> v;
    v.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 100);
    }
    for_each(v.begin(), v.end(), Print);
    cout << endl;

    sort(v.begin(), v.end());       //升序
    for_each(v.begin(), v.end(), Print);
    cout << endl;

    sort(v.begin(), v.end(), Fun);  //降序
    for_each(v.begin(), v.end(), Print);
    cout << endl;

    return 0;
}