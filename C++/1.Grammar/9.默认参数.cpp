#include <iostream>
using namespace std;

void Fun(int i, int j = 2, int k = 3)   //j、k为默认参数 默认参数必须从右向左设置 同一函数声明和实现只能有一个有写默认参数
{
    cout << i << " " << j << " " << k << endl;
}

int main()
{
    Fun(1);
    Fun(1, 10);
    Fun(1, 10, 100);

    return 0;
}
