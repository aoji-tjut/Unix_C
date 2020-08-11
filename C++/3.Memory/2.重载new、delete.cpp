#include <iostream>
#include <cstdlib>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A()\t\t" << this << endl;
    }

    ~A()
    {
        cout << "~A()\t" << this << endl;
    }

    static void* operator new(size_t size)
    {
        cout << "new" << endl;
        return (A*) malloc(size);
    }

    static void operator delete(void* ptr)
    {
        cout << "delete" << endl;
        free(ptr);
    }

    static void* operator new[](size_t size)
    {
        cout << "new[]" << endl;
        return (A*) malloc(size);
    }

    static void operator delete[](void* ptr)
    {
        cout << "delete[]" << endl;
        free(ptr);
    }
};

int main()
{
    A* p1 = new A;
    delete p1;
    cout << endl;

    A* p2 = new A[3];
    delete[] p2;

    return 0;
}