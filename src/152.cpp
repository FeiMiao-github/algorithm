#include <comm.h>

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        vector<int> minf(nums.begin(), nums.end()),
            maxf(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); i++) {
            minf[i] =
                min(minf[i - 1] * nums[i], min(maxf[i - 1] * nums[i], nums[i]));
            maxf[i] =
                max(minf[i - 1] * nums[i], max(maxf[i - 1] * nums[i], nums[i]));
        }
        return *max_element(maxf.begin(), maxf.end());
    }
};

void test(const vector<int> &nums, int exp) {
    auto param = nums;
    auto res = Solution().maxProduct(param);
    ug_check(res, exp);
}

int main() {
    test({2, 3, -2, 4}, 6);
    test({0, 2}, 2);
    return 0;
}
