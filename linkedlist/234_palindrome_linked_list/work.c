#include <stdio.h>

#define bool int
#define true 1
#define false 0

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *find_mid(struct ListNode *head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *mid = head, *current = head->next;
    while (current && current->next)
    {
        mid = mid->next;
        current = current->next->next;
    }
    return mid;
}

struct ListNode *reverse(struct ListNode *head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *pre = head, *current = head->next, *tail = head;
    while (current)
    {
        tail->next = current->next;
        current->next = head;
        head = current;
        current = tail->next;
    }
    return head;
}

bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next)
        return true;
    struct ListNode *mid = find_mid(head), *head1, *head2;
    head1 = head, head2 = mid->next;
    mid->next = NULL;
    head2 = reverse(head2);
    while (head1 && head2)
    {
        if (head1->val != head2->val)
            break;
        head1 = head1->next;
        head2 = head2->next;
    }

    if (!head2)
        return true;
    return false;
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
    struct ListNode n6 = {1, NULL},
                    n5 = {2, &n6},
                    n4 = {3, &n5},
                    n3 = {3, &n4},
                    n2 = {2, &n3},
                    n1 = {1, &n2},
                    n0 = {1, &n4},
                    *res;
    int is_res;
    print(&n0);
    print(&n1);
    is_res = isPalindrome(&n1);
    printf("%d\n", is_res);
    return 0;
}
