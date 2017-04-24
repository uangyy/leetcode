#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int get_heigh(struct TreeNode *root)
{
    if (!root)
        return 0;
    int l, r;
    l = get_heigh(root->left);
    r = get_heigh(root->right);
    return l > r ? l + 1 : r + 1;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int h, i;
    struct TreeNode **arr1, **arr2, *current = root, *res;
    if (!root)
        return NULL;
    h = get_heigh(root);
    arr1 = malloc(sizeof(struct TreeNode) * h);
    arr2 = malloc(sizeof(struct TreeNode) * h);
    memset(arr1, 0, sizeof(struct TreeNode) * h);
    memset(arr2, 0, sizeof(struct TreeNode) * h);

    i = 0;
    while (current)
    {
        arr1[i++] = current;
        if (current->val == p->val)
            break;
        else if (current->val > p->val)
            current = current->left;
        else
            current = current->right;
    }

    i = 0;
    current = root;
    while (current)
    {
        arr2[i++] = current;
        if (current->val == q->val)
            break;
        else if (current->val > q->val)
            current = current->left;
        else
            current = current->right;
    }
    res = arr1[0];
    i = 0;
    while (1)
    {
        if (arr1[i] == arr2[i])
            res = arr1[i++];
        else
        {
            free(arr1);
            free(arr2);
            return res;
        }
    }
}

struct TreeNode* lowestCommonAncestor_iterative(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (1)
    {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
}

struct TreeNode* lowestCommonAncestor_recursive(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor_recursive(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor_recursive(root->right, p, q);
    return root;
}

int main(int argc, char **argv)
{
    struct TreeNode n6 = {6, NULL, NULL},
                    n2 = {2, NULL, NULL},
                    n8 = {8, NULL, NULL},
                    n0 = {0, NULL, NULL},
                    n4 = {4, NULL, NULL},
                    n3 = {3, NULL, NULL},
                    n5 = {5, NULL, NULL},
                    n7 = {7, NULL, NULL},
                    n9 = {9, NULL, NULL},
                    *res;
    n6.left = &n2;
    n6.right = &n8;
    n2.left = &n0;
    n2.right = &n4;
    n4.left = &n3;
    n4.right = &n5;
    n8.left = &n7;
    n8.right = &n9;
    res = lowestCommonAncestor_recursive(&n6, &n2, &n8);
    printf("%d\n", res->val);
    res = lowestCommonAncestor_recursive(&n6, &n2, &n4);
    printf("%d\n", res->val);
    return 0;
}
