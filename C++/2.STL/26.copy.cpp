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
    vector<int> src;
    src.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        src.push_back(i);
    }
    for_each(src.begin(), src.end(), Print);
    cout << endl;

    vector<int> dst(10);
    copy(src.begin(), src.end(), dst.begin());      //拷贝
    for_each(src.begin(), src.end(), Print);
    cout << endl;

    return 0;
}
