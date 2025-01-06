#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr char Q_FLAG = 'Q';
constexpr char DEF_FLAG = '.';

vector<vector<string>> res;

bool is_valid(vector<string>& board, int row, int col, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == Q_FLAG)
        {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == Q_FLAG)
        {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == Q_FLAG)
        {
            return false;
        }
    }

    return true;
}

void backtrack(vector<string>& board, int row, int n)
{
    if (row == n)
    {
        res.emplace_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (!is_valid(board, row, col, n))
        {
            continue;
        }

        board[row][col] = Q_FLAG;
        backtrack(board, row + 1, n);
        board[row][col] = DEF_FLAG;
    }
}

vector<vector<string>> solve_queen(int n)
{
    vector<string> board(n, string(n, DEF_FLAG));
    backtrack(board, 0, n);
    return res;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec)
{
    os << "==================================================\n";
    for (auto &s: vec)
    {
        os << s << "\n";
    }
    return os << "==================================================\n";
}

int main()
{
    solve_queen(10);
    std::cout << "count: " << res.size() << "\n";
    // for (auto p = res.cbegin(); p != res.cend(); p++)
    // {
    //     std::cout << *p << "\n";
    // }
    return 0;
}