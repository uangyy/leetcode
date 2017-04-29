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
    int sum_nodes(TreeNode *root, int up)
    {
        if (!root)
            return up;
        int sum = sum_nodes(root->right, up);
        root->val += sum;
        sum = sum_nodes(root->left, root->val);
        return sum;
    }

    TreeNode* convertBST(TreeNode* root) {
        sum_nodes(root, 0);
        return root;
    }
};

int main(int argc, char **argv)
{
    /*
    TreeNode n1(2), n2(0), n3(3), n4(-4), n5(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    */
    TreeNode n1(5), n2(2), n3(13);
    n1.left = &n2;
    n1.right = &n3;

    Solution s;
    s.convertBST(&n1);
    return 0;
}
