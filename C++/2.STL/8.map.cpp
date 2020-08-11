#include <iostream>
#include <map>  //关联式容器 字典(容器适配器) 底层红黑树 插入时默认按key升序排序 map无重复key multimap可以有重复key unordered_map底层哈希
using namespace std;

class Compare
{
public:
    //仿函数 重载()运算符 自定义排序规则
    bool operator()(const int i, const int j) const     //必须const修饰
    {
        return i > j;   //key降序排序
    }
};

template<typename T>
void Print(const T& t)
{
    for(multimap<int, char>::const_iterator it = t.begin(); it != t.end(); it++)
    {
        cout << it->first << "->" << it->second << " ";
    }
    cout << endl;
}

//初始化
void Init()
{
    map<int, char> m1;
    multimap<int, char> mm;
    for(int i = 0; i < 10; i++)
    {
        int key = rand() % 100;
        static int value = 65;
        static pair<map<int, char>::iterator, bool> result;     //插入结果

        result = m1.insert(make_pair(key, value));            //对组形式插入

        if(result.second)   //bool类型
        {
            printf("第%d次插入%d->%c插入成功\n", i + 1, key, value);
        } else
        {
            printf("第%d次插入%d->%c插入失败\n", i + 1, key, value);
        }

        mm.insert(make_pair(key, value));

        value++;
    }
    cout << "map：" << endl;
    Print(m1);
    cout << "multimap：" << endl;
    Print(mm);
    cout << endl;

    map<int, char> m2(m1);      //拷贝构造
    Print(m2);

    map<int, char> m3;
    m3 = m2;                    //赋值
    Print(m3);
}

//大小
void Size()
{
    map<int, char> m;

    for(int i = 0; i < 10; i++)
    {
        int key = rand() % 100;
        static int value = 65;

        m.insert(make_pair(key, value++));
    }
    Print(m);

    if(m.empty())
    {
        cout << "容器为空" << endl;
    } else
    {
        cout << "容器大小：" << m.size() << endl;
    }
}

//互换
void Swap()
{
    map<int, char> m1;
    for(int i = 0; i < 10; i++)
    {
        int key = rand() % 100;
        static int value = 65;

        m1.insert(make_pair(key, value++));
    }

    map<int, char> m2;
    for(int i = 0; i < 10; i++)
    {
        int key = rand() % 1000;
        static int value = 65;

        m2.insert(make_pair(key, value++));
    }

    Print(m1);
    Print(m2);

    m1.swap(m2);
    Print(m1);
    Print(m2);
}

//插入删除
void InsertErase()
{
    map<int, char> m;

    m.insert(make_pair(1, 'A'));                    //第一种插入
    m.insert(pair<int, char>(2, 'B'));              //第二种插入
    m.insert(map<int, char>::value_type(3, 'C'));   //第三种插入
    m[4] = 'D';                                     //第四种插入
    Print(m);

    m.erase(m.begin());
    Print(m);

    m.erase(3);    //删除指定key
    Print(m);

    m.clear();
    Print(m);
}

//查找
void Find()
{
    map<int, char> m;

    for(int i = 0; i < 10; i++)
    {
        static int value = 65;
        m.insert(make_pair(i, value++));
    }
    Print(m);

    map<int, char>::iterator it_pos = m.find(5);    //查找5 返回迭代器
    if(it_pos == m.end())
    {
        cout << "未找到" << endl;
    } else
    {
        cout << "找到元素：" << it_pos->first << "->" << it_pos->second << endl;
    }
}

//统计
void Count()
{
    map<int, char> m;
    for(int i = 0; i < 10; i++)
    {
        static int value = 65;
        m.insert(make_pair(5, value++));
    }
    Print(m);
    cout << m.count(5) << endl;     //返回5的个数

    multimap<int, char> mm;
    for(int i = 0; i < 10; i++)
    {
        static int value = 65;
        mm.insert(make_pair(5, value++));
    }
    Print(mm);
    cout << mm.count(5) << endl;    //返回5的个数
}

//排序
void Sort()
{
    map<int, char, Compare> m;

    m.insert(make_pair(1, 'A'));
    m.insert(make_pair(2, 'B'));
    m.insert(make_pair(3, 'C'));
    m.insert(make_pair(4, 'D'));

    for(map<int, char, Compare>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << "->" << it->second << " ";
    }
}

int main()
{
    srand(6);
    Init();
    Size();
    Swap();
    InsertErase();
    Find();
    Count();
    Sort();

    return 0;
}