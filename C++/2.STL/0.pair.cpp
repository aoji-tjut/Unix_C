#include <iostream>
using namespace std;

int main()
{
    //对组
    pair<int, char> p1(10, 'A');
    cout << p1.first << " " << p1.second << endl;

    pair<int, char> p2 = make_pair(20, 'B');
    cout << p2.first << " " << p2.second << endl;

    return 0;
}