#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !head->next)
        return NULL;
    if (head == head->next)
        return head;

    struct ListNode *pre = head, *current = head;
    int i = 0, j = 0, cycle_len, flag = 0;

    while (current)
    {
        current = current->next;
        j++;
        if (!current)
            return NULL;
        if (current == pre)
            if (flag)
                break;
            else
            {
                flag = 1;
                i = j = 0;
                continue;
            }
        current = current->next;
        j++;
        if (!current)
            return NULL;
        if (current == pre)
            if (flag)
                break;
            else
            {
                flag = 1;
                i = j = 0;
                continue;
            }
        pre = pre->next;
        i++;
    }
    cycle_len = j - i;

    printf("%d\n", cycle_len);

    current = pre = head;
    while (--cycle_len)
    {
        current = current->next;
    }

    while (current->next != pre)
    {
        pre = pre->next;
        current = current->next;
    }
    return pre;
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
    n6.next = &n3;
    res = detectCycle(&n1);
    printf("%d\n", res->val);
    return 0;
}
