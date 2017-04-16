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
        vector<ListNode *> heap;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                heap.push_back(lists[i]);

        makeHeap(heap);

        ListNode *head = NULL, *tail = NULL;
        while (!heap.empty())
        {
            if (head == NULL)
            {
                head = heap[0];
                tail = head;
            }
            else
            {
                tail->next = heap[0];
                tail = tail->next;
            }
            heap[0] = heap[0]->next;
            if (!heap[0])
            {
                swap(heap[0], heap[heap.size() - 1]);
                heap.pop_back();
            }
            verify_heap(heap, 1);
        }
        return head;
    }

    void makeHeap(vector<ListNode *> &heap)
    {
        for (int i = heap.size() / 2; i > 0; --i)
        {
            verify_heap(heap, i);
        }
    }

    void verify_heap(vector<ListNode *> &heap, int i)
    {
        int l = i * 2, r = i * 2 + 1, min = i;
        if (l <= heap.size() && heap[l - 1]->val < heap[i - 1]->val)
            min = l;
        if (r <= heap.size() && heap[r - 1]->val < heap[min - 1]->val)
            min = r;

        if (min != i)
        {
            swap(heap[i - 1], heap[min - 1]);
            verify_heap(heap, min);
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
