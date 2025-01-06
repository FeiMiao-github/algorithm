#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isSp(int v)
    {
        if (v == 1) { return false; }

        int tmp = sqrt(v);
        if (tmp * tmp != v)
        {
            return false;
        }

        int k = 2;
        while (k * k <= tmp)
        {
            if (tmp % k == 0)
            {
                return false;
            }
            k++;
        }

       return true;
    }

    int nonSpecialCount(int l, int r) {
        int cnt = 0;
        for (int i = l; i <= r; i++)
        {
            if (!isSp(i))
            {
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    std::cout << "res is " << s.nonSpecialCount(4, 16) << "\n";
    return 0;
}