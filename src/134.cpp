#include "comm.h"

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        size_t station_size = gas.size();
        int remain_gas = 0;
        int min_remain = INT32_MAX;
        int ret = -1;

        for (size_t station_id = 0; station_id < station_size; station_id++)
        {
            remain_gas += gas[station_id];
            remain_gas -= cost[station_id];

            if (remain_gas < min_remain)
            {
                min_remain = remain_gas;
                ret = station_id;
            }
        }

        if (remain_gas < 0)
            return -1;

        return (ret + 1) % station_size;
    }
};

int main()
{
    Solution s;
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    std::cout << s.canCompleteCircuit(gas, cost) << "\n";
    return 0;
}
