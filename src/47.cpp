#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// std::cout vector<int>
std::ostream& operator<<(std::ostream& os, const vector<int>& arr)
{
    os << "{";
    for (auto &v: arr)
    {
        os << v << ",";
    }
    return os << "}";
}

// std::cout vector<vector<int>>
std::ostream& operator<<(std::ostream& os, const vector<vector<int>>& arrs)
{
    os << "{";
    for (auto p = arrs.cbegin(); p != arrs.end(); p++)
    {
        os << *p << ",";
    }
    os << "}";
    return os;
}

class Solution {
public:
    void inner(vector<vector<int>>& ans, vector<int> &nums, vector<int> &flags, vector<int>& seq)
    {
        if (seq.size() == nums.size())
        {
            ans.push_back(seq);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (flags[i] == 1 || (i > 0 && (nums[i - 1] == nums[i]) && (flags[i - 1] == 0)))
            {
                continue;
            }

            seq.push_back(nums[i]);
            flags[i] = 1;
            inner(ans, nums, flags, seq);
            flags[i] = 0;
            seq.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> seq;
        vector<int> flag(nums.size(), 0);
        std::sort(nums.begin(), nums.end());
        inner(ans, nums, flag, seq);
        return ans;       
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 3, 0, 3};
    std::cout << "permute is " << s.permuteUnique(nums) << "\n";
    return 0;
}