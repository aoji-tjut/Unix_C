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

    reverse(v.begin(), v.end());    //逆序
    for_each(v.begin(), v.end(), Print);
    cout << endl;

    return 0;
}
