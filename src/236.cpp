#include "comm.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void get_path(TreeNode*root, TreeNode* p, std::deque<TreeNode*>& dq)
    {
        while (root)
        {
            dq.push_back(root);
            root = root->left;
        }

        TreeNode* last = nullptr;
        while (!dq.empty())
        {
            root = dq.back();
            if (root->right == nullptr || root->right == last)
            {
                if (root == p) {
                    return;
                }
                else {
                    last = root;
                    dq.pop_back();
                }
            } else if (root->right) {
                dq.push_back(root->right);
                while (root->left)
                {
                    dq.push_back(root->left);
                    root = root->left;
                }
            }
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::deque<TreeNode*> st1, st2;
        TreeNode* ret;
        get_path(root, p, st1);
        get_path(root, q, st2);
        while (!st1.empty() && !st2.empty() && st1.front() == st2.front())
        {
            ret = st1.front();
            st1.pop_front();
            st2.pop_front();
        }
        return ret;
    }
};


int main()
{
    Solution s;
    return 0;
}
