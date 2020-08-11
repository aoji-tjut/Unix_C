#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(int i)
{
    cout << i << " ";
}

bool Fun(int i)
{
    return i > 5;
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

    replace_if(v.begin(), v.end(), Fun, -1);    //条件替换大于5为-1
    for_each(v.begin(), v.end(), Print);
    cout << endl;

    return 0;
}
