#include <iostream>
using namespace std;

//仿函数
class Add
{
public:
    Add()
    {
        this->count = 0;
    }

    //重载()
    int operator()(int i, int j)
    {
        this->count++;
        return i + j;
    }

    int count;      //记录函数状态
};

void Fun(Add& add, int i, int j)
{
    cout << add(i, j) << endl;
}

int main()
{
    Add add;    //创建函数对象

    cout << add(10, 20) << endl;    //调用仿函数

    Fun(add, 10, 20);   //仿函数作为参数

    cout << "调用次数：" << add.count << endl;   //输出函数状态

    return 0;
}