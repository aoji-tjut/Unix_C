#include <iostream>
#include <deque>    //序列式容器 双端数组 许多连续的buffer 中间控制器指针iterator(cur、first、last、node)
using namespace std;

void Print(const deque<int>& d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//初始化
void Init()
{
    deque<int> d1;
    for(int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    Print(d1);

    deque<int> d2(d1.begin(), d1.end());    //区间初始化
    Print(d2);

    deque<int> d3(10, 5);                   //10个5
    Print(d3);

    deque<int> d4(d3);                      //拷贝构造
    Print(d4);
}

//赋值
void Assign()
{
    deque<int> d;
    for(int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    Print(d);

    deque<int> d1;
    d1 = d;
    Print(d1);

    deque<int> d2;
    d2.assign(d.begin(), d.end());
    Print(d2);

    deque<int> d3;
    d3.assign(10, 5);   //10个5
    Print(d3);
}

//大小
void Size()
{
    deque<int> d;
    for(int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    Print(d);

    if(d.empty())
    {
        cout << "容器为空" << endl;
    } else
    {
        cout << "容器大小：" << d.size() << endl;
    }

    d.resize(15, -1);   //重新指定size 剩余位置设为-1 默认剩余位置补0
    cout << "容器大小：" << d.size() << endl;
    Print(d);

    d.resize(5);        //重新指定size 删除多余位置
    cout << "容器大小：" << d.size() << endl;
    Print(d);
}

//插入删除
void InsertErase()
{
    deque<int> d;

    for(int i = 0; i < 5; i++)
    {
        d.push_front(i);    //首插
    }
    Print(d);

    for(int i = 0; i < 5; i++)
    {
        d.push_back(i);     //尾插
    }
    Print(d);

    for(int i = 0; i < 3; i++)
    {
        d.pop_front();      //首删
    }
    Print(d);

    for(int i = 0; i < 3; i++)
    {
        d.pop_back();       //尾删
    }
    Print(d);

    d.insert(d.begin(), -1);            //插入-1
    Print(d);

    d.insert(d.end(), 5, -2);           //插入5个-2
    Print(d);

    deque<int> temp;
    temp.push_back(-3);
    temp.push_back(-3);
    temp.push_back(-3);
    d.insert(d.begin() + 3, temp.begin(), temp.end());  //区间插入
    Print(d);

    d.erase(d.begin());                 //删除
    Print(d);

    d.erase(d.begin() + 7, d.end());    //区间删除
    Print(d);

    d.clear();                          //清空
    Print(d);
}

//读写
void At()
{
    deque<int> d;

    for(int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    Print(d);

    cout << d.front() << endl;      //首元素

    cout << d.back() << endl;       //尾元素

    for(int i = 0; i < d.size(); i++)
    {
        d[i] = 1;
        cout << d[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < d.size(); i++)
    {
        d.at(i) = 2;
        cout << d.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    Init();
    Assign();
    Size();
    InsertErase();
    At();

    return 0;
}