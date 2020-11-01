#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <thread>
#include <unistd.h>
#include <future>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <forward_list>
#include <array>
#include <__hash_table>
#include <complex>
#include <tuple>
using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned)
{
    map<string, int> m_s;
    map<string, int> m_v;
    map<int, string, greater<>> res;

    for(auto i :banned)
    {
        m_v[i]++;
    }

    string temp;
    for(int i = 0; i < paragraph.size(); i++)
    {
        if(paragraph[i] >= 'A' && paragraph[i] <= 'Z')
        {
            paragraph[i] = tolower(paragraph[i]);
        }

        if(paragraph[i] >= 'a' && paragraph[i] <= 'z')
        {
            temp.push_back(paragraph[i]);
        }
        else
        {
            if(m_v.find(temp) == m_v.end() && !temp.empty())
            {
                m_s[temp]++;
            }

            temp.clear();
        }
    }

    if(m_v.find(temp) == m_v.end())
    {
        m_s[temp]++;
    }

    for(auto i :m_s)
    {
        res[i.second] = i.first;
    }

    return res.begin()->second;
}

int main()
{
    vector<string> v{"bob", "hit"};
    cout << mostCommonWord("Bob. hIt, baLl", v);

    return 0;
}

