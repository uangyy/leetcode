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
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode *> queue;
        vector<vector<int> > res;
        int level_count = 0;
        if (!root)
            return res;
        queue.push(root);
        while (!queue.empty())
        {
            level_count = queue.size();
            vector<int> level;
            while (level_count--)
            {
                TreeNode *current = queue.front();
                queue.pop();
                if (current->left)
                    queue.push(current->left);
                if (current->right)
                    queue.push(current->right);
                level.push_back(current->val);
            }
            res.push_back(level);
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n4.right = &n5;
    Solution s;
    vector<vector<int> >res = s.levelOrder(&n1);
    for (int i = 0; i < res.size(); ++i)
    {
        vector<int> level = res[i];
        for (int j = 0; j < level.size(); ++j)
        {
            cout << level[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
