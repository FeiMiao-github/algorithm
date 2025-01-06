#include "comm.h"

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> mp;
        for (size_t i = 0; i < power.size(); i++)
        {
            mp[power[i]] += 1;
        }

        int n = mp.size();
        decltype(mp)::iterator iter = mp.begin();
        int i = 1;
        int j = 0;
        vector<long long> dp(n + 1, 0);
        for (auto p = mp.begin(); p != mp.end(); p++)
        {
            while (iter->first < p->first - 2)
            {
                iter++;
                j++;
            }
            dp[i] = std::max(dp[i - 1], dp[j] + p->first * p->second);
            i++;
        }
        return dp[n];
    }
};

void test(const vector<int>& ns, long long expect_res)
{
    Solution s;
    vector<int> param = ns;
    // static_assert(s.maximumTotalDamage(param) == expect_res);
    long long res = s.maximumTotalDamage(param);
    if (res == expect_res)
    {
        cout << "[OK] res is " << res << "\n";
    }
    else
    {
        cout << "[FAILED] res is " << res << "\n";
    }
}

int main()
{
    // [1,1,3,4]
    test({1, 1, 3, 4}, 6);
    return 0;
}