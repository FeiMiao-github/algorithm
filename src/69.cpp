#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        double x0 = x, x1;
        while (true)
        {
            x1 = (x0 + x / x0) / 2;
            if (x0 - x1 < 10e-7)
            {
                break;
            }
            x0 = x1;
        }

        int tmp = (int)x0;
        if (tmp * tmp <= x)
        {
            return tmp;
        }
        else
        {
            return tmp - 1;
        }
    }
};

int main()
{
    Solution s;
    std::cout << "res is " << s.mySqrt(4) << std::endl;
    return 0;
}