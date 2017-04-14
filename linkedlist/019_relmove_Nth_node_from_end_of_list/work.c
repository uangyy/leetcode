#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (n <= 0)
        return head;
    struct ListNode *pre = head, *current = head;
    while (n-- && current)
    {
        current = current->next;
    }
    if (!current)
        if (n != -1)
            return head;
        else
            return head->next;
    while (current->next)
    {
        pre = pre->next;
        current = current->next;
    }

    pre->next = pre->next->next;
    return head;
}

void print(struct ListNode *head)
{
    while (head){
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
                    n1 = {1, &n2},
                    *res;
    print(&n1);
    res = removeNthFromEnd(&n1, 1);
    print(res);
    return 0;
}
