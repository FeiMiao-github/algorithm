#include <comm.h>

class Solution {
public:
    string cur;

    void gen(vector<string> &res, int l, int r) {
        if (l == 0 && r == 0) {
            res.push_back(cur);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        gen(res, n, 0);
        return res;
    }
};

int main() { return 0; }
