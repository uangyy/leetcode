#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numTrees(int n) {
    if (n == 0 || n == 1)
        return 1;
    int *G = malloc(sizeof(int) * (n + 1)), i, j;
    memset(G, 0, sizeof(int) * n); 
    G[0] = G[1] = 1;
    for (i = 2; i < n + 1; ++i)
    {   
        int sum = 0;
        for (j = 1; j < i + 1; ++j)
        {   
            sum += G[j - 1] * G[i - j]; 
        }   
        G[i] = sum;
    }   
    i = G[n];
    free(G);
    return i;
}

int main(int argc, char **argv)
{
    int num = numTrees(4);
    printf("%d\n", num);
    return 0;
}
