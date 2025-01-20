#include <comm.h>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = 0;
        int inf = INT32_MAX / 2;
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, inf));
        for (size_t i = 0; i < times.size(); i++)
        {
            graph[times[i][0]][times[i][1]] = times[i][2];
        }

        vector<int> dist(n + 1, inf);
        dist[k] = 0;
        vector<int> vis(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int x = -1;
            for (int j = 1; j <= n; j++)
            {
                if (vis[j] != 0)
                {
                    continue;
                }

                if (x == -1 || dist[j] < dist[x])
                {
                    x = j;
                }
            }

            vis[x] = 1;
            for (int j = 1; j <= n; j++)
            {
                dist[j] = min(dist[j], dist[x] + graph[x][j]);
            }
        }

        ans = *std::max_element(dist.begin() + 1, dist.end());
        ans = ans == inf ? -1 : ans;
        return ans;
    }
};

int main()
{
    // times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    // vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    Solution s;
    // std::cout << "res is " << s.networkDelayTime(times, 4, 2) << "\n";  

    // times = [[1,2,1]], n = 2, k = 2
    // vector<vector<int>> times = {{1,2,1}};
    // std::cout << "res is " << s.networkDelayTime(times, 2, 2) << "\n";

    // [[1,2,1],[2,3,2],[1,3,4]] 3 1
    vector<vector<int>> times = {{1,2,1},{2,3,2},{1,3,4}};
    std::cout << "res is " << s.networkDelayTime(times, 3, 1) << "\n";

    return 0;
}