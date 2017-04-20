#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int minDepth(struct TreeNode* root) {
    if (!root)
        return 0;
    int l, r;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    l = minDepth(root->left);
    r = minDepth(root->right);
    if (l < r)
        return l + 1;
    else
        return r + 1;
}

int main(int argc, char **argv)
{
    struct TreeNode n1 = {1, NULL, NULL},
                    n2 = {2, NULL, NULL},
                    n3 = {3, NULL, NULL},
                    n4 = {4, NULL, NULL},
                    n5 = {5, NULL, NULL},
                    n6 = {6, NULL, NULL},
                    n7 = {7, NULL, NULL};
    int res;

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n6.left = &n7;

    res = minDepth(&n1);
    printf("%d\n", res);
    return 0;
}
