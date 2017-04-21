#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int helper(TreeNode *root, int *res)
    {
        if (!root)
            return 0;
        int l = helper(root->left, res);
        int r = helper(root->right, res);
        if (l < 0)
            l = 0;
        if (r < 0)
            r = 0;
        if (l + r + root->val > *res)
            *res = l + r + root->val;
        return l > r ? root->val + l : root->val + r;
    }

    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int res = root->val;
        helper(root, &res);
        return res;
    }
};

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    TreeNode n11(-3);

    Solution s;

    int res = s.maxPathSum(&n11);
    cout << res << endl;
    return 0;
}
