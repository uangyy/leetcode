#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
void reorderList(struct ListNode* head) {
    if (!head || !head->next)
        return;
    struct ListNode *mid = head, *current = head->next, *head2, *tail;
    while (current && current->next)
    {
        mid = mid->next;
        current = current->next->next;
    }

    // cut
    head2 = mid->next;
    mid->next = NULL;

    // reverse
    tail = head2;
    current = head2->next;
    while (current)
    {
        tail->next = current->next;
        current->next = head2;
        head2 = current;
        current = tail->next;
    }

    while (head && head2)
    {
        struct ListNode *tmp = head->next;
        head->next = head2;
        head = tmp;
        tmp = head2->next;
        head2->next = head;
        head2 = tmp;
    }

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
    reorderList(&n1);
    print(&n1);
    return 0;
}
