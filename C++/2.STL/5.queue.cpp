#include <iostream>
#include <queue>    //序列式容器 队(容器适配器) 底层deque 先进先出 队尾进队头出 只能访问队头队尾 不能遍历
using namespace std;

int main()
{
    queue<int> q;
    for(int i = 0; i < 10; i++)
    {
        q.push(i);                                      //入队
    }

    cout << q.size() << endl;                           //队大小

    while(!q.empty())                                   //判空
    {
        cout << q.front() << " " << q.back() << endl;   //队头队尾元素
        q.pop();                                        //出队
    }

    return 0;
}