#include <comm.h>
#include <vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int x = 0, y = c - 1;
        while (x < r && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                x++;
            } else if (matrix[x][y] > target) {
                y--;
            }
        }

        return false;
    }
};

void test(const vector<vector<int>> &matrix, int target, bool res) {
    auto param1 = matrix;
    auto param2 = target;
    auto r = Solution().searchMatrix(param1, param2);

    if (r == res) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]" << r << "\n";
    }
}

int main() {
    test({{1, 4, 7, 11, 15},
          {2, 5, 8, 12, 19},
          {3, 6, 9, 16, 22},
          {10, 13, 14, 17, 24},
          {18, 21, 23, 26, 30}},
         5, true);
    return 0;
}
