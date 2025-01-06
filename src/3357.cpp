#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int getMaxD(int adj_min, int adj_max, int amin, int amax, int diff)
    {
        return std::max((std::min(adj_max - amin, amax - adj_min) + 1) / 2, diff);
    }

    int getMaxDContMissing(int adj_min, int adj_max, int amin, int amax, int diff)
    {
        int d1 = std::min(getMaxD(adj_min, adj_max, amin, amax, diff), (adj_max - adj_min + 2) / 3);
        return std::max(d1, diff);
    }

    int minDifference(vector<int>& nums) {
        int nums_n = nums.size();
        int adjacent_min = INT_MAX, adjacent_max = 0;

        for (int i = 0; i < nums_n; i++)
        {
            if (nums[i] != -1
                && ((i > 0 && nums[i - 1] == -1) || ((i + 1 < nums_n) && (nums[i + 1] == -1))))
            {
                adjacent_min = min(nums[i], adjacent_min);
                adjacent_max = max(nums[i], adjacent_max);
            }
        }

        std::cout << "min adjacent is " << adjacent_min << ", max adjacent is " << adjacent_max << "\n";

        int pre_adjacent = -1;
        int ret = 0;
        for (int i = 0; i < nums_n; i++)
        {
            if (nums[i] == -1)
            {
                continue;
            }

            if (pre_adjacent >= 0)
            {
                if (i - pre_adjacent == 1)
                {
                    ret = std::max(ret, std::abs(nums[i] - nums[pre_adjacent]));
                }
                else if (i - pre_adjacent == 2)
                {
                    ret = getMaxD(adjacent_min, adjacent_max, std::min(nums[i], nums[pre_adjacent]), std::max(nums[i], nums[pre_adjacent]), ret);
                }
                else
                {
                    ret = getMaxDContMissing(adjacent_min, adjacent_max, std::min(nums[i], nums[pre_adjacent]), std::max(nums[i], nums[pre_adjacent]), ret);
                }
            }
            else if (i > 0)
            {
                ret = getMaxD(adjacent_min, adjacent_max, nums[i], nums[i], ret);
            }


            pre_adjacent = i;
        }

        return ret;
    }
};

int main()
{
    Solution s;
    // [1,2,-1,10,8]
    // vector<int> nums = {1,2,-1,10,8};
    // [8,1]
    vector<int> nums = {8,1};
    std::cout << "max d is " << s.minDifference(nums) << "\n";
    return 0;
}