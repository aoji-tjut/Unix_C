#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>     //inserter迭代器适配器
using namespace std;

int main()
{
    vector<int> src{-1, -1, -1, -1, -1};
    vector<int> dst(4);

    copy(src.begin(), src.end(), inserter(dst, dst.begin() + 2));   //在dst+2位置插入src

    for(int i:dst)
    {
        cout << i << " ";
    }

    return 0;
}