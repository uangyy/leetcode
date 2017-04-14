#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if (!head || !head->val)
        return head;
    struct ListNode *current = head->next, *tail = head;

    while (current)
    {
        tail->next = current->next;
        current->next = head;
        head = current;
        current = tail->next;
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
    res = reverseList(&n1);
    print(res);
    return 0;
}
