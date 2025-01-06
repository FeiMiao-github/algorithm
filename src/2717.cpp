#include "comm.h"

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int ret = 0;
        int i = nums.size() - 1;
        while (nums[i] != nums.size())
        {
            i--;
        }

        for (int j = i + 1; j < nums.size(); j++)
        {
            std::swap(nums[j], nums[j - 1]);
            ret ++;
        }

        i = 0;
        while (nums[i] != 1)
        {
            i++;
        }

        return ret + i;
    }
};

int main()
{
    vector<int> param1 = {2,1,4,3};
    std::cout << "res is " << Solution().semiOrderedPermutation(param1) << "\n";
    return 0;
}