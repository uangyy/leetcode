#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int inorder(struct TreeNode *root, int *res)
{
    if (!root)
        return 0;
    int count;
    count = inorder(root->left, res);
    res[count++] = root->val;
    count += inorder(root->right, res + count);
    return count;
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res = malloc(sizeof(int) * (*returnSize));
    inorder(root, res);
    return res;
}

int main(int argc, char **argv)
{
    struct TreeNode n3 = {3, NULL, NULL},
                    n2 = {2, NULL, NULL},
                    n1 = {1, &n2, &n3};
    int *res, *size = malloc(sizeof(int)), i;
    *size = 3;
    res = inorderTraversal(&n1, size);
    for (i = 0; i < *size; ++i)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);
    return 0;
}
