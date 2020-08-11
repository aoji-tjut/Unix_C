#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void Print(int i)
{
    cout << i << " ";
}

int main()
{
    vector<int> v(10, 100);     //初始化10个100
    for_each(v.begin(), v.end(), Print);
    cout << endl;

    fill(v.begin(), v.end(), 200);      //填充200
    for_each(v.begin(), v.end(), Print);
    cout << endl;

    return 0;
}
