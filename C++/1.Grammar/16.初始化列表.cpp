#include <iostream>
using namespace std;

class A
{
public:
    //初始化列表 先赋值再执行函数体
    A(int a, int b, int c) : i(a), j(b), k(c)
    {
        cout << "构造函数" << endl;
    }

    //初始化顺序按声明顺序
    A(int a, int b) : i(a), k(b), j(k)
    {
        cout << "构造函数" << endl;
    }

    void Show()
    {
        cout << this->i << " " << this->j << " " << this->k << endl;
    }

private:
    int i;
    int j;
    int k;
};

int main()
{
    A a1(10, 20, 30);
    A a2(10, 20);
    cout << endl;

    a1.Show();
    a2.Show();

    return 0;
}