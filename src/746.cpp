#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int mincost(vector<int>& cost, int n, vector<int>& memo)
    {
        if (memo[n] >= 0)
        {
            return memo[n];
        }

        int res = std::min(mincost(cost, n - 1, memo), mincost(cost, n - 2, memo)) + cost[n];
        memo[n] = res;
        return res;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        memo[0] = cost[0];
        memo[1] = cost[1];
        return std::min(mincost(cost, n - 1, memo), mincost(cost, n - 2, memo));
    }
};

int main()
{
    Solution s;
    vector<int> cost = {0,0,0,0};
    std::cout << s.minCostClimbingStairs(cost) << "\n";
    return 0;
}