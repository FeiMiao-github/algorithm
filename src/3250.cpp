#include <comm.h>

class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int ans = 0;

        vector<vector<int>> dp(nums.size(), vector<int>(51, 0));
        for (int i = 0; i <= nums[0]; i++)
        {
            dp[0][i] = 1;
        }

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j <= nums[i]; j++)
            {
                for (int k = 0; k <= j; k++)
                {
                    if (nums[i - 1] - k >= nums[i] - j && nums[i] - j >= 0)
                    {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000007;
                    }
                }
            }
        }

        for (int v: dp[nums.size() - 1])
        {
            ans = (ans + v) % 1000000007;
        }

        return ans;
    }
};

void test(const vector<int>& ns, int expect_res)
{
    Solution s;
    vector<int> nums = ns;
    int res = s.countOfPairs(nums);
    assert(res == expect_res);
    std::cout << "res is " << res << "\n";
}

int main()
{
    test({2, 3, 2}, 4);
    return 0;
}