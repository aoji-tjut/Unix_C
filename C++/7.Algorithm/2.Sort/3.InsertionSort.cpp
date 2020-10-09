#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void InsertionSort(vector<int>& v, int n)
{
    int temp;

    for(int i = 1; i < n; i++)
    {
        temp = v[i];

        int j = i;
        while(j >= 1 && v[j - 1] > temp)
        {
            v[j] = v[j - 1];
            j--;
        }

        v[j] = temp;
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

    InsertionSort(v, v.size());

    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}