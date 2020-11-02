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

int arrangeCoins(int n)
{
    int low = 1;
    int high = n;
    long mid, sum;

    while(low <= high)
    {
        mid = low + (high - low) / 2;
        sum = mid * (mid + 1) / 2;
        if(sum == n)
        {
            return (int) mid;
        }
        else if(n > sum)
        {
            low = (int) mid + 1;
        }
        else
        {
            high = (int) mid - 1;
        }
    }

    return high;
}

int main()
{
    vector<int> v1{};
    vector<int> v2{1, 1};
    cout << arrangeCoins(1804289383);

    return 0;
}

