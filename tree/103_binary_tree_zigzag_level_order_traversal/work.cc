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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        vector<TreeNode *> s1, s2;

        if (!root)
            return res;
        s1.push_back(root);
        vector<int> level;
        level.push_back(root->val);
        res.push_back(level);

        while (!s1.empty())
        {
            vector<int> l1;
            while (!s1.empty())
            {
                TreeNode *tmp = *s1.rbegin();
                s1.pop_back();
                if (tmp->right)
                {
                    s2.push_back(tmp->right);
                    l1.push_back(tmp->right->val);
                }
                if (tmp->left)
                {
                    s2.push_back(tmp->left);
                    l1.push_back(tmp->left->val);
                }
            }
            if (l1.size())
                res.push_back(l1);
            vector<int> l2;
            while (!s2.empty())
            {
                TreeNode *tmp = *s2.rbegin();
                s2.pop_back();
                if (tmp->left)
                {
                    s1.push_back(tmp->left);
                    l2.push_back(tmp->left->val);
                }
                if (tmp->right)
                {
                    s1.push_back(tmp->right);
                    l2.push_back(tmp->right->val);
                }
            }
            if (l2.size())
                res.push_back(l2);
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
    vector<vector<int> >res = s.zigzagLevelOrder(&n1);
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
