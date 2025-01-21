#include <comm.h>
#include <iostream>

class Solution {
public:
    vector<int> findAnagrams1(string s, string p) {
        vector<int> res;
        vector<int> scnt = vector<int>(26);
        vector<int> pcnt = vector<int>(26);

        if (p.size() > s.size()) {
            return res;
        }

        for (size_t i = 0; i < p.size(); i++) {
            scnt[s[i] - 'a'] += 1;
            pcnt[p[i] - 'a'] += 1;
        }
        scnt[s[p.size() - 1] - 'a'] -= 1;

        for (size_t l = 0, r = p.size() - 1; r < s.size(); l++, r++) {
            scnt[s[r] - 'a'] += 1;
            if (pcnt == scnt) {
                res.push_back(l);
            }
            scnt[s[l] - 'a'] -= 1;
        }
        return res;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> cnt(26);
        int diffcnt = 0;

        for (size_t i = 0; i < p.size(); i++) {
            cnt[p[i] - 'a'] -= 1;
        }

        for (auto v : cnt) {
            diffcnt += (v ? 1 : 0);
        }

        for (size_t i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] == 0)
                diffcnt--;

            if (i >= p.size()) {
                if (cnt[s[i - p.size()] - 'a'] == 0) {
                    diffcnt += 1;
                }
                cnt[s[i - p.size()] - 'a'] -= 1;
            }

            if (diffcnt == 0) {
                res.push_back(i - p.size() + 1);
            }
        }
        return res;
    }

    void print(const vector<int> &arr) {
        for (int i = 0; i < 26; i++) {
            std::cout << (char)('a' + i) << ":" << arr[i] << " ";
        }
    }
};

void test(const string &s, const string &p, const vector<int> &expect) {
    string param1 = s;
    string param2 = p;
    vector<int> res = Solution().findAnagrams(param1, param2);
    if (expect == res) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED] " << res << "\n";
    }
}

int main() {
    test("cbaebabacd", "abc", {0, 6});
    test("aa", "bb", {});
    return 0;
}
