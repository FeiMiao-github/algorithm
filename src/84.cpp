#include <comm.h>
#include <vector>

class Solution {
public:
    int largestRectangleArea0(vector<int> &heights) {
        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            int h_min = heights[i];
            for (int j = i; j < heights.size(); j++) {
                h_min = min(h_min, heights[j]);
                area = max(area, h_min * (j - i + 1));
            }
        }
        return area;
    }

    int largestRectangleArea1(vector<int> &heights) {
        stack<int> stk;
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        int area = 0;
        for (int i = 0; i < n; i++) {
            area = max((right[i] - left[i] - 1) * heights[i], area);
        }
        return area;
    }

    int largestRectangleArea(vector<int> &heights) {
        int area = 0;
        int n = heights.size();
        stack<int> stk;
        vector<int> left(n), right(n, n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        for (int i = 0; i < n; i++) {
            area = max((right[i] - left[i] - 1) * heights[i], area);
        }
        return area;
    }
};

void test(const vector<int> &heights, int exp) {
    auto param = heights;
    auto res = Solution().largestRectangleArea(param);
    ug_check(res, exp);
}

int main() {
    test({2, 1, 5, 6, 2, 3}, 10);
    test({2, 4}, 4);
    test({1, 1}, 2);
    return 0;
}
