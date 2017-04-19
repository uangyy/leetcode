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
    bool is_sym(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;

        return left->val == right->val && is_sym(left->left, right->right) && is_sym(left->right, right->left);
    }

    bool is_sym_nonrec(TreeNode *left, TreeNode *right)
    {
        TreeNode *current1 = left, *current2 = right;
        vector<TreeNode *> stack1, stack2;

        while (!stack1.empty() || current1)
        {
            if (current1)
            {
                if (!current2)
                    return false;
                else if (current1->val != current2->val)
                    return false;
                else
                {
                    stack1.push_back(current1);
                    stack2.push_back(current2);
                    current1 = current1->left;
                    current2 = current2->right;
                }
            }
            else if (current2)
                return false;
            else
            {
                current1 = *stack1.rbegin();
                current2 = *stack2.rbegin();
                stack1.pop_back();
                stack2.pop_back();
                current1 = current1->right;
                current2 = current2->left;
            }
        }
        if (!stack2.empty() || current2)
            return false;
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        //return root ? is_sym(root->left, root->right) : true;
        return root ? is_sym_nonrec(root->left, root->right) : true;
    }
};

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(2), n4(3), n5(3);
    //n1.left = &n2;
    n1.right = &n3;
    //n2.left = &n4;
    //n3.right = &n5;
    Solution s;
    cout << s.isSymmetric(&n1) << endl;
    return 0;
}
