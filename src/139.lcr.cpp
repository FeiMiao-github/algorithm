#include <comm.h>

class Solution {
public:
    vector<int> trainingPlan(vector<int> &actions) {
        int l = 0, r = actions.size() - 1;
        while (l < r) {
            if (actions[l] % 2 == 1) {
                l++;
            } else if (actions[r] % 2 == 0) {
                r--;
            } else {
                swap(actions[l], actions[r]);
                l++;
                r--;
            }
        }
        return actions;
    }
};

int main() {
    vector<int> actions = {1, 2, 3, 4, 5};
    Solution().trainingPlan(actions);
    std::cout << "actions: " << actions << "\n";
    return 0;
}
