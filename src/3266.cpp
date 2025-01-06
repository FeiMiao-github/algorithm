#include "comm.h"

class Solution {
public:
    using tp = std::pair<int, long long>;

    static constexpr int mod = 1000000007;

    struct Greater {
        bool operator()(const tp& a, const tp& b) {
            return (a.second > b.second) || (a.second == b.second && a.first > b.first);
        }
    };

    // long long pow(long long x, long long y) {
    //     long long res = 1;
    //     while (y > 0) {
    //         if (y & 1) {
    //             res *= x;
    //         }
    //         x = x * x % mod;
    //         y >>= 1;
    //     }
    //     return res;
    // }

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        std::priority_queue<tp, std::vector<tp>, Greater> q;
        int max_val = *max_element(nums.begin(), nums.end());
        int n = (int)nums.size();
        for (size_t i = 0; i < nums.size(); i++) {
            q.emplace(i, nums[i]);
        }
        for (; k > 0 && q.top().second < max_val; k--) {
            auto [idx, val] = q.top();
            q.pop();
            val = val * multiplier;
            q.emplace(idx, val);
        }

        int i = 0;
        int t = k / n;
        long long pow1 = pow(multiplier, t);
        long long pow2 = pow1 * multiplier;

        while (!q.empty()) {
            auto iter = q.top();
            long long v = iter.second;
            int idx = iter.first;
            q.pop();
            if (i < k % n) {
                v = v % mod * pow2 % mod;
            }
            else {
                v = v % mod * pow1 % mod;
            }
            i++;
            nums[idx] = v;
        }
        return move(nums);
    }
};

void test(const vector<int>& nums, int k, int multiplier, const vector<int>& expect) {
    Solution s;
    vector<int> params1 = nums;
    vector<int> expect1 = expect;
    auto res = s.getFinalState(params1, k, multiplier);
    if(res == expect)
    {
        cout << "[OK] res is " << res << "\n";
    }
    else
    {
        cout << "[FAILED] res is " << res << "\n";
    }
}

int main()
{
    // 输入：nums = [2,1,3,5,6], k = 5, multiplier = 2
    // 输出：[8,4,6,5,6]
    test({2,1,3,5,6}, 5, 2, {8,4,6,5,6});
    // 输入：nums = [100000,2000], k = 2, multiplier = 1000000
    // 输出：[999999307,999999993]
    test({100000,2000}, 2, 1000000, {999999307,999999993});
    // 输入：nums = [4, 2, 4], k = 3, multiplier = 2
    // 输出：[8,8,4]
    test({4, 2, 4}, 3, 2, {8, 8, 4});
    // 输入：nums = [161209470], k = 56851412, multiplier = 39846
    // 输出：[198168519]
    test({161209470}, 56851412, 39846, {198168519});
    // [66307295,441787703,589039035,322281864], k = 900900704, multiplier = 641725
    test({66307295,441787703,589039035,322281864}, 900900704, 641725, {66307295,441787703,589039035,322281864});
    return 0;
}