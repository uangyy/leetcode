#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head || !head->next)
        return head;
    struct ListNode *current = head, *tail1 = NULL, *tail2 = NULL, *head2;

    while (current && current->next)
    {
        if (!tail1)
        {
            tail1 = current;
            head2 = current->next;
            tail2 = head2;
        }
        else
        {
            tail1->next = current;
            tail2->next = current->next;
            tail1 = tail1->next;
            tail2 = tail2->next;
        }

        current = current->next->next;
    }

    if (current)
    {
        tail1->next = current;
        tail1 = tail1->next;
    }
    tail1->next = NULL;
    tail2->next = NULL;
    tail1->next = head2;
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
                    n0 = {1, &n4},
                    *res;
    int is_res;
    print(&n0);
    print(&n1);
    res = oddEvenList(&n1);
    print(res);
    return 0;
}
