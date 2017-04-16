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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int node_count = n - m + 1, pass = m;
        ListNode *start = head, *pre = NULL, *before = NULL, *after = NULL;
        while (--pass)
        {
            pre = start;
            start = start->next;
        }

        reverse(start, node_count, &before, &after);
        if (m == 1)
        {
            return before;
        }
        else
        {
            pre->next = before;
            return head;
        }
    }
    void reverse(ListNode *start, int n, ListNode **pbefore, ListNode **pafter)
    {
        if (n == 1)
        {
            *pafter = start->next;
            *pbefore = start;
            return;
        }
        reverse(start->next, --n, pbefore, pafter);
        start->next->next = start;
        start->next = *pafter;
        return;
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
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5), *res;
    n1.next = &n2;
    n2.next = &n3;
    //n3.next = &n4;
    //n4.next = &n5;
    print(&n1);
    res = s.reverseBetween(&n1, 1, 3);
    //res = s.reverseBetween(&n5, 1, 1);
    print(res);
}
