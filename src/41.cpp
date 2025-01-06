#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> arr(nums.size() + 1, 0);
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0 && nums[i] <= (int)nums.size())
            {
                arr[nums[i]] = 1;
            }
        }

        for (size_t i = 1; i < arr.size(); i++)
        {
            // std::cout << i << "m" << arr[i] << "\n";
            if (arr[i] != 1)
            {
                return i;
            }
        }
        return arr.size();
    }
};


int main()
{
    vector<int> nums{1};
    std::cout << Solution().firstMissingPositive(nums) << "\n";
    return 0;
}