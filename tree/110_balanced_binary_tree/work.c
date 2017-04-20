#include <stdio.h>

#define bool int
#define true 1
#define false 0

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int tree_heigh(struct TreeNode *root)
{
    if (!root)
        return 0;
    int l, r;
    l = tree_heigh(root->left);
    r = tree_heigh(root->right);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (!root)
        return true;
    int l, r;
    l = tree_heigh(root->left);
    r = tree_heigh(root->right);
    if (l - r > 1 || r - l > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
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

    res = isBalanced(&n1);
    printf("%d\n", res);
    return 0;
}
