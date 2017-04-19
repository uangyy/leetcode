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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (p && q && p->val == q->val)
            ;
        else
            return false;
        if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return true;
        return false;
    }
};

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(1), n5(2), n6(3);
    n1.left = &n2;
    n1.right = &n3;

    n4.left = &n5;
    n4.right = &n6;

    Solution s;
    bool res = s.isSameTree(&n1, &n4);
    cout << res << endl;
    return 0;
}
