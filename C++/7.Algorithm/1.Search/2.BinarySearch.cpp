#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void Sort(vector<int>& v, int n)
{
    bool change;
    int temp;

    for(int i = 0; i < n - 1; i++)
    {
        change = false;

        for(int j = 0; j < n - i - 1; j++)
        {
            if(v[j] > v[j + 1])
            {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                change = true;
            }
        }

        if(!change)
        {
            break;
        }
    }

    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int BinarySearch(vector<int>& v, int n, int value)
{
    //排序
    Sort(v, n);

    int low = 0;
    int high = n - 1;
    int mid;
    while(low <= high)
    {
        mid = low + (high - low) / 2;

        if(value > v[mid])
        {
            low = mid + 1;
        }
        else if(value < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
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

    int value = v[rand() % 10];
    int pos = BinarySearch(v, v.size(), value);

    cout << "value=" << value << endl;
    cout << "pos=" << pos << endl;

    return 0;
}