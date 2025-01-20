#include <comm.h>

class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        string prefix = "";

        for (int i = 0; i < strs[0].size(); i++)
        {
            bool flag = true;
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size())
                {
                    flag = false;
                    break;
                }
                else if (strs[0][i] != strs[j][i])
                {
                    flag = false;
                    break;
                }
            }

            if (!flag)
            {
                break;
            }
            else
            {
                prefix += strs[0][i];
            }
        }

        return prefix;
    }
};

int main()
{
    std::cout << Solution().longestCommonPrefix({"flower","flow","flight"}) << "\n";
    return 0;
}