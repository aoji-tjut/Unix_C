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
#include <complex>
#include <tuple>
#include <climits>
using namespace std;

class A
{
public:
    int i;
    int* p;

    A(int i)
    {
        this->i = i;
        this->p = &this->i;
    }
};

int main()
{
    A a(10);
    cout << a.p << " " << *a.p << endl;

    A aa(a);
    cout << aa.p << " " << *aa.p << endl;

    a.i++;
    cout << a.p << " " << *a.p << endl;
    cout << aa.p << " " << *aa.p << endl;

    return 0;
}