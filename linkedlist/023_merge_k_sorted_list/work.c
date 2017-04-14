#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define swap(a, b) do{\
    struct ListNode *tmp = *(a);\
    *(a) = *(b);\
    *(b) = tmp;\
} while(0)

void make_heap(struct ListNode **arr, int size);
void heapify(struct ListNode **arr, int i, int size);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize <= 0)
        return NULL;
    int i, count = 0;
    struct ListNode *heap[listsSize], *res = NULL, *tail = NULL;
    for (i = 0; i < listsSize; ++i)
    {
        if (lists[i])
            heap[count++] = lists[i];
    }

    make_heap(heap, count);
    while (count)
    {
        if (!res)
        {
            res = heap[0];
            tail = res;
        }
        else
        {
            tail->next = heap[0];
            tail = tail->next;
        }
        heap[0] = heap[0]->next;

        if (!heap[0])
        {
            swap(heap, heap + count - 1);
            count--;
        }
        heapify(heap, 1, count);
    }

    return res;
}

void make_heap(struct ListNode **arr, int size)
{
    int mid = size / 2;
    for (; mid > 0; --mid)
    {
        heapify(arr, mid, size);
    }
}

void heapify(struct ListNode **arr, int i, int size)
{
    int l = i * 2, r = i * 2 + 1, min = i;
    if (l <= size && arr[l - 1]->val < arr[i - 1]->val)
        min = l;
    if (r <= size && arr[r - 1]->val < arr[min - 1]->val)
        min = r;
    if (min != i)
    {
        swap(arr + min - 1, arr + i - 1);
        heapify(arr, min, size);
    }
}

void print(struct ListNode *head)
{
    while (head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode *reverse(struct ListNode *start, struct ListNode *end)
{
    if (!start)
        return start;
    struct ListNode *tail = start, *current = start->next;
    while (current != end)
    {
        tail->next = current->next;
        current->next = start;
        start = current;
        current = tail->next;
    }
    return start;
}

int main(int argc, char **argv)
{
    /*
    struct ListNode n5 = {5, NULL},
                    n4 = {4, &n5},
                    n3 = {3, &n4},
                    n2 = {2, &n3},
                    n1 = {1, &n2},
                    n8 = {8, NULL},
                    n7 = {7, &n8},
                    n6 = {6, &n7};
                    */
    struct ListNode n1 = {0, NULL},
                    n2 = {-2, &n1},

                    n3 = {6, NULL},
                    n4 = {5, &n3},
                    n5 = {-2, &n4},

                    n6 = {5, NULL},
                    n7 = {4, &n6},
                    n8 = {1, &n7},
                    n9 = {-2, &n8};

    struct ListNode *res, *arr[10];

    arr[0] = &n9;
    arr[1] = &n5;
    arr[2] = &n2;

    print(arr[0]);
    print(arr[1]);
    print(arr[2]);
    res = mergeKLists(arr, 3);
    print(res);
    //res = reverse(res, NULL);
    //print(res);
    return 0;
}
