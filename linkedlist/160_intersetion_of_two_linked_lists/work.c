#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB)
        return NULL;

    int len1 = 0, len2 = 0, ahead = 0;
    struct ListNode *head1 = headA, *head2 = headB;
    while (head1)
    {
        ++len1;
        head1 = head1->next;
    }
    while (head2)
    {
        ++len2;
        head2 = head2->next;
    }
    ahead = len1 - len2;
    if (ahead < 0)
    {
        ahead = -ahead;
        head1 = headB;
        head2 = headA;
    }
    else
    {
        head1 = headA;
        head2 = headB;
    }

    while (ahead--)
    {
        head1 = head1->next;
    }

    while (head1)
    {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
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
    res = getIntersectionNode(&n0, &n1);
    print(res);
    return 0;
}
