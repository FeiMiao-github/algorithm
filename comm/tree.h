#include <memory>
#include <vector>
#include <tuple>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

[[nouse]]
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