#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root)
        return NULL;
    struct TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main(int argc, char **argv)
{
    struct TreeNode n1 = {1, NULL, NULL},
                    n2 = {2, NULL, NULL},
                    n3 = {3, NULL, NULL},
                    n4 = {4, NULL, NULL},
                    n5 = {5, NULL, NULL},
                    n6 = {6, NULL, NULL},
                    n7 = {7, NULL, NULL},
                    *res;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    res = invertTree(&n1);
    return 0;
}
