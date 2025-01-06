#include "comm.h"

class Solution {
public:
    struct cmp {
        cmp(vector<vector<int>>& nums, vector<int>& index) : nums(nums), index(index) {}

        bool operator()(int i, int j) {
            return nums[i][index[i]] > nums[j][index[j]];
        }

        vector<vector<int>>& nums;
        vector<int>& index;
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans {0, INT32_MAX};
        vector<int> index(nums.size(), 0);
        int sz = nums.size();
        int min_value; int max_value = INT32_MIN;

        std::priority_queue<int, vector<int>, cmp> pq(cmp(nums, index));
        for (int i = 0; i < sz; i++)
        {
            pq.emplace(i);
            max_value = max(max_value, nums[i][index[i]]);
        }

        while (true)
        {
            int row = pq.top();
            pq.pop();

            min_value = nums[row][index[row]];
            if ((max_value - min_value) < (ans[1] - ans[0]))
            {
                ans[1] = max_value;
                ans[0] = min_value;
            }

            index[row]++;
            if (index[row] == nums[row].size())
            {
                break;
            }

            max_value = max(max_value, nums[row][index[row]]);
            pq.emplace(row);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<vector<int>> nums = {{1}};
    vector<int> ans = s.smallestRange(nums);
    cout << ans << endl;
    return 0;
}