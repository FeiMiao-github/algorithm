#include <comm.h>
#include <vector>

class Solution {
public:
    vector<vector<string>> res;
    vector<string> cur;
    vector<vector<int>> f;
    void partition(const string &s, size_t eidx) {
        if (eidx >= s.size()) {
            res.push_back(cur);
            return;
        }

        auto check = [this](const string &s, size_t l, size_t r) {
            if (f[l][r] != -1) {
                return f[l][r] == 1;
            }

            while (l < r) {
                if (s[l] != s[r]) {
                    return (f[l][r] = 0, false);
                }
                l++;
                r--;
            }
            return f[l][r] = 1, true;
        };

        for (size_t i = eidx; i < s.size(); i++) {
            if (check(s, eidx, i)) {
                cur.push_back(s.substr(eidx, i - eidx + 1));
                partition(s, i + 1);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        f.resize(s.size(), vector<int>(s.size(), -1));
        partition(s, 0);
        return res;
    }
};

void test(const string s, const vector<vector<string>> &exp) {
    auto res = Solution().partition(s);
    // ug_check(res, exp);
    std::cout << "res is " << res << "\n";
}

int main() {
    test("aab", {{"aa", "b"}, {"a", "a", "b"}});
    return 0;
}
