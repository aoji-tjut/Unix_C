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
    vector<int> src2;
    src1.reserve(10);
    src2.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        src1.push_back(i);
        src2.push_back(i + 5);
    }
    for_each(src1.begin(), src1.end(), Print);
    cout << endl;
    for_each(src2.begin(), src2.end(), Print);
    cout << endl;

    vector<int> dst(min(src1.size(), src2.size()));
    auto it_end = set_intersection(src1.begin(), src1.end(), src2.begin(), src2.end(),
                                   dst.begin());    //有序同序序列求交集 返回end迭代器
    for_each(dst.begin(), it_end, Print);
    cout << endl;

    return 0;
}
