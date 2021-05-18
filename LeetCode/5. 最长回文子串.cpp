class Solution
{
public:
    string longestPalindrome(string s)
    {
        int size = s.size();
        if(size == 1) return s;

        int max_len = 1;
        int begin = 0;
        vector <vector<bool>> dp(size, vector<bool>(size));
        for(int i = 0; i < size; i++) dp[i][i] = true;

        for(int j = 1; j < size; j++)
        {
            for(int i = 0; i < j; i++)
            {
                if(s[i] != s[j]) dp[i][j] = false;
                else if((j - 1) - (i + 1) + 1 < 2) dp[i][j] = true; //一个字符必为回文
                else dp[i][j] = dp[i + 1][j - 1];

                if(dp[i][j] && j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, max_len);
    }
};