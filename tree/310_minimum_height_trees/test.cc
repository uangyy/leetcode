#include <iostream>
#include <vector>

using namespace std;

void preorder_traversal(int (*arr)[4], int l, int k, int n)
{
    if (k > n)
        return;
    cout << k << " ";
    for (int i = 0; i <= n; ++i)
    {
        if (arr[k][i] && i != l)
        {
            preorder_traversal(arr, k, i, n);
        }
    }
}

int get_height(int (*arr)[4], int l, int k, int n)
{
    if (k > n)
        return 0;
    int *arr_height = new int[n + 1];
    for (int i = 0; i <= n; ++i)
        arr_height[i] = 0;

    for (int i = 0; i <= n; ++i)
    {
        if (arr[k][i] && i != l)
        {
            arr_height[i] = get_height(arr, k, i, n);
        }
    }
    int res = -1;
    for (int i = 0; i <= n; ++i)
    {
        if (arr_height[i] > res)
            res = arr_height[i];
    }
    delete []arr_height;
    return res + 1;
}

void preorder_traversal_nonrec(int (*arr)[4], int k, int n)
{
}

void postorder_traversal(int (*arr)[4], int l, int k, int n)
{
    if (k > n)
        return;
    for (int i = 0; i <= n; ++i)
    {
        if (arr[k][i] && i != l)
        {
            postorder_traversal(arr, k, i, n);
        }
    }
    cout << k << " ";
}

int main(int argc, char **argv)
{
    int graph[][4] = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
    };

    preorder_traversal(graph, -1, 0, 3);
    cout << endl;
    preorder_traversal(graph, -1, 1, 3);
    cout << endl;
    preorder_traversal(graph, -1, 2, 3);
    cout << endl;
    preorder_traversal(graph, -1, 3, 3);
    cout << endl;
    preorder_traversal(graph, -1, 4, 3);
    cout << endl;
    postorder_traversal(graph, -1, 0, 3);
    cout << endl;

    cout << get_height(graph, -1, 0, 3) << endl;
    cout << get_height(graph, -1, 1, 3) << endl;
    cout << get_height(graph, -1, 2, 3) << endl;
    cout << get_height(graph, -1, 3, 3) << endl;
    cout << get_height(graph, -1, 4, 3) << endl;
    return 0;
}
