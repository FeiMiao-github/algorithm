#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> mp {{1, 1}, {2, 2}};

    int climbStairs(int n) {
        if (mp.find(n) != mp.end())
        {
            return mp[n];
        }
        int res = climbStairs(n - 1) + climbStairs(n - 2);
        mp[n] = res;
        return res;
    }
};

int main()
{
    std::cout << "climb stairs: " << Solution().climbStairs(35) << "\n";
    return 0;
}