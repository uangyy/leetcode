#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    if (!head)
        return head;

    struct ListNode *pre = NULL, *current = head;
    while (current)
    {
        if (current->val == val)
            if (!pre)
                head = head->next;
            else
                pre->next = current->next;
        else
            pre = current;
        current = current->next;
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
                    n0 = {1, &n4},
                    *res;
    print(&n0);
    print(&n1);
    res = removeElements(&n1, 6);
    print(res);
    return 0;
}
