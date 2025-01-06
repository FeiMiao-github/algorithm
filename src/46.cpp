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
    void inner(vector<vector<int>>& ans, vector<int> &nums, int len, vector<int>& seq)
    {
        if (len == 0)
        {
            ans.push_back(seq);
            return;
        }

        for (int i = 0; i < len; i++)
        {
            seq.push_back(nums[i]);
            std::swap(nums[i], nums[len - 1]);
            inner(ans, nums, len - 1, seq);
            std::swap(nums[len - 1], nums[i]);
            seq.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> seq;
        inner(ans, nums, nums.size(), seq);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    std::cout << "permute is " << s.permute(nums) << "\n";
    return 0;
}