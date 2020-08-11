#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)
*/

int threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());

    int size = nums.size();
    int b;
    int e;
    int sum;
    int res = nums[0] + nums[1] + nums[2];

    for(int cur = 0; cur < size - 1; cur++)
    {
        b = cur + 1;
        e = size - 1;

        while(b < e)
        {
            sum = nums[cur] + nums[b] + nums[e];
            if(abs(target - res) > abs(target - sum))
            {
                res = sum;
            }

            if(sum == target)
            {
                return sum;
            } else if(sum < target)
            {
                b++;
            } else if(sum > target)
            {
                e--;
            }
        }
    }

    return res;
}

int main()
{
    vector<int> v = {-1, 2, 1, -4};
    cout << threeSumClosest(v, 1);

    return 0;
}

