#include <comm.h>
#include <cstdint>

class Solution {
public:
    int dfs(int e, int target) {
        std::cout << "e: " << e << ", target: " << target << "\n";
        if (cache[e][target] != 0) {
            return cache[e][target];
        }

        if (e == 1) {
            cache[e][target] = target;
            return target;
        }

        auto e2 = e * e;
        if (target >= e2) {
            int ret = min(dfs(e, target - e2) + 1, dfs(e - 1, target));
            cache[e][target] = ret;
            return ret;
        } else {
            int ret = dfs(e - 1, target);
            cache[e][target] = ret;
            return ret;
        }
    }

    vector<vector<int>> cache;
    int numSquares1(int n) {
        int v = sqrt(n);
        cache = vector<vector<int>>(v + 1, vector<int>(n + 1));
        return dfs(v, n);
    }

    int numSquares(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int minn = INT32_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};
void test(int n, int expect) {
    auto res = Solution().numSquares(n);
    if (res == expect) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]" << res << "\n";
    }
}
int main() {
    test(12, 3);
    test(13, 2);
    test(7168, 4);
    return 0;
}
