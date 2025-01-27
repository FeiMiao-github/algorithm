#include <comm.h>
#include <cstddef>
#include <string>
#include <vector>

class Solution {
public:
    bool wordBreak0(string s, vector<string> &wordDict) {
        unordered_set<string> wordmp(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1);
        dp[0] = true;
        for (size_t i = 1; i <= s.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (dp[j] && wordmp.contains(s.substr(j, i - j))) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        vector<int> cache(s.size(), -1);
        unordered_set<string> word_st(wordDict.begin(), wordDict.end());
        function<bool(size_t)> dfs = [&](size_t n) {
            if (n >= s.size())
                return true;
            if (cache[n] != -1) {
                return cache[n] == 1;
            }
            for (size_t i = n; i < s.size(); i++) {
                if (word_st.contains(s.substr(n, i - n + 1)) && dfs(i + 1)) {
                    cache[n] = 1;
                    return true;
                }
            }
            cache[n] = 0;
            return false;
        };
        return dfs(0);
    }
};

void test(string s, const vector<string> &wordDict, bool exp) {
    auto param = wordDict;
    auto res = Solution().wordBreak(s, param);
    ug_check(res, exp);
}

int main() {
    test("leetcode", {"leet", "code"}, true);
    test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaab",
         {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa",
          "aaaaaaaaa", "aaaaaaaaaa"},
         false);
    return 0;
}
