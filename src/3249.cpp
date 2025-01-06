#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution
{
public:
    int dfs(const vector<vector<int>> &graph, int parent, int node, vector<int> &dp, int& goodNodeCount)
    {
        if (dp[node] != -1)
        {
            return dp[node];
        }

        bool isGoodNode = true;
        int num = 0;
        int subTreeSize = 0;
        int treeSize = 0;
        for (size_t i = 0; i < graph[node].size(); i++)
        {
            if (graph[node][i] == parent) continue;
            int tmpSubTreeSize = dfs(graph, node, graph[node][i], dp, goodNodeCount);
            if (subTreeSize == 0)
            {
                subTreeSize = tmpSubTreeSize;
            }
            else if (subTreeSize != tmpSubTreeSize)
            {
                isGoodNode = false;
            }
            treeSize += tmpSubTreeSize;
        }
        goodNodeCount += isGoodNode ? 1 : 0;
        dp[node] = treeSize + 1;
        return dp[node];
    }

    int countGoodNodes(const vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(edges.size() + 1);
        for (size_t i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dp(edges.size() + 1, -1);
        int res = 0;
        dfs(graph, -1, 0, dp, res);
        return res;
    }
};

int main()
{
    Solution s;
    // int res = s.countGoodNodes({{0, 1}, {1, 2}, {1, 3}, {1, 4}, {0, 5}, {5, 6}, {6, 7}, {7, 8}, {0, 9}, {9, 10}, {9, 12}, {10, 11}});
    // [[6,0],[1,0],[5,1],[2,5],[3,1],[4,3]]
    // int res = s.countGoodNodes({{6, 0}, {1, 0}, {5, 1}, {2, 5}, {3, 1}, {4, 3}});
    // [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]
    int res = s.countGoodNodes({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 5}, {1, 6}, {2, 7}, {3, 8}});
    std::cout << "count good nodes: " << res << "\n";
    return 0;
}