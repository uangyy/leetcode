#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // inorder_traversal
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        vector<TreeNode *> stack;
        TreeNode *current = root, *last = NULL;
        while (!stack.empty() || current)
        {
            if (current)
            {
                stack.push_back(current);
                current = current->left;
            }
            else
            {
                current = *stack.rbegin();
                stack.pop_back();
                if (last && last->val >= current->val)
                    return false;
                last = current;
                current = current->right;
            }
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3);
    n2.left = &n1;
    n2.right = &n3;
    Solution s;
    bool res = s.isValidBST(&n2);
    cout << res << endl;
}
