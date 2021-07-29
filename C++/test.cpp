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

struct bbox
{
    int classes;
    int xmin, ymin, xmax, ymax;
    float pro;
};

bool fun(bbox i, bbox j)
{
    if(i.pro > j.pro)
    {
        return true;
    }
    return false;
}



float Iou(bbox i, bbox j)
{
    int h, w;

    return (h * w) / ((i.xmax - i.xmin) * (i.ymax - i.ymin) + (j.xmax - j.xmin) * (j.ymax - j.ymin) - h * w) * 1.0;
}

vector<bbox>& nms(vector<bbox> v, float iou)
{

    for(int i=0;i<v.size();i++)
    {
        sort(v.begin(), v.begin(), fun);
        bbox max = *v.begin();

        for(int j = 1; j < v.size(); j++)
        {
            if(Iou(v[j], max) > iou)
            {
                v[j].pro=0;
            }
        }
    }

    return v;
}

int main()
{

    return 0;
}




