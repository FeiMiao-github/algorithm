#include <comm.h>
#include <vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int l = 0, r = matrix[0].size(), u = 0, d = matrix.size();
        int dir = 0;
        size_t total = r * d;
        while (res.size() < total) {
            if (dir == 0) {
                for (int i = l; i < r; i++) {
                    res.push_back(matrix[u][i]);
                }
                u++;
                dir = 1;
            } else if (dir == 1) {
                for (int i = u; i < d; i++) {
                    res.push_back(matrix[i][r - 1]);
                }
                r--;
                dir = 2;
            } else if (dir == 2) {
                for (int i = r - 1; i >= l; i--) {
                    res.push_back(matrix[d - 1][i]);
                }
                d--;
                dir = 3;
            } else if (dir == 3) {
                for (int i = d - 1; i >= u; i--) {
                    res.push_back(matrix[i][l]);
                }
                l++;
                dir = 0;
            }
        }
        return res;
    }
};

void test(const vector<vector<int>> &matrix, const vector<int> &expect) {
    vector<vector<int>> param1 = matrix;
    vector<int> res = Solution().spiralOrder(param1);
    if (res == expect) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]: " << res << "\n";
    }
}

int main() {
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 6, 9, 8, 7, 4, 5});
    return 0;
}
