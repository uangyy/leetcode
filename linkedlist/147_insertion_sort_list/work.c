#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next)
        return head;
    struct ListNode *current = head->next;
    head->next = NULL;
    while (current)
    {
        struct ListNode *pre = NULL, *pos = head;
        while (pos)
        {
            if (pos->val >= current->val)
                break;
            pre = pos;
            pos = pos->next;
        }
        if (!pre)
        {
            struct ListNode *tmp = current->next;
            current->next = head;
            head = current;
            current = tmp;
        }
        else
        {
            struct ListNode *tmp = current->next;
            current->next = pos;
            pre->next = current;
            current = tmp;
        }
    }
    return head;
}

void print(struct ListNode *head)
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
    struct ListNode n6 = {6, NULL},
                    n5 = {5, &n6},
                    n4 = {4, &n5},
                    n3 = {3, &n4},
                    n2 = {2, &n3},
                    n1 = {1, &n2},
                    *res;
    print(&n1);
    res = insertionSortList(&n1);
    print(res);
    return 0;
}
