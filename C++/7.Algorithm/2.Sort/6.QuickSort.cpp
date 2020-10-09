#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void QuickSort(vector<int>& v, int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int key = v[start];
    int low = start;
    int high = end;

    while(low < high)
    {
        //从右向左找第一个小于key的值
        while(low < high && v[high] >= key)
        {
            high--;
        }
        if(low < high)
        {
            v[low] = v[high];
            low++;
        }

        //从左向右找第一个大于key的值
        while(low < high && v[low] < key)
        {
            low++;
        }
        if(low < high)
        {
            v[high] = v[low];
            high--;
        }
    }

    //low == high
    int mid = low = high;
    v[mid] = key;
    QuickSort(v, start, mid - 1);
    QuickSort(v, mid + 1, end);
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

    QuickSort(v, 0, v.size() - 1);

    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}