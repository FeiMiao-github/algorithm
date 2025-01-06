#include "comm.h"

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int sz = colors.size();
        vector<int> dp(sz, 0);
        dp[sz - 1] = 1;
        for (int i = sz - 1; i > 0; i--)
        {
            if (colors[i] != colors[i - 1])
            {
                dp[i - 1] = dp[i] + 1;
            }
            else
            {
                dp[i - 1] = 1;
            }
        }

        if (colors[0] != colors[sz - 1])
        {
            for (int i = sz - k + 1; i < sz; i++)
            {
                if (dp[i] == sz - i)
                {
                    dp[i] = dp[i] + dp[0];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < sz; i++)
        {
            if (dp[i] >= k)
            {
                ans++;
            }
        }
        return ans;
    }
};

void TEST_F(const vector<int>& num, auto k, auto ans)
{
    vector<int> nums = num;
    Solution s;
    int res;
    res = s.numberOfAlternatingGroups(nums, k);
    assert(res == ans);
    std::cout << "res is " << res << "\n";
}

int main()
{
    TEST_F({0, 1, 0, 0, 1, 0, 1}, 6, 2);

    // 0,1,0,1,0, 3
    TEST_F({0, 1, 0, 1, 0}, 3, 3);

    // 0, 0, 1,  3
    TEST_F({0, 0, 1}, 3, 1);

    // 0, 1, 1 3
    TEST_F({0, 1, 1}, 3, 1);
    return 0;
}