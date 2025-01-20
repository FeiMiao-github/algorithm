#include <comm.h>

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        for (auto p = s.cbegin(); p != s.cend(); p++)
        {
            if (p + 1 != s.cend())
            {
                if (*p == 'I')
                {
                    if (*(p + 1) == 'V')
                    {
                        res += 4;
                        p++;
                    }
                    else if (*(p + 1) == 'X')
                    {
                        res += 9;
                        p++;
                    }
                    else
                    {
                        res += 1;
                    }
                }
                else if (*p == 'X')
                {
                    if (*(p + 1) == 'L')
                    {
                        res += 40;
                        p++;
                    }
                    else if (*(p + 1) == 'C')
                    {
                        res += 90;
                        p++;
                    }
                    else
                    {
                        res += 10;
                    }
                }
                else if (*p == 'C')
                {
                    if (*(p + 1) == 'D')
                    {
                        res += 400;
                        p++;
                    }
                    else if (*(p + 1) == 'M')
                    {
                        res += 900;
                        p++;
                    }
                    else
                    {
                        res += 100;
                    }
                }
                else
                {
                    res += mp[*p];
                }
            }
            else
            {
                res += mp[*p];
            }
        }
        return res;
    }
};

void test(string str, int expect) {
    Solution s;
    int res = s.romanToInt(str);
    if(res == expect)
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
    // 输入: s = "III"
    // 输出: 3
    test("III", 3);

    // 输入: s = "IV"
    // 输出: 4
    test("IV", 4);

    // 输入: s = "IX"
    // 输出: 9
    test("IX", 9);

    // 输入: s = "LVIII"
    // 输出: 58
    test("LVIII", 58);

    // 输入: s = "MCMXCIV"
    // 输出: 1994
    test("MCMXCIV", 1994);

    return 0;
}