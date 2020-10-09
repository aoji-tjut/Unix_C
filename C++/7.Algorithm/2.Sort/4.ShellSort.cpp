#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void ShellSort(vector<int>& v, int n)
{
    int temp;

    //增量每次减小一半
    for(int increase = n / 2; increase > 0; increase /= 2)
    {
        //插入排序
        for(int i = increase; i < n; i++)
        {
            temp = v[i];

            int j = i;
            while(j >= increase && v[j - increase] > temp)
            {
                v[j] = v[j - increase];
                j -= increase;
            }

            v[j] = temp;
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

    ShellSort(v, v.size());

    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}