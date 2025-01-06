#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPerfectSquare(int num) {
        double x0 = num, x1;
        while (true)
        {
            x1 = (x0 + num / x0) / 2;
            if (x0 - x1 < 10e-7)
            {
                break;
            }
            x0 = x1;
        }
        int x = (int)x0;
        std::cout << "x0 * x0: " << (x0 * x0) << ", x0 " << x0 << ", " << num << "\n";
        return (x * x) == num;
    }
};

int main()
{
    int c = __INT32_MAX__;
    Solution s;
    std::cout << "res is " << (s.isPerfectSquare(c) ? "true" : "false" )<< "\n";
    return 0;
}