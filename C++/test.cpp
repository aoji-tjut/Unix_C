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

void A(int* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        a[i]++;
    }
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    cout << sizeof(a) << endl;

    A(a, sizeof(a) / sizeof(*a));

    for(int i = 0; i < 5; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}