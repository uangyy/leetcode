#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode *pre = head, *current = head->next;
        int pre_val = head->val;
        while (current)
        {
            if (current->val == pre_val)
            {
                pre->next = current->next;
            }
            else
            {
                pre_val = current->val;
                pre = current;
            }
            current = current->next;
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
    ListNode n1(1), n2(1), n3(3), n4(4), *res;
    Solution s;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    print(&n1);
    res = s.deleteDuplicates(&n1);
    print(res);
}
