#include <stdio.h>

#define bool int
#define true 1
#define false 0

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    *node = *node->next;
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
    deleteNode(&n3);
    print(&n1);
    return 0;
}
