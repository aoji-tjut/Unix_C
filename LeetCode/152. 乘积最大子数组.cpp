class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        vector<int> v_max(nums), v_min(nums);

        for(int i = 1; i < nums.size(); ++i)
        {
            v_max[i] = max(v_max[i - 1] * nums[i], max(v_min[i - 1] * nums[i], nums[i]));
            v_min[i] = min(v_max[i - 1] * nums[i], min(v_min[i - 1] * nums[i], nums[i]));
        }

        return *max_element(maxF.begin(), maxF.end());
    }
};