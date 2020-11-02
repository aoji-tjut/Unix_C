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

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> res;
    set<int> s1, s2;
    map<int, int> m;

    for(auto i:nums1)
    {
        s1.insert(i);
    }
    for(auto i:nums2)
    {
        s2.insert(i);
    }

    for(auto i:s1)
    {
        m[i]++;
    }
    for(auto i:s2)
    {
        m[i]++;
    }

    for(auto i:m)
    {
        if(i.second > 1)
        {
            res.push_back(i.first);
        }
    }

    return res;
}

int main()
{
    vector<int> v1{};
    vector<int> v2{1, 1};
    vector<int> res = intersection(v1, v2);
    for(auto i:res)
    {
        cout << i << " ";
    }

    return 0;
}

