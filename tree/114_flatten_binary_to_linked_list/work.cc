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
    void flatten(TreeNode* root) {
        TreeNode *current = root;
        vector<TreeNode *> stack, res;

        while (!stack.empty() || current)
        {
            if (current)
            {
                res.push_back(current);
                stack.push_back(current);
                current = current->left;
            }
            else
            {
                current = *stack.rbegin();
                stack.pop_back();
                current = current->right;
            }
        }
        for (int i = 0; i < res.size(); ++i)
        {
            res[i]->left = NULL;
            if (i < res.size() - 1)
                res[i]->right = res[i + 1];
            else
                res[i]->right = NULL;
        }
    }
};

void print(TreeNode *root)
{
    while (root)
    {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);

    n1.left = &n2;
    n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;

    Solution s;
    s.flatten(&n1);
    print(&n1);
    return 0;
}
