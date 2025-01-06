#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> len(nums.size());
        len[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i-1] + 1)
            {
                len[i] = len[i-1] + 1;
            }
            else
            {
                len[i] = 1;
            }
        }

        vector<int> powers;
        for (int i = k-1; i < nums.size(); i++)
        {
            if (len[i] >= k)
            {
                powers.emplace_back(nums[i]);
            }
            else
            {
                powers.emplace_back(-1);
            }
        }
        return powers;
    }
};

std::ostream &operator<<(std::ostream& out, const std::vector<int>& vec)
{
    std::cout << "{";
    for (auto p = vec.cbegin(); p != vec.cend(); p++)
    {
        std::cout << *p << ", ";
    }
    std::cout << "}\n";
    return out;
}

int main()
{
    Solution s;
    std::vector<int> nums = {1,2,3,4,3,2,5};
    std::cout << "count is " << s.resultsArray(nums, 3) << "\n";
    return 0;
}