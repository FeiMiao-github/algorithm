#include <comm.h>


/**
 * sliding window maximum
 */
class Solution {
public:
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        priority_queue<std::pair<int, int>> pq;
        vector<int> ret;
        int i = 0;
        for (; i < k - 1; i++)
        {
            pq.emplace(nums[i], i);
        }

        for (; i < nums.size(); i++)
        {
            pq.emplace(nums[i], i);
            while (pq.top().second <= i - k)
            {
                pq.pop();
            }
            ret.push_back(pq.top().first);
        }

        return ret;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<std::pair<int, int>> dq;
        vector<int> ret;
        int i = 0;
        for (; i < k - 1; i++)
        {
            while (!dq.empty() && dq.back().first < nums[i])
            {
                dq.pop_back();
            }
            dq.emplace_back(nums[i], i);
        }

        for (; i < nums.size(); i++)
        {
            while (!dq.empty() && dq.back().first < nums[i])
            {
                dq.pop_back();
            }
            dq.emplace_back(nums[i], i);
            while (dq.front().second <= i - k)
            {
                dq.pop_front();
            }
            ret.push_back(dq.front().first);
        }

        return ret;
    }
};

void test(const vector<int>& nums, int k, const vector<int>& expect) {
    Solution s;
    vector<int> param1 = nums;
    vector<int> res = s.maxSlidingWindow(param1, k);
    if (res == expect)
    {
        cout << "[OK] res is " << res << "\n";
    }
    else
    {
        cout << "[FAILED] res is " << res << "\n";
    }
}

int main()
{
    // test({1,3,-1,-3,5,3,6,7}, 3, {3,3,5,5,6,7});

    // vector<int> nums(19999);
    // vector<int> expect(9999 -1000 + 1);
    // std::iota(nums.begin(), nums.end(), 1);
    // std::iota(expect.begin(), expect.end(), 1000);
    // test(nums, 1000, expect);

    // test({1, -1}, 1, {1, -1});
    test({7, 2, 4}, 2, {7, 4});
    return 0;
}