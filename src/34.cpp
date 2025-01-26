#include <comm.h>
#include <vector>

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> res(2, -1);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                res[0] = mid, res[1] = mid;
                for (int i = mid - 1; i >= 0; i--) {
                    if (nums[i] == target) {
                        res[0] = i;
                    }
                }

                for (int i = mid + 1; i < nums.size(); i++) {
                    if (nums[i] == target) {
                        res[1] = i;
                    }
                }
                break;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};

void test(const vector<int> &arr, int target, const vector<int> &expect) {
    auto param = arr;
    auto res = Solution().searchRange(param, target);
    if (res != expect) {
        std::cout << "[FAILED]" << res << "\n";
    } else {
        std::cout << "[OK]\n";
    }
}

int main() {
    test({5, 7, 7, 8, 8, 10}, 8, {3, 4});
    return 0;
}
