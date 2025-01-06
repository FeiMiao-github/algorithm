#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec)
{
    out << "{";
    for (auto p = vec.cbegin(); p != vec.cend(); p++)
    {
        out << *p << ", ";
    }
    out << "}";
    return out;
}

class Solution {
public:
    int countValidSelections(const vector<int>& nums) {
        int ret = 0;
        for (int curr = 0; curr < nums.size(); curr++)
        {
            if (nums[curr] != 0)
            {
                continue;
            }

            for (int dir = 0; dir <= 1; dir++)
            {
                vector<int> tmp = nums;
                int i = curr;
                int d = dir;
                while (i >= 0 && i < nums.size())
                {
                    if (tmp[i] > 0)
                    {
                        tmp[i]--;
                        d = d == 0 ? 1 : 0;
                    }
                    d == 0 ? ++i : --i;
                }

                bool all_zero = true;
                for (size_t j = 0; j < tmp.size(); j++)
                {
                    if (tmp[j] != 0)
                    {
                        all_zero = false;
                    }
                }

                if (all_zero)
                {
                    ret++;
                }
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    std::cout << "count valid selections: " << s.countValidSelections({1,0,2,0,3}) << "\n";
    return 0;
}