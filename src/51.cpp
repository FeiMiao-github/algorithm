#include "comm.h"

class Solution {
public:
    vector<string> gen(vector<int>& queue)
    {
        vector<string> ans;
        for (int i = 0; i < queue.size(); i++)
        {
            stringstream ss;
            for (int j = 0; j < queue.size(); j++)
            {
                if (j == queue[i])
                {
                    ss << 'Q';
                }
                else
                {
                    ss << '.';
                }
            }
            ans.push_back(ss.str());
            ss.clear();
        }
        return ans;
    }

    void backtrace(vector<vector<string>> &ans, vector<int>&queue, int n, int row, unordered_set<int>& col, unordered_set<int>& diag1, unordered_set<int> &diag2)
    {
        if (row == n)
        {
            ans.push_back(gen(queue));
        }
        else 
        {
            for (int i = 0; i < n; i++)
            {
                if (col.count(i))
                {
                    continue;
                }

                int dgv1 = row - i;
                if (diag1.count(dgv1))
                {
                    continue;
                }
            
                int dgv2 = row + i;
                if (diag2.count(dgv2))
                {
                    continue;
                }

                queue[row] = i;
                diag1.insert(dgv1);
                diag2.insert(dgv2);
                col.insert(i);
                backtrace(ans, queue, n, row + 1, col, diag1, diag2);
                queue[row] = -1;
                col.erase(i);
                diag1.erase(dgv1);
                diag2.erase(dgv2);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> queue(n, -1);
        unordered_set<int> col, diag1, diag2;
        int row = 0;
        backtrace(ans, queue, n, row, col, diag1, diag2);
        return ans;
    }
};

int main()
{
    std::cout << Solution().solveNQueens(4) << "\n";
    return 0;
}
