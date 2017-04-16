#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        ListNode *head = NULL, *tail = NULL;
        while (1)
        {
            multimap<int, int> item;
            vector<ListNode *>::iterator it;
            int i = 0;
            for (it = lists.begin(); it != lists.end();)
            {
                if (*it)
                {
                    item.insert(make_pair((*it)->val, i));
                    ++it;
                    ++i;
                }
                else
                    it = lists.erase(it);
            }
            if (item.size() >= 2)
            {
                int index = item.begin()->second;
                if (head == NULL)
                {
                    head = lists[index];
                    tail = head;
                }
                else
                {
                    tail->next = lists[index];
                    tail = tail->next;
                }
                lists[index] = lists[index]->next;
            }
            else if(item.size() == 1)
            {
                int index = item.begin()->second;
                if (head == NULL)
                    head = lists[index];
                else
                    tail->next = lists[index];
                return head;
            }
            else
            {
                return head;
            }
        }
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
    ListNode n1(2), n2(-1), n3(199), *res;
    vector<ListNode *> lists;
    lists.push_back(&n1);
    lists.push_back(NULL);
    lists.push_back(&n2);
    lists.push_back(&n3);
    print(&n1);
    print(&n2);
    res = s.mergeKLists(lists);
    print(res);
}
