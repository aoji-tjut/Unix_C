#include<iostream>
#include<vector>
using namespace std;

/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
*/

int minSubArrayLen(int s, vector<int>& nums)
{
    int size = nums.size();
    if(!size)
    {
        return 0;
    }

    int res = INT_MAX;
    int start = 0, end;
    int sum = 0;
    for(end = 0; end < size; end++)
    {
        sum += nums[end];
        while(sum >= s)
        {
            res = min(res, end - start + 1);
            sum -= nums[start];
            start++;
        }
    }

    return res == INT_MAX ? 0 : res;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << minSubArrayLen(15, v) << endl;

    return 0;
}

