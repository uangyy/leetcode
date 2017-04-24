#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<TreeNode *> stack;
        vector<string> res;
        TreeNode *current = root, *last = NULL;
        ostringstream os;

        while (current)
        {
            stack.push_back(current);
            current = current->left;
        }

        while (!stack.empty())
        {
            current = *stack.rbegin();
            if (!current->right || current->right == last)
            {
                if (!current->right && !current->left)
                {
                    string tmp;
                    for (int i = 0; i < stack.size(); ++i)
                    {
                        os.str("");
                        os << stack[i]->val;
                        if (i != stack.size() - 1)
                            tmp += os.str() + "->";
                        else
                            tmp += os.str();
                    }
                    res.push_back(tmp);
                }
                stack.pop_back();
                last = current;
            }
            else
            {
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
    TreeNode n1(1),
             n2(2),
             n3(3),
             n4(4),
             n5(5);
    n1.left = &n2;
    //n1.right = &n3;
    //n2.left = &n4;
    //n2.right = &n5;
    vector<string> res;
    Solution s;
    res = s.binaryTreePaths(&n1);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
