#include <iostream>
#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        int tmp = std::sqrt(c);

        int a = 0, b = tmp;
        int count = 0;
        while (a <= b)
        {
            count ++;
            int a_2 = a * a;
            int b_2 = b * b;
            if (a_2 == c - b_2)
            {
                std::cout << "count is " << count << "\n";
                return true;
            }
            else if (a_2 > c - b_2)
                b--;

            else
                a++;
        }
        
        std::cout << "count is " << count << "\n";
        return false;
    }

    
    // bool judgeSquareSum(int c) {
    //     long long tmp = c;
    //     int count = 0;
    //     for (long long i = 0; i * i <= tmp; i++)
    //     {
    //         int b = std::sqrt(c - i * i);
    //         count ++ ;
    //         if (b * b == c - i * i)
    //         {
    //             std::cout << "count is " << count << "\n";
    //             return true;
    //         }
    //     }

    //     std::cout << "count is " << count << "\n";
    //     return false;
    // }
};

int main()
{
    int c = __INT32_MAX__;
    Solution s;
    std::cout << "res is " << (s.judgeSquareSum(c) ? "true" : "false" )<< "\n";
    return 0;
}