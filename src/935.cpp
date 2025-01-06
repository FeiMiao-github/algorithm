#include "comm.h"

class Solution
{
public:
    static const vector<vector<int>> tb;
    const int mod = 1e9 + 7;
    int knightDialer(int n)
    {
        vector<vector<int>> dp(2, vector<int>(10, 0));

        for (size_t i = 0; i < dp[0].size(); i++)
        {
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            int id = i % 2;
            for (int j = 0; j < 10; j++)
            {
                dp[id][j] = 0;
                for (int k : tb[j])
                {
                    dp[id][j] = (dp[id][j] + dp[id ^ 1][k]) % mod;
                }
            }
        }

        int res = 0;
        for (int x : dp[(n - 1) % 2])
        { 
            res = (res + x) % mod;
        }
        return res;
    }
};

const vector<vector<int>> Solution::tb = {
    {4, 6},
    {6, 8},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {1, 7, 0},
    {2, 6},
    {1, 3},
    {2, 4}};

int main()
{
    std::cout << Solution().knightDialer(3131) << "\n";
    return 0;
}