#include <comm.h>
#include <vector>

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        int n = nums.size();
        if (n % 2 || n < 2) {
            return false;
        }

        int max_num = nums[0];
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            max_num = max(max_num, nums[i]);
        }

        int target = sum / 2;
        if (max_num > target)
            return false;

        if (sum % 2 != 0)
            return false;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));
        for (int i = 0; i < nums.size(); i++)
            dp[i][0] = true;

        dp[0][nums[0]] = true;
        for (int k = 1; k <= target; k++)
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > k) {
                    dp[i][k] = dp[i - 1][k];
                } else {
                    dp[i][k] = dp[i - 1][k] || dp[i - 1][k - nums[i]];
                }
            }
        return dp[n - 1][target];
    }
};

void test(const vector<int> &nums, bool exp) {
    auto param = nums;
    auto res = Solution().canPartition(param);
    ug_check(res, exp);
}
int main() {
    test({1, 5, 11, 5}, true);
    test({1, 2, 3, 5}, false);
    return 0;
}
