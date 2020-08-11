#include <iostream>
using namespace std;

int main()
{
    //创建数组
    int a[2][5];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            a[i][j] = rand() % 100;
        }
    }

    //输出数组值和地址
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << &a[i][j] << " " << a[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    //数组与指针结合
    int (* p)[5] = a;   //行指针 二级指针 数组指针
    int* q = *a;        //列指针 一级指针
    cout << a + 1 << " " << p + 1 << " " << **(p + 1) << endl;                      //行指针+1
    cout << *a + 1 << " " << q + 1 << " " << *(q + 1) << endl;                      //列指针+1
    cout << *(a + 1) + 1 << " " << *(p + 1) + 1 << " " << *(*(a + 1) + 1) << endl;  //行指针+1 列指针+1

    return 0;
}
