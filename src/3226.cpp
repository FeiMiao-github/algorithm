#include <comm.h>

class Solution {
public:
    int minChanges(int n, int k) {
        int tmp = (n ^ k);
        if (tmp & k)
        {
            return -1;
        }

        int ans = 0;
        tmp = tmp & n;
        while (tmp != 0)
        {
            if (tmp & 1)
            {
                ans += 1;
            }
            tmp >>= 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    std::cout << "s res is " << s.minChanges(13, 4) << "\n";
    return 0;
}