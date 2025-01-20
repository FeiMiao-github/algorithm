#include <comm.h>
#include <cstdint>
#include <tree.h>

class Solution {
public:
    TreeNode* buildTreeInner1(vector<int>& preorder, vector<int>& inorder, int prebegin, int preend, int inobegin, int inoend)
    {
        if (prebegin == preend) { return new TreeNode(preorder[prebegin]); }

        int ltreecnt = 0;
        for (int i = inobegin; i <= inoend; i++)
        {
            if (preorder[prebegin] == inorder[i]) break;
            ltreecnt++;
        }

        TreeNode* left = nullptr, *right = nullptr;
        int pbg = prebegin + 1; int ped = prebegin + ltreecnt;
        int ibg = inobegin; int ied = inobegin + ltreecnt - 1;
        if (pbg <= ped && ibg <= ied)
        {
            left = buildTreeInner1(preorder, inorder, pbg, ped, ibg, ied);
        }

        std::cout << "[" << preorder[prebegin] << "]1st preorder: \n";
        for (int i = pbg; i <= ped; i++)
        {
            std::cout << preorder[i] << "\n";
        }
        std::cout << "[" << preorder[prebegin] << "]1st inorder: \n";
        for (int i = ibg; i <= ied; i++)
        {
            std::cout << inorder[i] << "\n";
        }

        pbg = prebegin + ltreecnt + 1, ped = preend;
        ibg = inobegin + ltreecnt + 1, ied = inoend;
        if (pbg <= ped && ibg <= ied)
        {
            right = buildTreeInner1(preorder, inorder, pbg, ped, ibg, ied);
        }

        std::cout << "[" << preorder[prebegin] << "]2nd preorder: \n";
        for (int i = pbg; i <= ped; i++)
        {
            std::cout << preorder[i] << "\n";
        }
        std::cout << "[" << preorder[prebegin] << "]1st inorder: \n";
        for (int i = ibg; i <= ied; i++)
        {
            std::cout << inorder[i] << "\n";
        }

        return new TreeNode(preorder[prebegin], left, right);
    }

    TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeInner1(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);       
    };

    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        int pl = preorder.size();
        int il = inorder.size();
        stack<TreeNode*> st;
        TreeNode *ret = new TreeNode(preorder[0]);
        st.push(ret);
        for (int i = 1; i < pl; i++)
        {
            if (!st.empty() && st.top()->val == inorder[index])
            {
                TreeNode* tmp;
                while (!st.empty() && index < il && st.top()->val == inorder[index])
                {
                    tmp = st.top(); st.pop(); index ++;
                }
                tmp->right = new TreeNode(preorder[i]);
                st.push(tmp->right);
            }
            else {
                TreeNode* tmp = new TreeNode(preorder[i]);
                if (!st.empty())
                {
                    st.top()->left = tmp;
                }
                st.push(tmp);
            }
        }
        return ret;
    }

    TreeNode* buildTreeInner(vector<int>& preorder, vector<int>& inorder, int val)
    {
        int psize = preorder.size();
        if (pre == psize)
        {
            return nullptr;
        }

        if (inorder[in] == val)
        {
            in++;
            return nullptr;
        }

        int root_val = preorder[pre++];
        TreeNode* ltree = buildTreeInner(preorder, inorder, root_val);
        TreeNode* rtree = buildTreeInner(preorder, inorder, val);
        return new TreeNode(root_val, ltree, rtree);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTreeInner(preorder, inorder, INT32_MAX);
    }

    int pre = 0;
    int in = 0;
};

void test(const vector<int>& preorder, const vector<int>& inorder)
{
    auto param1 = preorder;
    auto param2 = inorder;
    TreeNode* ret = Solution().buildTree(param1, param2);

    std::cout << " ==== iterate ==== \n";
    TreeNode::to_vec_level(ret, [](const vector<TreeNode*>& arr) {
        for (auto ptr: arr)
        {
            if (ptr)
            {
                std::cout << ptr->val << " ";
            }
            else
            {
                std::cout << "null" << " ";
            }
        }
        std::cout << "\n";
    });

    // release memory
    TreeNode treenode(0, ret, nullptr);
}

int main()
{
    test({3,9,20,15,7}, {9, 3, 15, 20, 7});
    test({3, 9, 8, 5, 4, 10, 20, 15, 7}, {4, 5, 8, 10, 9, 3, 15, 20, 7});
    return 0;
}

//        3
// 9            20
//         15         7