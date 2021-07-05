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

int main()
{
    int a[10] = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
    int target = 4;
    int l = 0;
    int r = 9;

    int temp;
    while(l < r)
    {
        temp = (l + r) / 2;
        if(a[temp] > target)
        {
            r = temp - 1;
        }
        if(a[temp] < target)
        {
            l = temp + 1;
        }
        else break;
    }

    int l_res, r_res;
    for(int i = temp; a[i] == target; i--)
    {
        l_res = i;
    }
    cout << l_res;
    for(int i = temp; a[i] == target; i++)
    {
        r_res = i;
    }
    cout << r_res;

    return 0;
}