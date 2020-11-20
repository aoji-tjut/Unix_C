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

bool validMountainArray(vector<int>& A)
{
    int size = A.size();
    int l = 0;
    int r = size - 1;

    while(l + 1 < size && A[l] < A[l + 1])
    {
        l++;
    }

    while(r > 0 && A[r - 1] > A[r])
    {
        r--;
    }

    if((l > 0) && (r < size - 1) && (l == r))
    {
        return true;
    }

    return false;
}

int main()
{
    char str[]="hello";
    cout << sizeof(str) << endl;
    cout << strlen(str);


    return 0;
}

