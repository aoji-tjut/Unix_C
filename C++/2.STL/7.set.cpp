#include <iostream>
#include <set>  //关联式容器 集合(容器适配器) 底层红黑树 插入时默认升序排序 set无重复元素 multiset可以有重复元素 unordered_set底层哈希
using namespace std;

class Student
{
public:
    Student(char name, int age)
    {
        this->name = name;
        this->age = age;
    }

    char name;
    int age;
};

class Compare
{
public:
    //仿函数 重载()运算符 自定义排序规则
    bool operator()(const Student& stu1, const Student& stu2) const     //必须const修饰
    {
        //优先姓名升序 姓名相同时年龄降序
        if(stu1.name == stu2.name)
        {
            return stu1.age > stu2.age;
        } else
        {
            return stu1.name < stu1.name;
        }
    }
};

template<typename T>
void Print(const T& t)
{
    for(set<int>::const_iterator it = t.begin(); it != t.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//初始化
void Init()
{
    set<int> s1;
    multiset<int> ms;
    for(int i = 0; i < 10; i++)
    {
        int value = rand() % 100;
        static pair<set<int>::iterator, bool> result;   //插入结果

        result = s1.insert(value);    //只能insert插入 自动屏蔽重复元素 插入后自动升序排列

        if(result.second)   //bool类型
        {
            printf("第%d次插入%d值插入成功\n", i + 1, value);
        } else
        {
            printf("第%d次插入%d值插入失败\n", i + 1, value);
        }

        ms.insert(value);   //只能insert插入 不屏蔽重复元素 插入后自动升序排列
    }
    cout << "set：" << endl;
    Print(s1);
    cout << "multiset：" << endl;
    Print(ms);
    cout << endl;

    set<int> s2(s1);        //拷贝构造
    Print(s2);

    set<int> s3;
    s3 = s1;                //赋值
    Print(s3);
}

//大小
void Size()
{
    set<int> s;

    for(int i = 0; i < 10; i++)
    {
        s.insert(rand() % 100);
    }
    Print(s);

    if(s.empty())
    {
        cout << "容器为空" << endl;
    } else
    {
        cout << "容器大小：" << s.size() << endl;
    }
}

//互换
void Swap()
{
    set<int> s1;
    for(int i = 0; i < 10; i++)
    {
        s1.insert(rand() % 100);
    }

    set<int> s2;
    for(int i = 0; i < 10; i++)
    {
        s2.insert(rand() % 1000);
    }

    Print(s1);
    Print(s2);

    s1.swap(s2);
    Print(s1);
    Print(s2);
}

//插入删除
void InsertErase()
{
    set<int> s;

    for(int i = 0; i < 10; i++)
    {
        s.insert(i);
    }
    Print(s);

    s.erase(s.begin());
    Print(s);

    s.erase(9);    //删除指定元素
    Print(s);

    s.clear();
    Print(s);
}

//查找
void Find()
{
    set<int> s;

    for(int i = 0; i < 10; i++)
    {
        s.insert(i);
    }
    Print(s);

    set<int>::iterator it_pos = s.find(5);      //查找5 返回迭代器
    if(it_pos == s.end())
    {
        cout << "未找到" << endl;
    } else
    {
        cout << "找到元素：" << *it_pos << endl;
    }
}

//统计
void Count()
{
    set<int> s;
    for(int i = 0; i < 10; i++)
    {
        s.insert(5);
    }
    Print(s);
    cout << s.count(5) << endl;     //返回5的个数

    multiset<int> ms;
    for(int i = 0; i < 10; i++)
    {
        ms.insert(5);
    }
    Print(ms);
    cout << ms.count(5) << endl;    //返回5的个数
}

//排序(自定义类型必须指定排序方式)
void Sort()
{
    multiset<Student, Compare> ms;

    Student stu1('A', 10);
    Student stu2('A', 20);
    Student stu3('B', 10);
    Student stu4('B', 20);
    ms.insert(stu1);
    ms.insert(stu2);
    ms.insert(stu3);
    ms.insert(stu4);

    for(multiset<Student, Compare>::const_iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << it->name << " " << it->age << endl;
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