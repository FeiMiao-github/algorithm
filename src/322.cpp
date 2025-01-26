#include <comm.h>
#include <cstdint>
#include <iostream>

class Solution {
public:
    int dfs(vector<int> &coins, int amount, int coin_index) {
        if (coin_index < 0) {
            return amount == 0 ? 0 : INT32_MAX / 2;
        }
        if (amount < coins[coin_index]) {
            return dfs(coins, amount, coin_index - 1);
        }

        return min(dfs(coins, amount, coin_index - 1),
                   dfs(coins, amount - coins[coin_index], coin_index) + 1);
    }

    int coinChange1(vector<int> &coins, int amount) {
        int ans = dfs(coins, amount, coins.size() - 1);
        return ans > amount ? -1 : ans;
    }

    int coinChange2(vector<int> &coins, int amount) {
        vector<int> f(amount + 1, 0);
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            int minn = INT32_MAX / 2;
            for (size_t j = 0; j < coins.size() && i >= coins[j]; j++) {
                minn = min(f[i - coins[j]], minn);
            }
            f[i] = minn + 1;
        }
        return f[amount] > amount ? -1 : f[amount];
    }

    int coinChange(vector<int> &coins, int amount) {
        vector<int> f(amount + 1, INT32_MAX / 2);
        f[0] = 0;
        for (auto c : coins) {
            for (int i = c; i <= amount; i++) {
                f[i] = min(f[i], f[i - c] + 1);
            }
        }
        return f[amount] > amount ? -1 : f[amount];
    }
};

void test(const vector<int> &coins, int amount, int expect) {
    auto param = coins;
    auto res = Solution().coinChange(param, amount);
    if (res == expect) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]" << res << "\n";
    }
}

int main() {
    test({1, 2, 5}, 11, 3);
    test({2}, 3, -1);
    test({411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422}, 9864,
         24);
    test({474, 83, 404, 3}, 12, 4);
    test({474, 83, 404, 3}, 264, 8);
    return 0;
}
