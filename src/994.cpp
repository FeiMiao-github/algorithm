#include <comm.h>

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt1 = 0;
        int cnt2 = 0;
        queue<tuple<int, int>> q;
        int ret = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    cnt1++;
                } else if (grid[i][j] == 2) {
                    cnt2++;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int new_cnt = 0;

            for (int i = 0; i < cnt2; i++) {
                auto [x, y] = q.front();
                q.pop();

                if (x + 1 < r && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                    new_cnt++;
                }

                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                    new_cnt++;
                }

                if (y + 1 < c && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                    new_cnt++;
                }

                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                    new_cnt++;
                }
            }
            cnt1 -= new_cnt;
            cnt2 = new_cnt;
            if (new_cnt == 0)
                break;
            ret++;
        }

        return cnt1 == 0 ? ret : -1;
    }
};

void test(const vector<vector<int>> &grid, int expect) {
    auto param = grid;
    auto res = Solution().orangesRotting(param);
    if (res == expect) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]" << res << "\n";
    }
}

int main() {
    test({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4);
    return 0;
}
