#include <comm.h>

class Solution {
public:
    vector<int> dailyTemperatures1(vector<int> &temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<size_t> st;
        for (size_t i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if (!st.empty()) {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};

void test(const vector<int> &temp, const vector<int> &exp) {
    auto param = temp;
    auto res = Solution().dailyTemperatures(param);
    ug_check(res, exp);
}

int main() {
    test({73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0});
    return 0;
}
