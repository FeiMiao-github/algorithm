#include <comm.h>
#include <vector>

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int res = -1;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[0]) {
                if (target >= nums[0]) {
                    if (nums[mid] > target) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                } else {
                    l = mid + 1;
                }
            } else {
                if (target >= nums[0]) {
                    r = mid - 1;
                } else {
                    if (nums[mid] > target) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
            }
        }
        return res;
    }
};

void test(const vector<int> &nums, int target, int exp) {
    auto param1 = nums;
    auto res = Solution().search(param1, target);
    ug_check(res, exp);
}

int main() {
    test({4, 5, 6, 7, 0, 1, 2}, 0, 4);
    return 0;
}
