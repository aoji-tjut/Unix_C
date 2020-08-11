#include <iostream>
using namespace std;

void Sort(int (* p)[5], int len)
{
    int* q = *p;

    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(q[j] > q[j + 1])
            {
                static int temp;
                temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
        }
    }
}

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

    //输出排序前数组
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << a[i][j] << " ";
        }
    }
    cout << endl;

    //调用冒泡排序
    Sort(a, sizeof(a) / sizeof(**a));

    //输出排序后数组
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << a[i][j] << " ";
        }
    }
    cout << endl;

    return 0;
}
