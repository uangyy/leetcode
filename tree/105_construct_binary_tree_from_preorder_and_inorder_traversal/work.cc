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
    inline int find_pos(vector<int> &inorder, int s, int e, int t)
    {
        for (int i = s; i <= e; ++i)
        {
            if (inorder[i] == t)
                return i;
        }
    }

    TreeNode *build(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie)
    {
        if (ps > pe)
            return NULL;
        if (ps == pe)
            return new TreeNode(preorder[ps]);
        TreeNode *root = new TreeNode(preorder[ps]);
        int pos = find_pos(inorder, is, ie, preorder[ps]);
        int left_num = pos - is, right_num = ie - pos;
        root->left = build(preorder, ps + 1, ps + left_num, inorder, is, pos - 1);
        root->right = build(preorder, ps + left_num + 1, pe, inorder, pos + 1, ie);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

int main(int argc, char **argv)
{
    vector<int> pre, in;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(6);
    pre.push_back(7);
    pre.push_back(3);
    pre.push_back(5);

    in.push_back(2);
    in.push_back(6);
    in.push_back(4);
    in.push_back(7);
    in.push_back(1);
    in.push_back(3);
    in.push_back(5);

    Solution s;

    TreeNode *res = s.buildTree(pre, in);
    return 0;
}
