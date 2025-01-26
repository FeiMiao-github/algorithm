#include <comm.h>
#include <vector>

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> arr('z' - 'a' + 1, vector<int>());
        vector<int> res;

        for (size_t i = 0; i < s.size(); i++) {
            arr[s[i] - 'a'].push_back(i);
        }

        size_t i = 0;
        while (i < s.size()) {
            vector<int> flag('z' - 'a' + 1, 0);
            int last_id = *arr[s[i] - 'a'].rbegin();
            flag[s[i] - 'a'] = 1;
            for (int i = 0; i < last_id; i++) {
                if (flag[s[i] - 'a'] != 1) {
                    last_id = max(last_id, *arr[s[i] - 'a'].rbegin());
                }
            }

            res.push_back(last_id - i + 1);
            i = last_id + 1;
        }
        return res;
    }
};

void test(const string &s, const vector<int> &expect) {
    auto param1 = s;
    auto res = Solution().partitionLabels(s);
    if (res == expect) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]" << res << "\n";
    }
}

int main() {
    test("ababcbacadefegdehijhklij", {9, 7, 8});
    return 0;
}
