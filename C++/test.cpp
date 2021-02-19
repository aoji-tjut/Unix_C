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
//    int a[2][3] = {1, 2, 3, 4, 5, 6};
//    int* p = *a;
//    int(* q)[3] = a;
//    cout << a+1 << endl;
//    cout << p+1 << endl;
//    cout << q+1 << endl;
//    cout << sizeof(a) << endl;
//    cout << sizeof(p) << endl;
//    cout << sizeof(q) << endl;
//    cout << "---------------------------" << endl;

//    int num = 1;
//    int a[2][3][4];
//    for(int i = 0; i < 2; i++)
//    {
//        for(int j = 0; j < 3; j++)
//        {
//            for(int k = 0; k < 4; k++)
//            {
//                a[i][j][k] = num++;
//            }
//        }
//    }
//
//    int* p = **a;
//    for(int i = 0; i < 24; i++)
//    {
//        cout << *(p++) << endl;
//    }
//    cout << endl;
//
//    int (* q)[3][4] = a;
//    cout << ***(q + 1) << endl;
//
//    int (* r)[4] = *a;
//    cout << **(r + 1) << endl;
//    cout << "---------------------------" << endl;

//    int* pp = nullptr;
//    fun(pp, 100);
//    cout << *pp << endl;
//    free(pp);
//    cout << "---------------------------" << endl;

//    int aa[] = {5, 1, 7, 2, 8, 3};
//    int y;
//    int* ppp = &aa[1];
//    y = (*--ppp)++;
//    cout << y << endl;
//    cout << aa[0] << endl;




    return 0;
}

