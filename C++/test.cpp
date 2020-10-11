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

int main()
{
    int size;
    cin >> size;

    int a[size];
    for(int i = 0; i < size; i++)
    {
        a[i] = i;
    }
    for(int i:a)
    {
        cout << i << " ";
    }

    return 0;
}

