#include <iostream>
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
    vector<int> largestValues(TreeNode* root) {
        TreeNode *current = root;
        queue<TreeNode *> q;
        q.push(root);
        vector<int> res;
        
        if (!root)
            return res;

        while (!q.empty())
        {
            int level_size = q.size();
            int m = q.front()->val;
            while (level_size--)
            {
                current = q.front();
                if (current->val > m)
                    m = current->val;
                q.pop();
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            res.push_back(m);
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(3), n3(2), n4(5), n5(3), n6(9);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    
    Solution s;
    vector<int> res = s.largestValues(&n1);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
