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
    vector<int> src1;
    src1.reserve(10);
    for(int i = 0; i < 20; i += 2)
    {
        src1.push_back(i);
    }
    for_each(src1.begin(), src1.end(), Print);
    cout << endl;

    vector<int> src2;
    src2.reserve(10);
    for(int i = 1; i < 20; i += 2)
    {
        src2.push_back(i);
    }
    for_each(src2.begin(), src2.end(), Print);
    cout << endl;

    vector<int> dst(src1.size() + src2.size());
    merge(src1.begin(), src1.end(), src2.begin(), src2.end(), dst.begin());     //合并 必须同序有序
    for_each(dst.begin(), dst.end(), Print);
    cout << endl;

    return 0;
}
