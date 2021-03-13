#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void SelctionSort(vector<int>& v, int n)
{
    int min_index;
    int temp;

    for(int i = 0; i < n - 1; i++)
    {
        min_index = i;

        for(int j = i + 1; j < n; j++)
        {
            if(v[min_index] > v[j])
            {
                min_index = j;
            }
        }

        if(min_index != i)
        {
            temp = v[i];
            v[i] = v[min_index];
            v[min_index] = temp;
        }
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

    SelctionSort(v, v.size());

    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}