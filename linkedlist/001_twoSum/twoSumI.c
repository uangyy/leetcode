/*************************************************************************
	> File Name: twoSumI.c
	> Author: uangyy
	> Mail:uangyy@gmail.com 
	> Created Time: Tue 02 Jun 2015 09:37:44 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    int index;
};

int cmp(const void *a, const void *b)
{
    return ((struct Node*)a)->val - ((struct Node*)b)->val;
}
int *twoSum(int *nums, int numsSize, int target)
{
    struct Node *arr = calloc(numsSize, sizeof(struct Node));

    int i = 0, j = numsSize - 1;
    int *ret = calloc(2, sizeof(int));
    for( ; i < numsSize; ++i)
    {
        arr[i].val = nums[i];
        arr[i].index = i +  1;
    }
    qsort(arr, numsSize, sizeof(struct Node), cmp);
    i = 0;
    while(i < j)
    {
        if(arr[i].val + arr[j].val == target)
        {
            if(arr[i].index < arr[j].index)
            {
                ret[0] = arr[i].index;
                ret[1] = arr[j].index;
            }
            else
            {
                ret[0] = arr[j].index;
                ret[1] = arr[i].index;
            }
            return ret;
        }
    else if(arr[i].val + arr[j].val > target)
        j--;
    else
        i++;
    }
}
