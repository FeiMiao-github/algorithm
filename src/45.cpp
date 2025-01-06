#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int max_pos = 0;
        int end = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            max_pos = max(nums[i] + i, max_pos);
            if (i == end)
            {
                end = max_pos;
                ++steps;
            }
        }
        return steps;      
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    std::cout << "canJump is " << (s.jump(nums)) << "\n";
    return 0;
}