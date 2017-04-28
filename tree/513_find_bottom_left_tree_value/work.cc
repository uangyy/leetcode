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
    int findBottomLeftValue(TreeNode* root) {
        int level = 1, res, m = 0;
        vector<TreeNode *> stack;
        TreeNode *current = root, *last = NULL;
        while (current)
        {
            stack.push_back(current);
            level++;
            current = current->left;
        }
        while (!stack.empty())
        {
            current = *stack.rbegin();
            if (!current->right || current->right == last)
            {
                if (level > m)
                {
                    res = current->val;
                    m = level;
                }
                stack.pop_back();
                level--;
                //cout << "level: " << level << ": " << current->val << endl;
                last = current;
            }
            else
            {
                current = current->right;
                while (current)
                {
                    stack.push_back(current);
                    level++;
                    current = current->left;
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.left = &n5;

    Solution s;
    cout << s.findBottomLeftValue(&n1) << endl;
    return 0;
}
