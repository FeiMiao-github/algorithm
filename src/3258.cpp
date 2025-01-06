#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int cnt_0 = 0;
            int cnt_1 = 0;
            for (int j = i; j < s.size(); j++)                                                                           
            {
                if (s[j] == '1')
                {
                    cnt_1 += 1;
                }
                else if (s[j] == '0')
                {
                    cnt_0 += 1;
                }

                if (cnt_0 > k && cnt_1 > k)
                {
                    break;
                }
                else
                {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << "res count is " << s.countKConstraintSubstrings("10101", 1) << "\n";
    return 0;
}
