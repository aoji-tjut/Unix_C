#include <iostream>
#include <vector>   //序列式容器 单端数组 动态扩展
using namespace std;

void Print(const vector<int>& v)
{
    //begin指向第一个元素 end指向最后一个元素的下一个位置
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//初始化
void Init()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        cout << v1.data() << endl;          //首元素地址 每次增长首元素地址都会变化
    }
    Print(v1);

    vector<int> v2(v1.begin(), v1.end());   //区间初始化
    Print(v2);

    vector<int> v3(10, 5);                  //10个5
    Print(v3);

    vector<int> v4(v3);                     //拷贝构造
    Print(v4);
}

//赋值
void Assign()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    Print(v);

    vector<int> v1;
    v1 = v;
    Print(v1);

    vector<int> v2;
    v2.assign(v.begin(), v.end());
    Print(v2);

    vector<int> v3;
    v3.assign(10, 5);   //10个5
    Print(v3);
}

//容量
void Capacity()
{
    vector<int> v;

    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    Print(v);

    if(v.empty())
    {
        cout << "容器为空" << endl;
    } else
    {
        cout << "容器总容量：" << v.capacity() << endl;
        cout << "容器已用大小：" << v.size() << endl;
    }

    v.resize(15, -1);   //重新指定size 剩余位置设为-1 默认剩余位置补0
    cout << "容器总容量：" << v.capacity() << endl;
    cout << "容器已用大小：" << v.size() << endl;
    Print(v);

    v.resize(5);        //重新指定size 删除多余位置
    cout << "容器总容量：" << v.capacity() << endl;
    cout << "容器已用大小：" << v.size() << endl;
    Print(v);
}

//插入删除
void InsertErase()
{
    vector<int> v;

    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);     //尾插
    }
    Print(v);

    for(int i = 0; i < 5; i++)
    {
        v.pop_back();       //尾删
    }
    Print(v);

    v.insert(v.begin(), -1);            //插入-1
    Print(v);

    v.insert(v.end(), 5, -2);           //插入5个-2
    Print(v);

    vector<int> temp;
    temp.push_back(-3);
    temp.push_back(-3);
    temp.push_back(-3);
    v.insert(v.begin() + 3, temp.begin(), temp.end());  //区间插入
    Print(v);

    v.erase(v.begin());                 //删除
    Print(v);

    v.erase(v.begin(), v.end() - 5);    //区间删除
    Print(v);

    v.clear();                          //清空
    Print(v);
}

//读写
void At()
{
    vector<int> v;

    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    Print(v);

    cout << v.front() << endl;      //首元素

    cout << v.back() << endl;       //尾元素

    for(int i = 0; i < v.size(); i++)
    {
        v[i] = 1;
        cout << v[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < v.size(); i++)
    {
        v.at(i) = 2;
        cout << v.at(i) << " ";
    }
    cout << endl;
}

//互换
void Swap()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    vector<int> v2;
    for(int i = 9; i >= 0; i--)
    {
        v2.push_back(i);
    }

    Print(v1);
    Print(v2);

    v1.swap(v2);    //交换
    Print(v1);
    Print(v2);

    //收缩内存空间
    vector<int> large_v;
    for(int i = 0; i < 10000; i++)
    {
        large_v.push_back(i);
    }
    cout << "容量：" << large_v.capacity() << endl;
    cout << "大小：" << large_v.size() << endl;

    large_v.resize(10);
    cout << "容量：" << large_v.capacity() << endl;
    cout << "大小：" << large_v.size() << endl;

    vector<int>(large_v).swap(large_v);     //与临时对象互换
    cout << "容量：" << large_v.capacity() << endl;
    cout << "大小：" << large_v.size() << endl;
}

//预留空间
void Reserve()
{
    int num = 0;    //统计开辟内存次数
    int* p = nullptr;
    vector<int> v1;
    for(int i = 0; i < 10000; i++)
    {
        v1.push_back(i);

        if(p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }
    cout << "内存开辟次数" << num << endl;

    num = 0;
    p = nullptr;
    vector<int> v2;
    v2.reserve(10000);   //预留10000空间 避免重复动态开辟空间 只改变capacity不改变size
    for(int i = 0; i < 10000; i++)
    {
        v2.push_back(i);

        if(p != &v2[0])
        {
            p = &v2[0];
            num++;
        }
    }
    cout << "内存开辟次数" << num << endl;
}

int main()
{
    Init();
    Assign();
    Capacity();
    InsertErase();
    At();
    Swap();
    Reserve();

    return 0;
}