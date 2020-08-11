#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    decltype(i) j = 'a';
    cout << typeid(i).name() << " " << i << endl;
    cout << typeid(j).name() << " " << j << endl;

    return 0;
}