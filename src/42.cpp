#include "comm.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int r = height.size() - 1;
        int l = 0;
        int ans = 0;
        while (l < r)
        {
            if (height[l] < height[l + 1])
            {
                l++;
                continue;
            }

            int i = l + 1;
            int i2 = l + 1;
            for (; i <= r; i++)
            {
                if (height[i] > height[l])
                {
                    break;
                }
                else if (height[i] > height[i - 1])
                {
                    if (i2 == -1)
                    {
                        i2 = i;
                    }
                    else if (height[i] > height[i2])
                    {
                        i2 = i;
                    }
                }
            }

            if (i2 != -1)
                i = std::min(i, i2);

            int min_val = std::min(height[i], height[l]);
            for (int j = l; j < i; j++)
            {
                ans += std::max(0, min_val - height[j]);
            }
            l = i;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << "res is " << Solution().trap(nums) << "\n";
    return 0;
}