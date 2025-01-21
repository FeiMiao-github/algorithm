#include <comm.h>
#include <cstddef>

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        vector<int> arr(128, 0);
        int charcnt = t.size();
        for (auto c : t) {
            arr[c] += 1;
        }

        size_t l = 0, r = 0;
        size_t res_start = 0, res_len = s.size() + 1;

        while (r < s.size()) {
            if (arr[s[r]]-- > 0) {
                charcnt--;
            }

            if (charcnt == 0) {
                while (charcnt == 0) {
                    if (res_len >= r - l + 1) {
                        res_start = l;
                        res_len = r - l + 1;
                    }
                    if (arr[s[l]] == 0) {
                        charcnt++;
                    }
                    arr[s[l]]++;
                    l++;
                }

                while (l < r && arr[s[l]] < 0) {
                    arr[s[l]]++;
                    l++;
                }
            }

            r++;
        }

        return res_len == s.size() + 1 ? "" : s.substr(res_start, res_len);
    }
};

void test(const string &s, const string &t, const string &expect) {
    auto res = Solution().minWindow(s, t);
    if (expect == res) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]" << res << "\n";
    }
}

int main() {
    test("ADOBECODEBANC", "ABC", "BANC");
    test("a", "b", "");
    test("ab", "b", "b");
    return 0;
}
