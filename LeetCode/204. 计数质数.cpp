class Solution
{
public:
    int countPrimes(int n)
    {
        if(n < 2)
        {
            return 0;
        }

        vector<bool> v(n, true);

        for(long long i = 2; i < n; i++)
        {
            if(v[i])
            {
                for(long long j = i * i; j < n; j += i)
                {
                    v[j] = false;
                }
            }
        }

        return accumulate(v.begin(), v.end(), 0) - 2;   //减去0和1
    }
};