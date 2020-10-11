#include <iostream>
using namespace std;

int main()
{
    int* p = new int(10);   //返回指针 初始化指针指向的值为10
    cout << p << " " << *p << endl;
    delete p;
    cout << endl;

    //1D
    int* q = new int[5];    //返回数组首地址 数组共5个元素
    for(int i = 0; i < 5; i++)
    {
        q[i] = i;
    }
    for(int i = 0; i < 5; i++)
    {
        cout << q + i << " " << *(q + i) << endl;
    }
    delete[] q;
    cout << endl;

    //2D
    int row = 2;
    int col = 3;
    int** r = new int* [row];
    for(int i = 0; i < row; i++)
    {
        r[i] = new int[col];
    }
    for(int i = 0; i < row; i++)
    {
        static int k = 0;

        for(int j = 0; j < col; j++)
        {
            r[i][j] = ++k;
        }
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << &r[i][j] << " " << r[i][j] << "\t";
        }

        cout << endl;
    }
    for(int i = 0; i < row; i++)
    {
        delete[] r[i];
    }
    delete[] r;
    
    //delete后可以继续当作栈区指针或堆区指针重新赋值使用

    return 0;
}
