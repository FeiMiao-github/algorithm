#include <cctype>
#include <comm.h>
#include <cstddef>
#include <string>

class Solution {
public:
    string decodeString0(string s) {
        int num = 0;
        stack<int> stk_n;
        stack<string> stk_str;
        stk_str.push("");
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                stk_n.push(num);
                stk_str.push("");
                num = 0;
            } else if (s[i] == ']') {
                int cnt = stk_n.top();
                stk_n.pop();
                string tmp = stk_str.top();
                stk_str.pop();
                for (int i = 0; i < cnt; i++) {
                    stk_str.top() += tmp;
                }
            } else {
                stk_str.top() += s[i];
            }
        }
        return stk_str.top();
    }

    string recursive(string s, size_t &i) {
        string res;
        int num = 0;
        while (i < s.size()) {
            if (s[i] == '[') {
                i += 1;
                string tmp = recursive(s, i);
                for (int i = 0; i < num; i++) {
                    res += tmp;
                }
                num = 0;
            } else if (s[i] == ']') {
                i += 1;
                break;
            } else if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                ++i;
            } else {
                res += s[i];
                ++i;
            }
        }
        return res;
    }

    string decodeString(string s) {
        string res;
        int num = 0;
        size_t i = 0;
        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            } else if (s[i] == '[') {
                i += 1;
                string tmp = recursive(s, i);
                for (int i = 0; i < num; i++) {
                    res += tmp;
                }
                num = 0;
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};

void test(const string &s, const string &exp) {
    auto param = s;
    auto res = Solution().decodeString(param);
    ug_check(res, exp);
}
int main() {
    test("3[a]2[bc]", "aaabcbc");
    test("3[a2[c]]", "accaccacc");
    test("2[abc]3[cd]ef", "abcabccdcdcdef");
    test("3[a3[b]3[c]d]", "abbbcccdabbbcccdabbbcccd");
    return 0;
}
