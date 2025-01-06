#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc_coins(int amount, vector<int>& coins)
{
    if (amount < 0) return -1;

    const int default_value = amount + 1;
    std::vector<int> arr(amount + 1);
    std::for_each(arr.begin(), arr.end(), [default_value](int &p) {
        p = default_value;
    });

    arr[0] = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int coin: coins)
        {
            if (i - coin < 0) continue;
            arr[i] = min(arr[i], arr[i - coin] + 1);
        }
    }

    return arr[amount] == default_value ? -1 : arr[amount];
}

int main()
{
    vector<int> coins { 1, 3, 5};
    vector<int> amount { -1, 5, 33, 17, 22};
    vector<int> res { -1, 1, 7, 5, 6};

    for (auto i = 0; i < amount.size(); i++)
    {
        std::cout << "calc res is: " << calc_coins(amount[i], coins) << ", "
            << "should be " << res[i] << "\n";
    }
    return 0;
}