#include <iostream>
using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *tail = NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val < l2->val)
        {
            head = l1;
            tail = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            tail = l2;
            l2 = l2->next;
        }

        ListNode *tmp;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tmp = l1->next;
                tail->next = l1;
                tail = l1;
                l1 = tmp;
            }
            else
            {
                tmp = l2->next;
                tail->next = l2;
                tail = l2;
                l2 = tmp;
            }
        }

        if (l1)
        {
            tail->next = l1;
        }
        else
        {
            tail->next = l2;
        }
        return head;
    }
};

void print(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    Solution s;
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(1), n7(2), n8(10), *res;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n6.next = &n7;
    n7.next = &n8;
    print(&n1);
    res = s.mergeTwoLists(&n1, &n6);
    print(res);
}
