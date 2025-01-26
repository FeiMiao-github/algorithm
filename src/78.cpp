#include <comm.h>

class Solution {
public:
    void subsets(vector<vector<int>> &res, vector<int> &nums, vector<int> &e,
                 int index, int len) {
        if (index + len > nums.size())
            return;

        if (len == 0) {
            res.push_back(e);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            e.push_back(nums[i]);
            subsets(res, nums, e, index + 1, len - 1);
            e.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        for (size_t i = 0; i < nums.size(); i++) {
            vector<int> e;
            subsets(res, nums, e, 0, i);
        }
        return res;
    }
};

void test(const vector<int> &v) {
    auto param = v;
    Solution().subsets(param);
}

int main() {
    test({1, 2, 3});
    return 0;
}
