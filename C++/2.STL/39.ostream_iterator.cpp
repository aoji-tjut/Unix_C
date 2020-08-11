#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>     //ostream_iterator适配器
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ostream_iterator<int> out_it(cout, ", ");   //输出流迭代器 ','间隔
    copy(v.begin(), v.end(), out_it);

    return 0;
}