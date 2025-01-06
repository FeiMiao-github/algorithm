#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_dist = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > max_dist)
            {
                return false;
            }

            if (nums[i] + i > max_dist)
            {
                max_dist = nums[i] + i;
            }
        }

        return max_dist >= nums.size() - 1;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {2,0};
    std::cout << "canJump is " << (s.canJump(nums) ? "true" : "false" )<< "\n";
    return 0;
}