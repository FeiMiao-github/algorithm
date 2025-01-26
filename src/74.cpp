#include <comm.h>

class Solution {
public:
    tuple<int, int> to_axis(int v, int w) {
        return std::make_tuple(v / w, v % w);
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int l = 0, r = matrix[0].size() * matrix.size() - 1;
        int w = matrix[0].size();
        while (l <= r) {
            int mid = (l + r) >> 1;
            auto [x, y] = to_axis(mid, w);
            if (target == matrix[x][y]) {
                return true;
            } else if (target > matrix[x][y]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};

int main() { return 0; }
