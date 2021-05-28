class Solution
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> s;
        int cur = 0;

        for(auto num : pushed)
        {
            s.push(num);

            while(!s.empty() && popped[cur] == s.top())
            {
                s.pop();
                cur++;
            }
        }

        return s.empty();
    }
};