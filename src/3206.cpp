#include <comm.h>

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        int sz = colors.size();
        for (int i = 0; i < sz; i++)
        {
            int next = (i + 1) % sz;
            int prev = (i - 1 + sz) % sz;
            if (colors[prev] != colors[i] && colors[i] != colors[next])
            {
                ans += 1;
            }
        }
        return ans;
    }
};

void TEST_F(const vector<int>& num, auto ans)
{
    vector<int> nums = num;
    Solution s;
    int res;
    res = s.numberOfAlternatingGroups(nums);
    assert(res == ans);
    std::cout << "res is " << res << "\n";
}

int main()
{
    TEST_F({0,1,0,0,1}, 3);
    return 0;
}