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

vector<int> findErrorNums(vector<int>& nums)
{
    vector<int> res;
    set<int> s;

    for(auto i:nums)
    {
        auto temp = s.insert(i);
        if(!temp.second)
        {
            res.push_back(i);
        }
    }

    int temp=1;
    for(auto i:s)
    {
        if(i!=temp)
        {
            res.push_back(temp);
            break;
        }
        temp++;
    }

    if(res.size()==1)
    {
        res.push_back(temp);
    }

    return res;
}

int main()
{
    vector<int> v1{1, 2, 2, 4};
    vector<int> v2;
    v2 = findErrorNums(v1);
    for(auto i:v2)
    {
        cout << i << " ";
    }

    return 0;
}

