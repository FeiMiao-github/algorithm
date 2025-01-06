#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// std::cout vector<int>
std::ostream& operator<<(std::ostream& os, const vector<int>& arr)
{
    os << "{";
    for (auto &v: arr)
    {
        os << v << ",";
    }
    return os << "}";
}

class Solution {
public:
    unordered_map<int, bool> memo;

    bool dfs(int maxChoosableInteger, int curTotal, int desiredTotal, int usenumbers)
    {
        bool res = false;
        if (memo.find(usenumbers) == memo.end())
        {
            for (int i = 1; i <= maxChoosableInteger; i++)
            {
                if (((usenumbers >> i) & 1) == 0)
                {
                    if (i + curTotal >= desiredTotal)
                    {
                        res = true;
                        break;
                    }
                    else if (!dfs(maxChoosableInteger, curTotal + i, desiredTotal, usenumbers | (1 << i)))
                    {
                        res = true;
                        break;
                    }
                }
            }
            memo[usenumbers] = res;
        }
        else
        {
            res = memo[usenumbers];
        }

        return res;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        return (maxChoosableInteger * (maxChoosableInteger + 1) / 2 >= desiredTotal)  && dfs(maxChoosableInteger, 0, desiredTotal, 0);
    }
};

int main()
{
    Solution s;
    // std::cout << "can i win: " << s.canIWin(10, 0) << "\n";
    std::cout << "can i win: " << s.canIWin(5, 50) << "\n";
    return 0;
}