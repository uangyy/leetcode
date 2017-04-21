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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode *> stack;
        TreeNode *current = root, *last = NULL;
        
        while (current)
        {
            stack.push_back(current);
            current = current->left;
        }

        while (!stack.empty())
        {
            current = *stack.rbegin();
            stack.pop_back();
            if (!current->right || current->right == last)
            {
                res.push_back(current->val);
                last = current;
            }
            else
            {
                stack.push_back(current);
                current = current->right;
                while (current)
                {
                    stack.push_back(current);
                    current = current->left;
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(4);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;

    Solution s;
    vector<int> res = s.postorderTraversal(&n1);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
