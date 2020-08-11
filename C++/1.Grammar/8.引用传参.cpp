#include <iostream>
using namespace std;

void Swap(int* p, int* q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void Swap(int& p, int& q)
{
    int temp;
    temp = p;
    p = q;
    q = temp;
}

int main()
{
    int i = 5, j = 10;

    cout << i << " " << j << endl;

    Swap(&i, &j);
    cout << i << " " << j << endl;

    Swap(i, j);     //传引用等同于传地址
    cout << i << " " << j << endl;

    return 0;
}