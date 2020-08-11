#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    void* p1 = malloc(512);
    cout << p1 << endl;
    free(p1);

    vector<int>* p2 = new vector<int>;
    cout << p2 << endl;
    delete p2;

    void* p3 = ::operator new(512);
    cout << p3 << endl;
    ::operator delete(p3);

    int* p4 = allocator<int>().allocate(5);
    cout << p4 << endl;
    allocator<int>().deallocate(p4, 5);

    return 0;
}