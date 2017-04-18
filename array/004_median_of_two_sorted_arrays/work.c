#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len = nums1Size + nums2Size;
    int arr[len], i = 0, j = 0, current = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] < nums2[j])
        {
            arr[current++] = nums1[i++];
        }
        else
        {
            arr[current++] = nums2[j++];
        }
    }
    while (i < nums1Size)
    {
        arr[current++] = nums1[i++];
    }
    while (j < nums2Size)
    {
        arr[current++] = nums2[j++];
    }

    if (len % 2 == 1)
    {
        return arr[(len - 1) / 2];
    }
    else
    {
        int mid = (len - 1) / 2;
        return (double)(arr[mid] + arr[mid + 1]) / 2;
    }
}

int main(int argc, char **argv)
{
    int arr1[] = {1, 3, 4, 5, 6, 7, 8},
        arr2[] = {2, 3, 4, 5, 7};
    double res;
    res = findMedianSortedArrays(arr1, 7, arr2, 5);
    printf("%f\n", res);
    return 0;
}
