#include <iostream>
#include <algorithm>
using namespace std;

void Print(int i)
{
    cout << i << " ";
}

int main()
{
    int i{666};
    cout << i << endl;

    int* p{nullptr};
    cout << p << endl;

    int a[10]{1, 2, 3, 4, 5};
    for_each(a, a + 10, Print);
    cout << endl;

    return 0;
}