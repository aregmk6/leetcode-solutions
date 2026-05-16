#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{
    void recTrav(vector<int>& res, TreeNode* cur)
    {
        if (!cur) {
            return;
        }

        recTrav(res, cur->left);
        res.push_back(cur->val);
        recTrav(res, cur->right);
    }

  public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res{};
        recTrav(res, root);

        return res;
    }
};
