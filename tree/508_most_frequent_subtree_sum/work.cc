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

    int get_sum(TreeNode *root, map<int, int> &count)
    {
        if (!root)
            return 0;
        int l, r;
        l = get_sum(root->left, count);
        r = get_sum(root->right, count);
        int sum = l + r + root->val;
        if (count.find(sum) != count.end())
            count[sum]++;
        else
            count[sum] = 1;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> count;
        get_sum(root, count);
        vector<int> res;

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
    TreeNode n1(5), n2(2), n3(-5);
    n1.left = &n2;
    n1.right = &n3;

    Solution s;
    vector<int> res = s.findFrequentTreeSum(&n1);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
