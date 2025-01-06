#include <iostream>
#include <vector>

using namespace std;

// std::cout vector
std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec)
{
    os << "{";
    for (auto p = vec.cbegin(); p != vec.cend(); p++)
    {
        os << *p << ", ";
    }
    os << "}";
    return os << "}";
}

class Solution {
public:
    bool check(int k, vector<int>& nums, vector<int>& diff, vector<vector<int>>& queries)
    {
        bool ret = true;
        std::fill(diff.begin(), diff.end(), 0);

        for (size_t i = 0; i < k; i++)
        {
            auto &q = queries[i];
            auto l = q[0];
            auto r = q[1];
            auto v = q[2];

            diff[l] += v;
            if (r + 1 < nums.size())
                diff[r + 1] -= v;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += diff[i];
            if (sum < nums[i])
            {
                ret = false;
            }
        }

        // std::cout << "k is " << k << ", ret is " << ret << "num is " << nums << "\n";
        // std::cout << "diff is " << diff << "\n";

        return ret;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0;
        int r = queries.size() + 1;
        vector<int> diff(nums.size());

        while (l < r)
        {
            int m = l + (r - l) / 2;
            // std::cout << "m is " << m << "\n";
            if (check(m, nums, diff, queries))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }

        }

        return r <= queries.size() ? r: -1;
    }
};

int main()
{
    Solution s;
    // [0, 10]
    // vector<int> nums = {0, 10};
    // [[0,1,2],[0,0,2],[0,1,2],[1,1,4],[0,1,3],[1,1,4],[0,1,2],[0,1,2],[0,1,2],[0,0,2],[1,1,2],[0,0,2],[0,0,3],[1,1,3],[0,0,5]]
    // vector<vector<int>> querieries = {{0, 1, 2}, {0, 0, 2}, {0, 1, 2}, {1, 1, 4}, {0, 1, 3}, {1, 1, 4}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 0, 2}, {1, 1, 2}, {0, 0, 2}, {0, 0, 3}, {1, 1, 3}, {0, 0, 5}};

    // [7,6,8]
    vector<int> nums = {7,6,8};
    // [[0,0,2],[0,1,5],[2,2,5],[0,2,4]]
    vector<vector<int>> querieries = {{0, 0, 2}, {0, 1, 5}, {2, 2, 5}, {0, 2, 4}};

    // [4,3,2,1]
    // vector<int> nums = {4,3,2,1};
    // [[0,2,1],[0,2,1],[1,1,3]]
    // vector<vector<int>> querieries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};

    // [2,0,2]
    // vector<int> nums = {2,0,2};
    // [[0,2,1],[0,2,1],[1,1,3]]
    // vector<vector<int>> querieries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};

    // [0]
    // vector<int> nums = {0};
    // [[0,0,2],[0,0,4],[0,0,4],[0,0,3],[0,0,5]]
    // vector<vector<int>> querieries = {{0, 0, 2}, {0, 0, 4}, {0, 0, 4}, {0, 0, 3}, {0, 0, 5}};
    std::cout << "min zero array: " << s.minZeroArray(nums, querieries) << "\n";
    return 0;
}