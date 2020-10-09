#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void MergeArr(vector<int>& v, int start, int mid, int end)
{
    vector<int> v_copy(v);
    int cur = start;        //v中当前修改的位置
    int left = start;       //v_copy左边比较的位置
    int right = mid + 1;    //v_copy右边比较的位置

    //比较v_copy左右两边 在v中修改
    while(cur <= end)
    {
        if(left > mid)                          //左边处理完毕只剩右边
        {
            v[cur++] = v_copy[right++];
        }
        else if(right > end)                    //右边处理完毕只剩左边
        {
            v[cur++] = v_copy[left++];

        }
        else if(v_copy[left] < v_copy[right])   //左边小于右边
        {
            v[cur++] = v_copy[left++];
        }
        else                                    //右边小于等于左边
        {
            v[cur++] = v_copy[right++];
        }
    }
}

void MergeSort(vector<int>& v, int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    MergeSort(v, start, mid);
    MergeSort(v, mid + 1, end);

    MergeArr(v, start, mid, end);
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

    MergeSort(v, 0, v.size() - 1);

    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}