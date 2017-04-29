#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int get_tilt(struct TreeNode *root, int *res)
{
    if (!root)
        return 0;
    int l, r, tilt;
    l = get_tilt(root->left, res);
    r = get_tilt(root->right, res);

    tilt = r - l;
    if (tilt < 0)
        tilt = -tilt;

    *res += tilt;

    return root->val + r + l;
}

int findTilt(struct TreeNode* root) {
    int res = 0;
    get_tilt(root, &res);
    return res;
}

int main(int argc, char **argv)
{
    struct TreeNode n1 = {1, NULL, NULL},
                    n2 = {2, NULL, NULL},
                    n3 = {3, NULL, NULL};
    int res;
    n1.left = &n2;
    n1.right = &n3;

    res = findTilt(&n1);
    return 0;
}
