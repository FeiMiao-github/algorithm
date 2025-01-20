#include <memory>
#include <utility>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    virtual ~TreeNode() { delete left; delete right; }

    static std::shared_ptr<std::vector<TreeNode>> gen_tree(std::vector<int> nums) {
        using ret_type = std::shared_ptr<std::vector<TreeNode>>;
        ret_type ret = std::make_shared<std::vector<TreeNode>>(nums.size());


        for (int i = 0; i < ret->size(); i++)
        {
            if (nums[i] != -1)
            {
                (*ret)[i].val = nums[i];
            }

            if (2 * i + 1 < nums.size())
            {
                if (nums[2 * i + 1] != -1)
                {
                    (*ret)[i].left = &(*ret)[2 * i + 1];
                }
                else
                {
                    (*ret)[i].left = nullptr;
                }
            }

            if (2 * i + 2 < nums.size())
            {
                if (nums[2 * i + 2] != -1)
                {
                    (*ret)[i].right = &(*ret)[2 * i + 2];
                }
                else
                {
                    (*ret)[i].right = nullptr;
                }
            }
        }

        return ret;
    }

    template <typename Func, typename ...Args>
    static void to_vec_preorder_inner(TreeNode* node, Func&& func, Args&&...args)
    {
        if (!node) {return;}
        
        std::forward<Func>(func)(node, std::forward<Args>(args)...);
        to_vec_preorder_inner(node->left, func);
        to_vec_preorder_inner(node->right, func);
    }

    template <typename Func, typename ...Args>
    static void to_vec_preorder(TreeNode* root, Func&& func, Args&& ...args)
    {
        to_vec_preorder_inner(root, std::forward<Func>(func), std::forward<Args>(args)...);
    }

    template <typename Func, typename ...Args>
    static void to_vec_level(TreeNode* root, Func&& func, Args&&... args)
    {
        std::queue<TreeNode*> q;
        int cnt = 1;

        while (root || !q.empty())
        {
            if (root) { q.push(root); root = nullptr; cnt = 1; }

            bool all_null = true;

            std::vector<TreeNode*> param(cnt);

            for (int i = 0; i < cnt; i++)
            {
                auto tmp = q.front();
                q.pop();

                param[i] = tmp;

                if (tmp && tmp->left)
                {
                    all_null = false;
                    q.push(tmp->left);
                }
                else
                {
                    q.push(nullptr);
                }

                if (tmp && tmp->right)
                {
                    all_null = false;
                    q.push(tmp->right);
                }
                else
                {
                    q.push(nullptr);
                }

            }

            cnt <<= 1;
            std::forward<Func>(func)(param, std::forward<Args>(args)...);
            
            if (all_null) break;
        }
    }
};