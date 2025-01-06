#include "comm.h"

class Solution {
public:
    int inner(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut, int h, int v) {
        int res = 0;
        if (m == 1 && n == 1)
        {
            return 0;
        }

        if (m == 1)
        {
            res += verticalCut[v];
            int min_cost = INT32_MAX;
            for (int i = 1; i <= n / 2; i++)
            {
                int tmp = inner(m, i, horizontalCut, verticalCut, h, v + 1) + inner(m, n - i, horizontalCut, verticalCut, h, v + 1);
                if (tmp < min_cost)
                {
                    {
                        std::cout << "m: " << m << " n: " << n << " h: " << h << " v: " << v << "\n";
                        std::cout << "i: " << i << " tmp: " << tmp << "\n";
                    }
                    min_cost = tmp;
                }
            }
            return res + min_cost;
        }

        if (n == 1)
        {
            res += horizontalCut[h];
            int min_cost = INT32_MAX;
            for (int i = 1; i <= m / 2; i++)
            {
                min_cost = min(min_cost, inner(i, n, horizontalCut, verticalCut, h + 1, v) + inner(m - i, n, horizontalCut, verticalCut, h + 1, v));
            }
            return res + min_cost;
        }

        int min_v_cost = INT32_MAX;
        int min_h_cost = INT32_MAX;
        for (int i = 1; i <= m / 2; i++)
        {
            min_h_cost = min(min_h_cost, inner(i, n, horizontalCut, verticalCut, h + 1, v) + inner(m - i, n, horizontalCut, verticalCut, h + 1, v));
        }
        for (int i = 1; i <= n / 2; i++)
        {
            min_v_cost = min(min_v_cost, inner(m, i, horizontalCut, verticalCut, h, v + 1) + inner(m, n - i, horizontalCut, verticalCut, h, v + 1));
        }
        return min(min_h_cost + horizontalCut[h], min_v_cost + verticalCut[v]);
    }

    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        return inner(m, n, horizontalCut, verticalCut, 0, 0);
    }
};

void test(int m, int n, const vector<int>& horizontalCut, const vector<int>& verticalCut, int expect) {
    int params1 = m;
    int params2 = n;
    vector<int> params3 = horizontalCut;
    vector<int> params4 = verticalCut;
    Solution s;
    int res = s.minimumCost(params1, params2, params3, params4);
    if(res == expect)
    {
        cout << "[OK] res is " << res << "\n";
    }
    else
    {
        cout << "[FAILED] res is " << res << "\n";
    }
}

int main() {
    // 输入：m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]
    // 输出：13
    test(3, 2, {1,3}, {5}, 13);

    // 输入：m = 2, n = 2, horizontalCut = [7], verticalCut = [4]
    // 输出：15
    test(2, 2, {7}, {4}, 15);

    // [2,3,2,3,1], [1, 2], m = 6, n = 3
    // 输出：28
    test(6, 3, {2,3,2,3,1}, {1, 2}, 28);

    // m = 1, n = 7, h: [], v: [2,1,2,1,2,1]
    // 输出：9
    test(1, 7, {}, {2,1,2,1,2,1}, 9);

    return 0;
}