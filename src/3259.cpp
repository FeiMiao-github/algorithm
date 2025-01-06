#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxEnergyBoost(const vector<int>& energyDrinkA, const vector<int>& energyDrinkB) {
        vector<int> dpA(energyDrinkA.size() + 1, 0);
        vector<int> dpB(energyDrinkB.size() + 1, 0);
        dpA[0] = 0;
        dpB[0] = 0;
        dpA[1] = energyDrinkA[0];
        dpB[1] = energyDrinkB[0];
        for (size_t i = 1; i < energyDrinkA.size(); i++)
        {
            dpA[i + 1] = max(dpA[i], dpB[i - 1]) + energyDrinkA[i];
            dpB[i + 1] = max(dpB[i], dpA[i - 1]) + energyDrinkB[i];
        }
        return max(dpA[energyDrinkA.size()], dpB[energyDrinkB.size()]);
    }
};

int main()
{
    std::cout << Solution().maxEnergyBoost({1,2,3}, {1,2,3}) << "\n";
    return 0;
}