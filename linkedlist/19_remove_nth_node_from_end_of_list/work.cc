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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = head, *pre = head;
        while (n--)
        {
            start = start->next;
        }
        
        if (start == NULL)
        {
            head = head->next;
            return head;
        }

        while (start->next)
        {
            pre = pre->next;
            start = start->next;
        }
        ListNode *tmp = pre->next;
        pre->next = tmp->next;
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
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5), *res;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print(&n1);
    res = s.removeNthFromEnd(&n1, 5);
    print(res);
}
