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
    void recoverTree(TreeNode* root) {
        TreeNode *p1 = NULL, *p2 = NULL, *current = root, *last = NULL;
        vector<TreeNode *>stack;
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
                {
                    if (!p1)
                    {
                        p1 = last;
                        p2 = current;
                    }
                    else
                    {
                        p2 = current;
                    }
                }
                last = current;
                current = current->right;
            }
        }
        swap(p1->val, p2->val);
    }
};

void inorder_traversal(TreeNode *root)
{
    vector<TreeNode *> stack;
    TreeNode *current = root;
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
            cout << current->val << " ";
            current = current->right;
        }
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    Solution s;
    n3.left = &n4;
    n3.right = &n2;
    n4.left = &n1;
    n2.right = &n5;
    inorder_traversal(&n3);
    s.recoverTree(&n3);
    inorder_traversal(&n3);
    return 0;
}
