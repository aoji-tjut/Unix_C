#include <iostream>
#include <list>    //序列式容器 双向循环链表 迭代器不支持随机访问
using namespace std;

void Print(const list<int>& l)
{
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//初始化
void Init()
{
    list<int> l1;
    for(int i = 0; i < 10; i++)
    {
        l1.push_back(i);
    }
    Print(l1);

    list<int> l2(l1.begin(), l1.end());   //区间初始化
    Print(l2);

    list<int> l3(10, 5);                  //10个5
    Print(l3);

    list<int> l4(l3);                     //拷贝构造
    Print(l4);
}

//赋值
void Assign()
{
    list<int> l;
    for(int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    Print(l);

    list<int> l1;
    l1 = l;
    Print(l1);

    list<int> l2;
    l2.assign(l.begin(), l.end());
    Print(l2);

    list<int> l3;
    l3.assign(10, 5);   //10个5
    Print(l3);
}

//互换
void Swap()
{
    list<int> l1;
    for(int i = 0; i < 10; i++)
    {
        l1.push_back(i);
    }

    list<int> l2;
    for(int i = 9; i >= 0; i--)
    {
        l2.push_back(i);
    }

    Print(l1);
    Print(l2);

    l1.swap(l2);    //交换
    Print(l1);
    Print(l2);
}

//大小
void Size()
{
    list<int> l;

    for(int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    Print(l);

    if(l.empty())
    {
        cout << "容器为空" << endl;
    } else
    {
        cout << "容器大小：" << l.size() << endl;
    }

    l.resize(15, -1);   //重新指定size 剩余位置设为-1 默认剩余位置补0
    cout << "容器大小：" << l.size() << endl;
    Print(l);

    l.resize(5);        //重新指定size 删除多余位置
    cout << "容器大小：" << l.size() << endl;
    Print(l);
}

//插入删除
void InsertErase()
{
    list<int> l;

    for(int i = 0; i < 5; i++)
    {
        l.push_front(i);    //首插
    }
    Print(l);

    for(int i = 0; i < 5; i++)
    {
        l.push_back(i);     //尾插
    }
    Print(l);

    for(int i = 0; i < 3; i++)
    {
        l.pop_front();      //首删
    }
    Print(l);

    for(int i = 0; i < 3; i++)
    {
        l.pop_back();       //尾删
    }
    Print(l);

    l.insert(l.begin(), -1);            //插入-1
    Print(l);

    l.insert(l.end(), 5, -2);           //插入5个-2
    Print(l);

    list<int> temp;
    temp.push_back(-3);
    temp.push_back(-3);
    temp.push_back(-3);
    list<int>::iterator it = l.begin();

    for(int i = 0; i < 3; i++)
    {
        it++;
    }
    l.insert(it, temp.begin(), temp.end());     //区间插入
    Print(l);

    l.erase(l.begin());                         //删除
    Print(l);

    it = l.begin();
    advance(it,7);                              //非连续容器不能it+n 只能++/--/advance
    l.erase(it, l.end());                       //区间删除
    Print(l);

    l.remove(-3);                               //移除所有-3
    Print(l);

    l.clear();                                  //清空
    Print(l);
}

//只读
void OnlyRead()
{
    list<int> l;

    for(int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    Print(l);

    cout << l.front() << endl;      //首元素

    cout << l.back() << endl;       //尾元素
}

//回调函数
bool Compare(int i, int j)
{
    return i > j;
}

//排序
void Sort()
{
    list<int> l;

    for(int i = 0; i < 10; i++)
    {
        l.push_back(rand() % 100);
    }
    Print(l);

    l.sort();           //升序排序
    Print(l);

    l.sort(Compare);    //降序排序
    Print(l);

    l.reverse();        //反转
    Print(l);
}

int main()
{
    Init();
    Assign();
    Swap();
    Size();
    InsertErase();
    OnlyRead();
    Sort();

    return 0;
}