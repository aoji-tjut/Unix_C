#include <iostream>
using namespace std;

void Print()
{
    cout << "递归结束 开始回溯" << endl;
}

template<typename T, typename... Types>
void Print(const T& firstArg, const Types& ... args)
{
    cout << "firstArg=" << firstArg << "\tsizeof(args)=" << sizeof...(args) << endl;
    Print(args...);
    cout << firstArg << "\t输出完毕" << endl;
}

/**********************************************************************************************************************/

//声明可变参数类模板
template<typename... Values>
class Tuple;

//具体化类模板处理空类型
template<>
class Tuple<>
{
public:
    Tuple()
    {
        cout << "父类老大在此！开始回溯创建元素！" << endl;
    }
};

//主模板
template<typename Head, typename... Tail>
class Tuple<Head, Tail...> : private Tuple<Tail...>
{
    using inherited = Tuple<Tail...>;

public:
    Tuple()
    {
    }

    Tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...)
    {
        cout << "创建元素：" << v << endl;
    }

    Head head()
    {
        return m_head;
    }

    inherited& tail()
    {
        return *this;
    }

protected:
    Head m_head;
};

int main()
{
    Print(100, "hello", 3.14, "world", '!');
    cout << endl;

    Tuple<int, const char*, double, const char*, char> t(100, "hello", 3.14, "world", '!');
    cout << t.head() << "\t输出完毕" << endl;
    cout << t.tail().head() << "\t输出完毕" << endl;
    cout << t.tail().tail().head() << "\t输出完毕" << endl;
    cout << t.tail().tail().tail().head() << "\t输出完毕" << endl;
    cout << t.tail().tail().tail().tail().head() << "\t\t输出完毕" << endl;

    return 0;
}