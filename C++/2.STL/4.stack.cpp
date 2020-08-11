#include <iostream>
#include <stack>    //序列式容器 栈(容器适配器) 底层deque 先进后出 栈顶进栈顶出 只能访问栈顶 不能遍历 deque一部分
using namespace std;

int main()
{
    stack<int> s;
    for(int i = 0; i < 10; i++)
    {
        s.push(i);                  //入栈
    }

    cout << s.size() << endl;       //栈大小

    while(!s.empty())               //判空
    {
        cout << s.top() << " ";     //栈顶元素
        s.pop();                    //出栈
    }

    return 0;
}