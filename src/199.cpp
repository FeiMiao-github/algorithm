#include <comm.h>
#include <tree.h>

class Solution {
public:
    void righftSideViewInner1(TreeNode *root, int level) {
        if (!root)
            return;

        if (cnt == level) {
            res[level] = root->val;
        }
        righftSideViewInner1(root->right, level + 1);
        righftSideViewInner1(root->left, level + 1);
    }
    vector<int> rightSideView1(TreeNode *root) {
        righftSideViewInner1(root, 0);
        return res;
    }

    int cnt = 0;
    vector<int> res;

    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> q;
        vector<int> res;
        int cnt = 1;
        while (root || !q.empty()) {
            if (root) {
                q.push(root);
                root = nullptr;
                cnt = 1;
            }

            int curcnt = cnt;
            cnt = 0;
            for (int i = 0; i < curcnt; i++) {
                auto tmp = q.front();
                if (i == curcnt - 1) {
                    res.push_back(tmp->val);
                }
                q.pop();

                if (tmp->left) {
                    cnt++;
                    q.push(tmp->left);
                }

                if (tmp->right) {
                    cnt++;
                    q.push(tmp->right);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
