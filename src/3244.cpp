#include <vector>
#include <iostream>

using namespace std;

// std::cout vector
std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec)
{
    os << "{";
    for (auto p = vec.cbegin(); p != vec.cend(); p++)
    {
        os << *p << ", ";
    }
    os << "}";
    return os;
}

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        vector<int> flag(n);
        for (size_t i = 0; i < n; i++) {
            flag[i] = i + 1;
        }
        int cnt = n - 1;
        for (size_t i = 0; i < queries.size(); i++) {
            int st = queries[i][0]; // 2
            int ed = queries[i][1]; // 4
            int k = flag[st];
            flag[st] = ed;
            while (k != -1 && k < ed)
            {
                int t = flag[k];
                flag[k] = -1;
                k = t;
                cnt --;
            }

            ans[i] = cnt;
        }
        return ans;
    }
};

int main()
{
    // n = 5, queries = [[2,4],[0,2],[0,4]]
    int n = 5;
    vector<vector<int>> queries {{2,4},{0,2},{0,4}};

    Solution s;
    std::cout << "res is " << s.shortestDistanceAfterQueries(n, queries) << "\n";

    return 0;
}