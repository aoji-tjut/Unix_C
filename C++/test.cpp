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
    cout << 16 << endl;

    map<char, int> m;
    char c='a';
    for(int i=0;i<5;i++)
    {

        cin >> m[c+i];
    }

    for(auto i : m)
    {
        cout << i.second<<endl;
    }


    return 0;
}