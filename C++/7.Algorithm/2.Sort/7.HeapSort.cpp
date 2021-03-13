#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//交换元素
void Swap(vector<int>& v, int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

//调整为大顶堆
void Heapify(vector<int>& v, int n, int parent)
{
    int left_child = 2 * parent + 1;
    int right_child = 2 * parent + 2;
    int max = parent;   //最大值索引

    if(left_child < n && v[left_child] > v[max])
    {
        max = left_child;
    }
    if(right_child < n && v[right_child] > v[max])
    {
        max = right_child;
    }

    if(max != parent)
    {
        Swap(v, parent, max);   //交换节点值
        Heapify(v, n, max);     //递归调整子堆
    }
}

//建堆
void BuildHeap(vector<int>& v, int n)
{
    //按数组顺序构建完全二叉树
    int last_node = n - 1;              //最后一个节点
    int parent = (last_node - 1) / 2;   //最后一个非叶子节点(最后一个节点的双亲节点)

    //从最后一个非叶子节点开始向上调整堆
    for(int i = parent; i >= 0; i--)
    {
        Heapify(v, n, i);   //调整
    }
}

//堆排序
void HeapSort(vector<int>& v, int n)
{
    BuildHeap(v, n);    //建堆

    for(int i = n - 1; i > 0; i--)
    {
        Swap(v, i, 0);      //堆顶节点(最大值)与最后一个节点交换
        Heapify(v, i, 0);   //调整除最后一个节点(最大值)剩下的节点 根节点以下已经为堆结构无需调整
    }
}

int main()
{
    srand(time(nullptr));

    vector<int> v(10);
    for(int& i : v)
    {
        i = rand() % 100;
        cout << i << " ";
    }
    cout << endl;

    HeapSort(v, v.size());

    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}