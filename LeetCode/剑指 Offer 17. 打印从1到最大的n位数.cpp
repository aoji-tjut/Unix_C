class Solution
{
public:
    vector<int> res;
    int pos = 0;

    vector<int> printNumbers(int n)
    {
        string s = "0123456789";
        string str = "";
        dfs(s, str, n);

        return res;
    }

    void dfs(string& s, string& str, int k)
    {
        if(str.length() == k)
        {
            //去除前导零
            if(pos == 0)
            {
                pos = 1;
                return;
            }

            res.push_back(atoi(str.c_str()));
            return;
        }

        for(int i = 0; i < s.length(); ++i)
        {
            str += s[i];
            dfs(s, str, k);
            str.pop_back();
        }
    }
};