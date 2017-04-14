#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre = NULL, *first, *second;
        if (!head || !head->next)
            return head;
        first = head;
        head = head->next;
        while (first)
        {
            ListNode *tmp;
            second = first->next;
            if (!second)
                break;
            tmp = second->next;
            second->next = first;
            first->next = tmp;
            if (pre)
                pre->next = second;
            pre = first;
            first = first->next;
        }
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
    res = s.swapPairs(&n1);
    print(res);
}
