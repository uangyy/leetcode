#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *find_mid(struct ListNode *head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *pre = head, *current = head->next;
    while (current && current->next)
    {
        pre = pre->next;
        current = current->next->next;
    }
    return pre;
}

struct ListNode *merge(struct ListNode *h1, struct ListNode *h2)
{
    struct ListNode *res = NULL, *tail;
    while (h1 && h2)
    {
        if (h1->val < h2->val)
        {
            if (!res)
            {
                res = h1;
                tail = res;
            }
            else
            {
                tail->next = h1;
                tail = tail->next;
            }
            h1 = h1->next;
        }
        else
        {
            if (!res)
            {
                res = h2;
                tail = res;
            }
            else
            {
                tail->next = h2;
                tail = tail->next;
            }
            h2 = h2->next;
        }
    }
    if (h1)
        tail->next = h1;
    if (h2)
        tail->next = h2;
    return res;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next)
        return head;
    struct ListNode *mid = find_mid(head), *head1, *head2;
    head1 = head, head2 = mid->next;
    mid->next = NULL;
    head1 = sortList(head1);
    head2 = sortList(head2);
    head = merge(head1, head2);
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
    res = sortList(&n1);
    print(res);
    return 0;
}
