#include <iostream>
#include <array>    //静态数组
using namespace std;

int main()
{
    array<int, 10> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}