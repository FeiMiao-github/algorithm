#include <comm.h>

class Solution {
public:
    vector<vector<int>> res;
    vector<int> eles;
    int sum = 0;

    void backtarce(vector<int> &candidates, int target, int index) {
        if (sum == target) {
            res.push_back(eles);
            return;
        }

        for (size_t i = index; i < candidates.size(); i++) {
            sum += candidates[i];
            if (sum > target) {
                return;
            }
            eles.push_back(candidates[i]);
            backtarce(candidates, target, i);
            eles.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtarce(candidates, target, 0);
        return res;
    }
};

void test(const vector<int> &candidates, int target,
          const vector<vector<int>> &exp) {
    auto param1 = candidates;
    auto res = Solution().combinationSum(param1, target);
    ug_check(res, exp);
}

int main() {
    test({2, 3, 6, 7}, 7, {{2, 2, 3}, {7}});
    return 0;
}
