#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *start = head, *end, *res = NULL;
        ListNode *pre = NULL, *next = NULL;
        while (start)
        {
            int count = k;
            end = start;
            while (--count && end)
            {
                end = end->next;
            }
            if (!end)
                break;
            next = end->next;
            ListNode *current = start->next, *tail = start;
            while (current != next)
            {
                ListNode *tmp = current->next;
                current->next = start;
                tail->next = tmp;
                start = current;
                current = tmp;
                if (pre)
                    pre->next = start;
            }
            pre = tail;
            if (!res)
                res = start;
            start = next;
        }
        if (!res)
            res = head;
        return res;
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
    //n2.next = &n3;
    //n3.next = &n4;
    print(&n1);
    res = s.reverseKGroup(&n1, 3);
    print(res);
}
