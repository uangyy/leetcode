#include <stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head)
        return head;

    ListNode *pre = NULL, *first = head, *current = head->next;
    int same_val = first->val, flag = 0;
    while (current)
    {
        if (same_val != current->val)
        {
            if (flag)
            {
                if (pre)
                    pre->next = current;
                else
                {
                    head = current;
                }
            }
            else
            {
                pre = first;
            }
            first = current;
            current = current->next;
            same_val = first->val;
            flag = 0;
        }
        else
        {
            flag = 1;
            first->next = current->next;
            current = current->next;
        }
    }
    if (flag)
    {
        if (pre)
            pre->next = current;
        else
            head = current;
    }
    return head;
}


void print(ListNode *head)
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
    ListNode n1, n2, n3, n4, n5, *res;
    n1.val = 1;
    n2.val = 2;
    n3.val = 2;
    n4.val = 4;
    n5.val = 5;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;
    //n4.next = NULL;
    //n4.next = &n5;
    //n5.next = NULL;
    print(&n1);
    //res = reverseKGroup(&n1, 2);
    res = deleteDuplicates(&n1);
    print(res);
}
