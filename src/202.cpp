#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int calc(int n)
    {
        int ret = 0;
        while (n > 0)
        {
            ret += std::pow(n % 10, 2);
            n /= 10;
        }
        return ret;
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);

        while (true)
        {
            int tmp = calc(n);
            if (tmp == 1)
            {
                return true;
            }
            else if (s.count(tmp) > 0)
            {
                return false;
            }

            std::cout << tmp << "\n";
            n = tmp;
            s.insert(tmp);
        }
    }
};

int main()
{
    Solution s;
    std::cout << "res is " << (s.isHappy(2) ? "true" : "false" )<< "\n";
    return 0;
}