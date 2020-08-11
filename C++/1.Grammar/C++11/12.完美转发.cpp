#include <iostream>
using namespace std;

void Fun(int& i)
{
    cout << "Fun(int& i)\t\t\t" << &i << " " << i << endl;
}

void Fun(int&& i)
{
    cout << "Fun(int&& i)\t\t" << &i << " " << i << endl;
}

void UnPerfectForward(int&& i)
{
    cout << "UnForward(int&& i)\t" << &i << " " << i << endl;
    Fun(i);     //直接调用会将右值作为左值传入
}

void PerfectForward(int&& i)
{
    cout << "Forward(int&& i)\t" << &i << " " << i << endl;
    Fun(std::forward<int>(i));      //完美转发
}

int main()
{
    int i = 10;
    cout << "\t\t\t\t\t" << &i << " " << i << endl;
    UnPerfectForward(std::move(i));
    cout << endl;

    i = 10;
    cout << "\t\t\t\t\t" << &i << " " << i << endl;
    PerfectForward(std::move(i));
    cout << endl;

    return 0;
}