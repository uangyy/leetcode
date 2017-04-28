#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        map<int, int> count;
        vector<int> res;
        if (!root)
            return res;
        TreeNode *current = root;
        vector<TreeNode *> stack;

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
                if (count.find(current->val) == count.end())
                    count[current->val] = 1;
                else
                    count[current->val]++;
                current = current->right;
            }
        }
        int m = 0;
        for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it)
        {
            if (it->second > m)
            {
                m = it->second;
                res.clear();
                res.push_back(it->first);
            }
            else if (it->second == m)
            {
                res.push_back(it->first);
            }
        }
        return res;
    }
};
int main(int argc, char **argv)
{
    TreeNode n1 = (2),
             n2 = (1),
             n3 = (3),
             n4 = (1),
             n5 = (2),
             n6 = (2);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;

    vector<int> res;
    Solution s;
    res = s.findMode(&n1);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
