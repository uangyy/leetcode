#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder_travel(struct TreeNode *root)
{
    if (!root)
        return;
    // left
    inorder_travel(root->left);
    // root
    printf("%d ", root->val);
    // right
    inorder_travel(root->right);
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0)
        return NULL;
    int mid = (numsSize - 1) / 2;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = root->right = NULL;

    // left
    root->left = sortedArrayToBST(nums, mid);
    // right
    root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);

    return root;
}

int main(int argc, char **argv)
{
    /*
    struct TreeNode root, left, right;
    root.val = 2;
    root.left = &left;
    root.right = &right;
    left.val = 1;
    left.left = left.right = NULL;
    right.val = 3;
    right.left = right.right = NULL;
    
    inorder_travel(&root);
    */

    //int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arr[] = {3, 5, 8};
    struct TreeNode *root;
    root = sortedArrayToBST(arr, 3);
    inorder_travel(root);
    return 0;
}
