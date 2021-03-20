class Solution
{
public:
    vector <vector<int>> threeSum(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        vector <vector<int>> res;

        for(int a = 0; a < nums.size(); a++)
        {
            if(a > 0 && nums[a] == nums[a - 1])
            {
                continue;
            }

            int c = nums.size() - 1;
            int target = -nums[a];

            for(int b = a + 1; b < nums.size(); b++)
            {
                if(b > a + 1 && nums[b] == nums[b - 1])
                {
                    continue;
                }

                while(b < c && nums[b] + nums[c] > target)
                {
                    c--;
                }

                if(b == c)
                {
                    break;
                }

                if(nums[b] + nums[c] == target)
                {
                    res.push_back({nums[a], nums[b], nums[c]});
                }
            }
        }

        return res;
    }
};