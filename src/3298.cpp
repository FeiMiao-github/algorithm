#include "comm.h"

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        long long ret = 0;
        vector<int> v1(26), v2(26);

        std::for_each(word2.begin(), word2.end(), [&](char c) {
            v2[c - 'a'] += 1;
        });

        int l = 0, r = 0;
        size_t l1 = word1.size();

        while (l < l1)
        {
            while (true)
            {   
                if (contains(v1, v2))
                {
                    ret += l1 - r + 1;
                    break;
                }

                if (r < l1)
                {
                    v1[word1[r] - 'a'] += 1;
                    r++;
                }
                else
                {
                    break;
                }
            }

            v1[word1[l] - 'a'] -= 1;

            l++;
        }

        return ret;
    }

    bool contains(vector<int> &v1, vector<int> &v2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (v1[i] < v2[i])
            {
                return false;
            }
        }
        return true;
    }
};

void test(string word1, string word2, long long expect) {
    Solution s;
    long long res = s.validSubstringCount(word1, word2);
    if(res == expect)
    {
        cout << "[OK] res is " << res << "\n";
    }
    else
    {
        cout << "[FAILED] res is " << res << "\n";
    }
}

int main() {
    test("bcca", "abc", 1);
    test("abcabc", "abc", 10);
    test("abcabc", "aaabc", 0);
    return 0;
}