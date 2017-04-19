#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct TreeNode **g(int s, int e, int *returnSize)
{
    if (s > e)
    {
        struct TreeNode **res = malloc(sizeof(struct TreeNode *));
        res[0] = NULL;
        *returnSize = 1;
        return res;
    }

    int i, j, k, c, *ret_size_l = malloc(sizeof(int)), *ret_size_r = malloc(sizeof(int));
    struct TreeNode **res = malloc(sizeof(struct TreeNode *));
    *returnSize = 0;
    c = 0;
    for (i = s; i <= e; ++i)
    {
        struct TreeNode **left_tree, **right_tree;
        left_tree = g(s, i - 1, ret_size_l);
        right_tree = g(i + 1, e, ret_size_r);
        *returnSize += *ret_size_l * *ret_size_r;
        res = realloc(res, sizeof(struct TreeNode *) * *returnSize);
        for (j = 0; j < *ret_size_l; ++j)
        {
            for (k = 0; k < *ret_size_r; ++k)
            {
                struct TreeNode *left, *right, *root;
                left = left_tree[j];
                right = right_tree[k];
                root = malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = left;
                root->right = right;
                res[c++] = root;
            }
        }
        free(left_tree);
        free(right_tree);
    }
    free(ret_size_l);
    free(ret_size_r);
    return res;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n < 1)
        return NULL;
    return g(1, n, returnSize);
}

int main(int argc, char **argv)
{
    int n = 4;
    struct TreeNode **res;
    res = generateTrees(4, &n);
    printf("%d\n", n);
    return 0;
}
