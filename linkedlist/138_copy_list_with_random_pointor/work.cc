#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> m;
        RandomListNode *res = NULL, *tail;
        while (head)
        {
            RandomListNode *random = head->random;
            if (m.find(head) == m.end())
            {
                RandomListNode *tmp = new RandomListNode(head->label);
                m[head] = tmp;
            }
            if (random && m.find(random) == m.end())
            {
                RandomListNode *tmp = new RandomListNode(random->label);
                m[random] = tmp;
            }

            if (!res)
            {
                res = m[head];
                if (random)
                    res->random = m[random];
                tail = res;
            }
            else
            {
                tail->next = m[head];
                tail = tail->next;
                if (random)
                    tail->random = m[random];
            }
            head = head->next;
        }
        return res;
    }
};

void print(RandomListNode *head)
{
    RandomListNode *current = head;
    while (current)
    {
        cout << current->label << " ";
        current = current->next;
    }
    cout << endl;

    current = head;
    while (current)
    {
        if (current->random)
            cout << current->label << "-->" << current->random->label << endl;
        else
            cout << current->label << "-->" << "NULL" << endl;
        current = current->next;
    }
}

int main(int argc, char **argv)
{
    Solution s;
    RandomListNode n5(5), n4(4), n3(3), n2(2), n1(1);
    n1.next = &n2, n2.next = &n3, n3.next = &n4, n4.next = &n5;
    n1.random = &n2, n2.random = &n4, n3.random = &n1, n4.random = &n5;

    print(&n1);
    RandomListNode *res;
    res = s.copyRandomList(&n1);
    cout << "----------" << endl;
    print(res);
    return 0;
}
