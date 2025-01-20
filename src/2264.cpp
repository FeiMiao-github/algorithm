#include <comm.h>

class Solution {
public:
    string largestGoodInteger(string num) {
        char ch = '0' - 1;
        for (auto p = num.begin(); p + 2 != num.end(); p++)
        {
            if (*p == *(p + 1) && *(p + 1) == *(p + 2))
            {
                if (*p > ch) ch = *p;
            }
        }

        if (ch == '0' - 1) return "";

        return string(3, ch);
    }
};

int main()
{
    Solution s;
    std::cout << s.largestGoodInteger("6777133339") << "\n";
    return 0;
}