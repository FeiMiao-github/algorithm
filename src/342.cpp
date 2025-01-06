#include "comm.h"

class Solution {
public:
    bool isPowerOfFour(int n) {
        unordered_set<int> s { 0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000};
        return s.count(n) > 0;
    }
};

void test(int n, bool expect) {
    Solution s;
    bool res = s.isPowerOfFour(n);
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
    test(16, true);
    test(5, false);
    test(1, true);
    return 0;
}