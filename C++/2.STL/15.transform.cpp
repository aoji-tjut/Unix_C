#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(int i)
{
    cout << i << " ";
}

int Fun(int i)
{
    return i * 2;
}

int main()
{
    vector<int> src;
    src.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        src.push_back(i);
    }
    for_each(src.begin(), src.end(), Print);
    cout << endl;

    vector<int> dst(src.size());
    transform(src.begin(), src.end(), dst.begin(), Fun);    //把src进行Fun处理后搬运到dst src不变
    for_each(dst.begin(), dst.end(), Print);
    cout << endl;

    return 0;
}