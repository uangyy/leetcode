#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *end, *start, *pre = NULL;
        if (!head)
            return head;
        int len = 0;
        start = head;
        while (start)
        {
            len++;
            start = start->next;
        }
        k %= len;
        if (k == 0)
            return head;
        end = head;
        start = head;
        while (--k)
        {
            end = end->next;
        }
        while (end->next)
        {
            end = end->next;
            pre = start;
            start = start->next;
        }

        if (!pre)
            return head;
        pre->next = NULL;
        end->next = head;
        head = start;
        return head;
    }
};

void print(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    ListNode n1(1), n2(2), n3(3), n4(4), *res;
    Solution s;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    print(&n1);
    res = s.rotateRight(&n1, 45);
    print(res);
}
