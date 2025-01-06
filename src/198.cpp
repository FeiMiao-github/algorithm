#include "comm.h"

class Solution {
public:
    unordered_map<int, int> mp;

    int robInner(vector<int>& nums, int n)
    {
        if (n < 0)
        {
            return 0;
        }
        else if (mp.find(n) != mp.end())
        {
            return mp[n];
        }

        int maxvalue = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxvalue = std::max(maxvalue, robInner(nums, i));
        }
        
        int res = maxvalue + nums[n];
        mp[n] = res;
        return res;
    }

    int rob(vector<int>& nums) {
        int maxvalue = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            maxvalue = std::max(maxvalue, robInner(nums, i));
        }
        return maxvalue;
    }
};

int main()
{
    Solution s;
    vector<int> nums {1,2,3,1};
    std::cout << "rob res is " << s.rob(nums) << "\n";
    return 0;
} 