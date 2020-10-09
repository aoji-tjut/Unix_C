#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int SequentialSearch(vector<int>& v, int n, int value)
{
    for(int i = 0; i < n; i++)
    {
        if(v[i] == value)
        {
            return i;
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
    int pos = SequentialSearch(v, v.size(), value);

    cout << "value=" << value << endl;
    cout << "pos=" << pos << endl;

    return 0;
}