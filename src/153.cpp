#include <comm.h>

class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = 0;
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[0] < nums[nums.size() - 1]) {
                res = 0;
                break;
            }

            if (nums[mid] <= nums[nums.size() - 1]) {
                if (nums[res] > nums[mid]) {
                    res = mid;
                }
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return nums[res];
    }
};

void test(const vector<int> &nums, int exp) {
    auto param1 = nums;
    auto res = Solution().findMin(param1);
    ug_check(res, exp);
}

int main() {
    test({3, 4, 5, 1, 2}, 1);
    test({4, 5, 6, 7, 0, 1, 2}, 0);
    test({2, 1}, 1);
    return 0;
}
