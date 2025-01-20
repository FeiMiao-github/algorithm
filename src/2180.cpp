#include <comm.h>

class Solution {
public:
    int countEven(int num) {
        int ct = 0;
        for (int i = 1; i <= num; i++)
        {
            int res = 0;
            int v = i;
            while (v > 0)
            {
                res += (v % 10);
                v /= 10;
            }
            if (res % 2 == 0) ct++;
        }
        return ct;
    }
};

int main()
{
    Solution s;
    std::cout << s.countEven(4) << "\n";
    return 0;
}