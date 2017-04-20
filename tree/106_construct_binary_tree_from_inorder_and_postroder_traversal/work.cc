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
    TreeNode *build(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe)
    {
        if (ps > pe)
            return NULL;
        if (ps == pe)
            return new TreeNode(postorder[pe]);
        TreeNode *root = new TreeNode(postorder[pe]);
        int pos;
        for (pos = is; pos <= ie; ++pos)
        {
            if (inorder[pos] == postorder[pe])
                break;
        }
        root->left = build(inorder, is, pos - 1, postorder, ps, ps + pos - is - 1);
        root->right = build(inorder, pos + 1, ie, postorder, ps + pos - is, pe - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

int main(int argc, char **argv)
{
    vector<int> post, in;
    post.push_back(6);
    post.push_back(7);
    post.push_back(4);
    post.push_back(2);
    post.push_back(5);
    post.push_back(3);
    post.push_back(1);

    in.push_back(2);
    in.push_back(6);
    in.push_back(4);
    in.push_back(7);
    in.push_back(1);
    in.push_back(3);
    in.push_back(5);

    Solution s;

    TreeNode *res = s.buildTree(in, post);
    return 0;
}
