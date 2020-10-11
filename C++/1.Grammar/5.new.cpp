#include <iostream>
using namespace std;

int main()
{
    int* p = new int(10);   //返回指针 初始化指针指向的值为10
    cout << p << " " << *p << endl;
    delete p;
    cout << endl;

    //1D
    int* arr1 = new int[5];    //返回数组首地址 数组共5个元素
    for(int i = 0; i < 5; i++)
    {
        arr1[i] = i;
    }
    for(int i = 0; i < 5; i++)
    {
        cout << arr1 + i << " " << *(arr1 + i) << endl;
    }
    delete[] arr1;
    cout << endl;

    //2D
    int row = 2;
    int col = 3;
    int (* arr2_1)[3] = new int[row][3];    //必须常量
    for(int i = 0; i < row; i++)
    {
        static int k = 0;

        for(int j = 0; j < col; j++)
        {
            arr2_1[i][j] = ++k;
        }
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << &arr2_1[i][j] << " " << arr2_1[i][j] << "\t";
        }

        cout << endl;
    }
    delete[] arr2_1;
    cout << endl;

    int** arr2_2 = new int* [row];  //内存不连续
    for(int i = 0; i < row; i++)
    {
        arr2_2[i] = new int[col];
    }
    for(int i = 0; i < row; i++)
    {
        static int k = 0;

        for(int j = 0; j < col; j++)
        {
            arr2_2[i][j] = ++k;
        }
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << &arr2_2[i][j] << " " << arr2_2[i][j] << "\t";
        }

        cout << endl;
    }
    for(int i = 0; i < row; i++)
    {
        delete[] arr2_2[i];
    }
    delete[] arr2_2;

    //delete后可以继续当作栈区指针或堆区指针重新赋值使用

    return 0;
}
