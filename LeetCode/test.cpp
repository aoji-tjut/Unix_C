#include <iostream>
#include <cstdlib>
using namespace std;

void fun(int** p)
{
    *p = (int*) malloc(sizeof(int));
    **p=5;
}

int main()
{
    int* p = nullptr;
    fun(&p);
    cout << *p << endl;
    free(p);

    return 0;
}