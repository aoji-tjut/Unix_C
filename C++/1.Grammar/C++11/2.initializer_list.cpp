#include <iostream>
#include <algorithm>
using namespace std;

void Print(int i)
{
    cout << i << " ";
}

class A
{
public:
    A(int i, int j)
    {
        cout << "A()" << endl;
        cout << i << " " << j << endl;
    }

    A(initializer_list<int> init_list)
    {
        cout << "A{}" << endl;
        for_each(init_list.begin(), init_list.end(), Print);
        cout << endl;
    }
};

int main()
{
    A(1, 2);
    A{1, 2, 3, 4, 5};

    return 0;
}