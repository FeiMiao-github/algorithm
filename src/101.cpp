#include <comm.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty())
        {
            auto u = q.front(); q.pop();
            auto v = q.front(); q.pop();

            if (u->val != v->val) return false;

            if (u->left && v->right)
            {
                q.push(u->left);
                q.push(v->right);
            }
            else if (!u->left ^ !v->right) return false;

            if (u->right && v->left)
            {
                q.push(u->right);
                q.push(v->left);
            }
            else if (!u->right ^ !v->left) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    return 0;
}