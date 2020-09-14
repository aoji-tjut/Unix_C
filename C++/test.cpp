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









    return 0;
}