#include <iostream>
#include <vector>
using namespace std;

template<typename T>
using V = vector<T>;

int add(int i, int j)
{
    return i + j;
}

int sub(int i, int j)
{
    return i - j;
}

int main()
{
    V<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;

    V<char> v2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    for(auto c : v2)
    {
        cout << c << " ";
    }
    cout << endl;

    typedef int (* fun1)(int, int);
    fun1 f1 = add;
    cout << f1(10, 20) << endl;

    using fun2 = int (*)(int, int);
    fun2 f2 = sub;
    cout << f2(10, 20) << endl;

    return 0;
}