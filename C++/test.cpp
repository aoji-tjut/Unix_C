#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <thread>
#include <unistd.h>
#include <future>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <forward_list>
#include <array>
#include <__hash_table>
#include <complex>
#include <tuple>
using namespace std;

/*
struct Node
{
    int data;
    Node* next;
};

void Init(Node*& L)
{
    Node* cur = nullptr;

    for(int i = 1; i <= 5; i++)
    {
        if(!L)
        {
            L = new Node;
            L->data = i;
            L->next = nullptr;
            cur = L;
            continue;
        }

        Node* temp = new Node;
        temp->data = i;
        temp->next = nullptr;

        cur->next = temp;
        cur = temp;
    }
}

void Delete(Node*& L)
{
    Node* cur = L;
    Node* tail = nullptr;

    while(cur->next)
    {
        tail = cur;
        cur = cur->next;
    }

    cout << "delete " << cur->data << endl;
    delete cur;
    tail->next = nullptr;
}

void Print(Node* L)
{
    Node* cur = L;
    while(cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "输出结束" << endl;
}

int main()
{
    Node* L = nullptr;

    Init(L);
    Print(L);

    Delete(L);
    Delete(L);
    Delete(L);
    Print(L);

    return 0;
}
*/

void print(int i)
{
    cout << i << " ";
}

void fff(int& i)
{
    i = i * 2;
}

struct S
{
private:
    int i;

    S()
    {
        cout << "asd";
    }
};

void fun()
{
    int a[5]{1, 2, 3, 4, 5};
    for(int i:a)
    {
        cout << i << " ";
    }
}

void fun(char, int);

int g_i;

typedef int Array[100];

void Swap(int i, int j)
{
    cout << &i << endl;
    cout << &j << endl;
    int temp;
    temp = i;
    i = j;
    j = temp;
}

void Point()
{
    int i = 10;
    int j = 20;
    const int* p = &i;  //常量指针 指向常量的指针
    int* const q = &i;  //指针常量 指针是一个常量
    const int* const r = &i;
    cout << *p << "\t" << *q << "\t" << *r << endl;

    p = &j;
    *q = 5;

    cout << *p << "\t" << *q << "\t" << *r << endl;
}

int AAA()
{
    return 6;
}

//////////////////////////////////////////////////////////////////////////////////////////
int main()
{



    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////


void fun(char c, int i)
{
    cout << c << endl;
}

