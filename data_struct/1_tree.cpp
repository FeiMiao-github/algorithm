#include "tree.h"
#include "comm.h"

class Iter {
public:
    void iter(TreeNode* root)
    {
        std::stack<TreeNode*> st;
        TreeNode* last = nullptr, *tmp = root;
        while (tmp || !st.empty())
        {
            while (tmp)
            {
                st.push(tmp);
                tmp = tmp->left;
            }

            tmp = st.top();
            st.pop();

            if (tmp->right == nullptr || tmp->right == last)
            {
                std::cout << tmp->val << "\n";
                last = tmp;
                tmp = nullptr;
            }
            else if (tmp->right)
            {
                st.push(tmp);
                tmp = tmp->right;
            }
        }
    }
};

int main()
{
    vector<int> arr {1, 2, 3, 4, 5, 6, -1};
    auto tree = gen_tree(arr);
    Iter iter;
    iter.iter(&(*tree)[0]);
    return 0;
}