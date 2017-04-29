#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int get_diameter(struct TreeNode *root, int *res)
{
    int l, r;
    if (!root)
        return 0;
    l = get_diameter(root->left, res);
    r = get_diameter(root->right, res);
    if (l + r + 1 > *res)
        *res = l + r + 1;
    return l > r ? l + 1 : r + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    if (!root)
        return 0;
    int res = 0;
    get_diameter(root, &res);
    return res - 1;
}

int main(int argc, char **argv)
{
    struct TreeNode n1 = {1, NULL, NULL},
                    n2 = {2, NULL, NULL},
                    n3 = {3, NULL, NULL},
                    n4 = {4, NULL, NULL},
                    n5 = {5, NULL, NULL};
    int res;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    res = diameterOfBinaryTree(&n1);
    printf("%d\n", res);
    return 0;
}
