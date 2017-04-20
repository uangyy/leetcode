#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode *> level_nodes;

        if (!root)
            return res;
        level_nodes.push(root);
        int level_count;
        while (!level_nodes.empty())
        {
            level_count = level_nodes.size();
            vector<int> level_res;
            while (level_count--)
            {
                TreeNode *tmp = level_nodes.front();
                level_nodes.pop();
                level_res.push_back(tmp->val);
                if (tmp->left)
                    level_nodes.push(tmp->left);
                if (tmp->right)
                    level_nodes.push(tmp->right);
            }
            res.push_back(level_res);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.left = &n5;
    n4.left = &n6;
    n4.right = &n7;

    Solution s;
    vector<vector<int> > res = s.levelOrderBottom(&n1);

    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
