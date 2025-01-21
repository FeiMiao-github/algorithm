#include <comm.h>
#include <vector>

class Solution {
public:
    bool canFinish1(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> flag(numCourses, 1);
        int prereq_size = prerequisites.size();
        int remain_cnt = 0;

        for (int i = 0; i < prereq_size; i++) {
            const int target = prerequisites[i][0];
            if (flag[target] == 1) {
                remain_cnt++;
                flag[target] = 0;
            }
        }

        std::cout << flag << ", remain count: " << remain_cnt << "\n";

        int cnt = remain_cnt;
        do {
            for (int i = 0; i < prereq_size; i++) {
                const int target = prerequisites[i][0];
                const int prereq = prerequisites[i][1];

                if (target != -1 && flag[prereq] == 1 && flag[target] != 1) {
                    flag[target] = 1;
                    prerequisites[i][0] = -1;
                    cnt--;
                }
            }

            if (cnt == remain_cnt) {
                break;
            } else {
                remain_cnt = cnt;
            }
        } while (remain_cnt > 0);

        return remain_cnt == 0;
    }

    vector<int> visited;
    vector<vector<int>> edges;
    bool valid = true;

    void dfs(int v) {
        visited[v] = 1;
        for (size_t i = 0; i < edges[v].size(); i++) {
            auto tgt = edges[v][i];
            if (visited[tgt] == 0) {
                dfs(tgt);
                if (!valid) {
                    return;
                }
            } else if (visited[tgt] == 1) {
                valid = false;
                return;
            }
        }
        visited[v] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        visited.resize(numCourses);
        edges.resize(numCourses);

        for (size_t i = 0; i < prerequisites.size(); i++) {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        return valid;
    }
};

void test(int num, const vector<vector<int>> &prereq, bool expect) {
    auto param = prereq;
    auto res = Solution().canFinish(num, param);
    if (res == expect) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]" << res << "\n";
    }
}

int main() {
    test(2, {{1, 0}}, true);
    test(2, {{1, 0}, {0, 1}}, false);
    test(5, {{1, 4}, {2, 4}, {3, 1}, {3, 2}}, true);
    test(3, {{1, 0}, {1, 2}, {0, 1}}, false);
    return 0;
}
