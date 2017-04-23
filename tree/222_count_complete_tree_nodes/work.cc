#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int pow(int k)
    {
        int res = 1;
        while (k--)
            res *= 2;
        return res;
    }

    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int l = 0, r = 0;
        TreeNode *current = root;
        while (current)
        {
            ++l;
            current = current->left;
        }
        current = root;
        while (current)
        {
            ++r;
            current = current->right;
        }

        if (l == r)
            return pow(r) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(4);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    Solution s;
    int res = s.countNodes(&n1);
    cout << res << endl;
}
