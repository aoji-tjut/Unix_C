#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void BubbleSort(vector<int>& v, int n)
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

    BubbleSort(v, v.size());

    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}