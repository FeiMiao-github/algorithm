#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int k = 0;
       for (int i = 0; i < nums.size(); ++i)
       {
            if (nums[i] != val)
            {
                nums[k] = nums[i];
                ++k;
            }
       }
       return k;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {3, 2, 2, 3};
    std::cout << "count is " << s.removeElement(nums, 3) << "\n";
    return 0;
}