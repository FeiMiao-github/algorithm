#include <comm.h>

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> bit(k, 0);
        int cnt = 0;
        int ret = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (cnt == k)
            {
                return ret;
            }

            if (nums[i] <= k && bit[nums[i] - 1] == 0)
            {
                bit[nums[i] - 1] = 1;
                cnt++;
            }

            ret ++;
        }
        return ret;
    }
};

void test(const vector<int>& nums, int k, int expect) {
    Solution s;
    vector<int> params1 = nums;
    int res = s.minOperations(params1, k);
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
    // 输入：nums = [3,1,5,4,2], k = 2
    // 输出：4
    test({3,1,5,4,2}, 2, 4);
    // 输入：nums = [3,1,5,4,2], k = 5
    // 输出：5
    test({3,1,5,4,2}, 5, 5);
    // 输入：nums = [3,2,5,3,1], k = 3
    // 输出：4
    test({3,2,5,3,1}, 3, 4);
    return 0;
}