#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

bool is_palindromic(char *s, int start, int end)
{
    if (end - start < 1)
        return true;
    while (start < end)
    {
        if (s[start] == s[end])
        {
            ++start;
            --end;
        }
        else
            return false;
    }
    return true;
}

char* longestPalindrome(char* s) {
    int i = 0, j = 0, length = 0;
    char *res = malloc(sizeof(char) * 1001);
    for (i = 0; s[i]; ++i)
    {
        for (j = i; s[j]; ++j)
        {
            if (is_palindromic(s, i, j))
            {
                if (j - i + 1 > length)
                {
                    length = j - i + 1;
                    memcpy(res, s + i, j - i + 1);
                    res[j + 1] = 0;
                }
            }
        }
    }
    res[length] = 0;
    return res;
}

char *longestPalindrome_dp(char *s)
{
    int n = 0, i, j;
    for (n = 0; s[n]; ++n) ;
    printf("%d\n", n);
    int F[n][n];
    memset(F, 0, sizeof(int) * n * n);

    for (i = 0; i < n; ++i)
    {
        F[i][i] = 1;
        if (i < n - 1 && s[i] == s[i + 1])
            F[i][i + 1] = 1;
    }

    for (j = 2; j < n; ++j)
    {
        for (i = 0; i < n - j; ++i)
        {
            if (s[i] == s[i + j] && F[i + 1][i + j - 1])
                F[i][i + j] = 1;
            else
                F[i][i + j] = 0;
        }
    }

    int tmp = 0, start, end;
    for (i = 0; i < n; ++i)
    {
        for (j = i; j < n; ++j)
        {
            if (F[i][j] && j - i + 1 > tmp)
            {
                tmp = j - i + 1;
                start = i;
                end = j;
            }
        }
    }
    char *res = malloc(sizeof(char) * (end - start + 2));
    memset(res, 0, end - start + 2);
    memcpy(res, s + start, end - start + 1);
    return res;
}

int main(int argc, char **argv)
{
    char *str = "vommlezel", *res;
    //char *str = "vomm", *res;
    res = longestPalindrome_dp(str);
    printf("%s\n", res);
    return 0;
}
