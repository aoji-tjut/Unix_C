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
    vector<int> v;
    v.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), Print);
    cout << endl;

    replace(v.begin(), v.end(), 0, -1);     //0替换为-1
    for_each(v.begin(), v.end(), Print);
    cout << endl;

    return 0;
}
