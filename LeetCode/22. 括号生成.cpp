class Solution
{
public:
    vector <string> res;

    void dfs(string s, int l, int r, int n)
    {
        if(l > n)
        {
            return;
        }

        if(l == n && r == n)
        {
            res.push_back(s);
            return;
        }

        if(l == r)
        {
            dfs(s + "(", l + 1, r, n);
        }
        else
        {
            dfs(s + "(", l + 1, r, n);
            dfs(s + ")", l, r + 1, n);
        }
    }

    vector <string> generateParenthesis(int n)
    {
        dfs("", 0, 0, n);

        return res;
    }
};