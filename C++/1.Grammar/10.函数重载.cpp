#include <iostream>
using namespace std;

//参数类型不同
void Fun1(int i)
{
    cout << "Fun1 " << i << endl;
}

void Fun1(char c)
{
    cout << "Fun1 " << c << endl;
}

//参数个数不同
void Fun2(int i)
{
    cout << "Fun2 " << i << endl;
}

void Fun2(int i, int j)
{
    cout << "Fun2 " << i << " " << j << endl;
}

//参数顺序不同
void Fun3(int i, char c)
{
    cout << "Fun3 " << i << " " << c << endl;
}

void Fun3(char c, int i)
{
    cout << "Fun3 " << c << " " << i << endl;
}

int main()
{
    int i = 5, j = 10;
    char c = 'A';

    Fun1(i);
    Fun1(c);
    cout << endl;

    Fun2(i);
    Fun2(i, j);
    cout << endl;

    Fun3(i, c);
    Fun3(c, i);

    return 0;
}