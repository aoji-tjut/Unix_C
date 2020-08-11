#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

int main()
{
    vector<int> v;
    v.reserve(100);
    for(int i = 1; i <= 100; i++)
    {
        v.push_back(i);
    }

    cout << accumulate(v.begin(), v.end(), 10000) << endl;                  //计算元素总和 再加10000
    cout << accumulate(v.begin(), v.end(), -10000, minus<int>()) << endl;   //计算元素总和相反数 再加-10000

    return 0;
}
