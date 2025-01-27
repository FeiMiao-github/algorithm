#include <comm.h>
#include <cstddef>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    vector<int> twoSum0(vector<int> &nums, int target) {
        vector<pair<size_t, int>> v;
        for (size_t i = 0; i < nums.size(); i++) {
            v.emplace_back(i, nums[i]);
        }

        std::sort(v.begin(), v.end(),
                  [](auto &a, auto &b) { return a.second < b.second; });

        size_t l = 0, r = nums.size() - 1;

        while (l < r) {
            int sum = v[l].second + v[r].second;
            if (sum == target)
                break;
            else if (sum < target)
                l++;
            else
                r++;
        }
        return vector<int>{static_cast<int>(v[l].first),
                           static_cast<int>(v[r].first)};
    }
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int another = target - nums[i];
            if (mp.contains(another)) {
                return {i, mp[another]};
            }
            mp[nums[i]] = i;
        }

        return {};
    }
};

void test(const vector<int> &nums, int target, const vector<int> &exp) {
    auto param = nums;
    auto res = Solution().twoSum(param, target);
    ug_check_set(res, exp);
}

int main() {
    test({2, 7, 11, 15}, 9, {0, 1});
    return 0;
}
