#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *less_tail = NULL, *current, *pre = NULL;
    if (!head || !head->next)
        return head;

    current = head;
    while (current)
    {
        if (current->val >= x)
        {
            pre = current;
            current = current->next;
        }
        else
        {
            if (!pre)
            {
                if (!less_tail)
                    less_tail = head;
                else
                    less_tail = less_tail->next;
                current = current->next;
            }
            else
            {
                pre->next = current->next;
                if (!less_tail)
                {
                    less_tail = current;
                    current->next = head;
                    head = current;
                }
                else
                {
                    current->next = less_tail->next;
                    less_tail->next = current;
                    less_tail = current;
                }
                current = pre->next;
            }
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
    struct ListNode n1, n2, n3, n4, n5, n6, *res;
    n1.val = 1;
    n2.val = 4;
    n3.val = 3;
    n4.val = 2;
    n5.val = 5;
    n6.val = 2;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = NULL;
    print(&n1);

    res = partition(&n1, 3);

    print(res);
    return 0;
}
