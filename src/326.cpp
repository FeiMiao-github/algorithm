#include <comm.h>

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (1162261467 % n == 0);
    }
};

void test(int n, bool expect) {
    Solution s;
    bool res = s.isPowerOfThree(n);
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
    test(27, true);
    test(9, true);
    test(45, false);
    test(0, false);
    return 0;
}