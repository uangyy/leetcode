#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        TreeNode *current = root;

        queue<TreeNode *> level_node;
        level_node.push(current);
        int level_count;

        while (!level_node.empty())
        {
            level_count = level_node.size();
            while (level_count--)
            {
                current = level_node.front();
                level_node.pop();
                if (level_count == 0)
                    res.push_back(current->val);
                if (current->left)
                    level_node.push(current->left);
                if (current->right)
                    level_node.push(current->right);
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
    n2.right = &n5;
    n3.right = &n4;

    TreeNode n6(1), n7(2);
    n6.right = &n7;
    
    Solution s;
    vector<int> res;
    res = s.rightSideView(&n6);

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
