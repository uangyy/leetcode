#include <stdio.h>

#define bool int
#define true 1
#define false 0

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (!head || !head->next)
        return false;
    struct ListNode *pre = head, *current = head->next;
    bool flag = false;
    while (current)
    {
        if (current == pre)
        {
            flag = true;
            break;
        }
        current = current->next;
        if (!current)
            break;
        if (current == pre)
        {
            flag = true;
            break;
        }
        current = current->next;
        if (!current)
            break;
        if (current == pre)
        {
            flag = true;
            break;
        }
        pre = pre->next;
    }
    return flag;
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
    struct ListNode n5 = {5, NULL},
                    n4 = {4, &n5},
                    n3 = {3, &n4},
                    n2 = {2, &n3},
                    n1 = {1, &n2};
    n5.next = &n1;
    int res;
    //print(&n1);
    res = hasCycle(&n1);
    printf("%d\n", res);
    return 0;
}
