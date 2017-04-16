#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int adjust(struct ListNode *head)
{
    if (!head->next)
    {
        if (head->val >= 10)
        {
            head->val %= 10;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int res = adjust(head->next);
    if (res == 1)
    {
        head->val += res;
        if (head->val >= 10)
        {
            head->val %= 10;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (head->val >= 10)
        {
            head->val %= 10;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    struct ListNode *head1 = l1, *head2 = l2, *res;
    int len1 = 0, len2 = 0, ahead;
    while (head1) { head1 = head1->next; ++len1; }
    while (head2) { head2 = head2->next; ++len2; }
    ahead = len1 - len2;

    if (ahead < 0)
    {
        ahead = - ahead;
        head1 = l2;
        head2 = l1;
        res = l2;
    }
    else
    {
        res = l1;
        head1 = l1;
        head2 = l2;
    }

    while (ahead--)
    {
        head1 = head1->next;
    }

    while (head1)
    {
        head1->val += head2->val;
        head1 = head1->next;
        head2 = head2->next;
    }
    
    ahead = adjust(res);
    if (ahead)
    {
        struct ListNode *tmp = malloc(sizeof(struct ListNode));
        tmp->val = 1;
        tmp->next = res;
        return tmp;
    }
    return res;
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
    int is_res;
    print(&n0);
    print(&n1);
    //res = add_list(&n0, &n1);
    res = addTwoNumbers(&n0, &n1);
    print(res);
    return 0;
}
