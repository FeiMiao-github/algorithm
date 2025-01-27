#include <comm.h>

class Solution {
public:
    bool search(vector<vector<char>> &board, string word,
                std::pair<int, int> baxis, int widx) {
        if (widx >= word.size())
            return true;

        int m = board.size();
        int n = board[0].size();
        bool ret = false;

        auto tmp = board[baxis.first][baxis.second];
        board[baxis.first][baxis.second] = '0';

        if (baxis.first + 1 < m &&
            board[baxis.first + 1][baxis.second] == word[widx]) {
            std::cout << "D[" << widx << "]\n";
            ret |=
                search(board, word, {baxis.first + 1, baxis.second}, widx + 1);
        }

        if (baxis.first - 1 >= 0 &&
            board[baxis.first - 1][baxis.second] == word[widx]) {
            std::cout << "U[" << widx << "]\n";
            ret |=
                search(board, word, {baxis.first - 1, baxis.second}, widx + 1);
        }
        if (baxis.second - 1 >= 0 &&
            board[baxis.first][baxis.second - 1] == word[widx]) {
            std::cout << "L[" << widx << "]\n";
            ret |=
                search(board, word, {baxis.first, baxis.second - 1}, widx + 1);
        }

        if (baxis.second + 1 < n) {
            std::cout << "==== " << board[baxis.first][baxis.second + 1]
                      << ", ====" << word[widx] << "\n";
        }

        if (baxis.second + 1 < n &&
            board[baxis.first][baxis.second + 1] == word[widx]) {
            std::cout << "R[" << widx << "]\n";
            ret |=
                search(board, word, {baxis.first, baxis.second + 1}, widx + 1);
        }

        board[baxis.first][baxis.second] = tmp;

        return ret;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    std::cout << "i: " << i << ", j: " << j
                              << ", word0: " << word[0] << "\n";
                    if (search(board, word, {i, j}, 1))
                        return true;
                }
            }
        }

        return false;
    }
};

void test(const vector<vector<char>> &board, string word, bool exp) {
    auto param = board;
    auto res = Solution().exist(param, word);
    ug_check(res, exp);
}

int main() {
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
         "ABCCED", true);
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
         "SEE", true);
    test({{'a', 'a'}}, "aa", true);
    return 0;
};
