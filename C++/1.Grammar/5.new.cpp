#include <iostream>
using namespace std;

int main()
{
    int* p = new int(10);   //返回指针 初始化指针指向的值为10
    cout << p << " " << *p << endl;

    int* q = new int[5];    //返回数组首地址 数组共5个元素
    for(int i = 0; i < 5; i++)
    {
        q[i] = i;
    }
    for(int i = 0; i < 5; i++)
    {
        cout << q + i << " " << *(q + i) << endl;
    }

    delete p;
    delete[] q;

    //delete后可以继续当作栈区指针或堆区指针重新赋值使用

    return 0;
}
