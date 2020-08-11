#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(int i)
{
    cout << i << " ";
}

int main()
{
    vector<int> v1;
    v1.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for_each(v1.begin(), v1.end(), Print);
    cout << endl;

    vector<int> v2;
    v2.reserve(5);
    for(int i = 0; i < 5; i++)
    {
        v2.push_back(i);
    }
    for_each(v2.begin(), v2.end(), Print);
    cout << endl;

    swap(v1, v2);   //互换 相同容器
    for_each(v1.begin(), v1.end(), Print);
    cout << endl;
    for_each(v2.begin(), v2.end(), Print);
    cout << endl;

    return 0;
}
