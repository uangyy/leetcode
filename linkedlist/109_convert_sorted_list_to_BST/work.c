#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode *find_mid(struct ListNode *head)
{
    struct ListNode *pre = head, *current = head, *next = head;
    while (next)
    {
        next = next->next;
        if (!next)
            return pre;
        next = next->next;
        if (!next)
            return pre;

        pre = current;
        current = current->next;
    }
    return pre;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head)
        return NULL;
    if (!head->next)
    {
        struct TreeNode *tmp = malloc(sizeof(struct TreeNode));
        tmp->val = head->val;
        tmp->left = tmp->right = NULL;
        return tmp;
    }

    struct ListNode *pre, *mid;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    pre = find_mid(head);
    mid = pre->next;
    root->val = mid->val;
    pre->next = NULL;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;
}

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

void print_list(struct ListNode *head)
{
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    struct ListNode n5 = {5, NULL},
                    n4 = {4, &n5},
                    n3 = {3, &n4},
                    n2 = {2, &n3},
                    n1 = {1, &n2};
    struct TreeNode *res;
    print_list(&n1);
    res = sortedListToBST(&n1);
    inorder_travel(res);
    return 0;
}
