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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode *> stack;
        vector<int> res;
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
                res.push_back(current->val);
                current = current->right;
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    TreeNode n1(1), n2(2), n3(3);
    n1.right = &n2;
    n2.left = &n3;
    vector<int> res;
    res = s.inorderTraversal(&n1);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
