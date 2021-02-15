#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <thread>
#include <unistd.h>
#include <future>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <forward_list>
#include <array>
#include <__hash_table>
#include <complex>
#include <tuple>
using namespace std;

void fun(int* p, int i)
{
    p = (decltype(p)) malloc(sizeof(int));
    *p = i;
}

int main()
{
    int a[2][3] = {1, 2, 3, 4, 5, 6};
    int* p = *a;
    int(* q)[3] = a;
    cout << a << endl;
    cout << p << endl;
    cout << q << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(q) << endl;
    cout << "---------------------------" << endl;

    int* pp = nullptr;
    fun(pp, 100);
    cout << *pp << endl;
    free(pp);

    return 0;
}
