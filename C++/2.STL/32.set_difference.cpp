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

    vector<int> dst1(src1.size());
    auto it_end1 = set_difference(src1.begin(), src1.end(), src2.begin(), src2.end(),
                                  dst1.begin());    //有序同序序列求差集 src1中src1与src2差 返回end迭代器
    for_each(dst1.begin(), it_end1, Print);
    cout << endl;

    vector<int> dst2(src2.size());
    auto it_end2 = set_difference(src2.begin(), src2.end(), src1.begin(), src1.end(),
                                  dst2.begin());    //有序同序序列求差集 src2中src1与src2差 返回end迭代器
    for_each(dst2.begin(), it_end2, Print);
    cout << endl;

    return 0;
}
