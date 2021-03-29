class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        vector<bool> dp(nums.size(), false);

        dp[0] = true;
        for(int i = 1; i < dp.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                //能跳到第j个 并且能从第j个跳到第i个
                if(dp[j] == true && j + nums[j] >= i)
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[dp.size() - 1];
    }
};