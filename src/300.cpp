#include <comm.h>
#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLIS1(vector<int> &nums) {
        vector<int> f(nums.size());
        int max_ret = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            f[i] = 1;
            for (size_t j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    f[i] = max(f[i], f[j] + 1);
                    max_ret = max(max_ret, f[i]);
                }
            }
        }

        return max_ret;
    }

    int lengthOfLIS(vector<int> &nums) {
        int res = 0;
        vector<int> d(nums.size() + 1);
        d[0] = INT32_MIN;

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > d[res]) {
                res++;
                d[res] = nums[i];
            } else {
                // size_t j = res;
                // for (; j > 0; j--) {
                //     if (nums[i] > d[j - 1]) {
                //         break;
                //     }
                // }
                // d[j] = min(d[j], nums[i]);
                int l = 0, r = res, pos = 0;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (d[mid] < nums[i]) {
                        l = mid + 1;
                        pos = mid;
                    } else {
                        r = mid - 1;
                    }
                    d[pos + 1] = nums[i];
                }
            }
        }

        return res;
    }
};

void test(const vector<int> &nums, int expect) {
    auto param = nums;
    auto res = Solution().lengthOfLIS(param);
    if (res == expect) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAIED]" << res << "\n";
    }
}

int main() {
    test({10, 9, 2, 5, 3, 7, 101, 18}, 4);
    test({0, 1, 0, 3, 2, 3}, 4);
    test({1, 3, 6, 7, 9, 4, 10, 5, 6}, 6);
    return 0;
}
