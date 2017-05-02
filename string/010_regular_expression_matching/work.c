#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0

bool isMatch_(char* s, char* p) {
    int i = 0, j = 0;
    char pre = -1;
    if (!s && !p)
        return true;
    if (!s)
        return false;
    if (!p || p[0] == '*')
        return false;

    while (s[i] && p[j])
    {
        if (p[j] == '*')
        {
            while (s[i] && (s[i] == pre || pre == '.'))
                ++i;
            ++j;
        }
        else if (p[j] == '.')
        {
            pre = '.';
            ++i;
            ++j;
        }
        else
        {
            if (s[i] != p[j])
                if (p[j + 1] && p[j + 1] != '*' || !p[j + 1])
                    return false;
                else
                {
                    j += 2;
                    continue;
                }
            pre = s[i];
            ++i;
            ++j;
        }
    }
    if (p[j] == '*')
        j++;
    if (!s[i] && !p[j])
        return true;
    else
        return false;
}

bool isMatch(char* s, char* p) {
    if (!p[0])
        return !s[0];

    if ('*' == p[1])
        return isMatch(s, p + 2) || s[0] && (s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p);
    else
        return s[0] && (s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p + 1);
}

bool isMatch_dp(char *s, char *p)
{
    /*
     * F[i][j] : if s[0...i-1] matches p[0...j-1]
     */
    int s_len = 0, p_len = 0;
    while (s[s_len]) s_len++;
    while (p[p_len]) p_len++;
    int **F = malloc(sizeof(int *) * (s_len + 1)), i, j;
    for (i = 0; i <= s_len; ++i)
    {
        F[i] = malloc(sizeof(int) * (p_len + 1));
        memset(F[i], 0, sizeof(int) * (p_len + 1));
    }

    F[0][0] = true;
    for (j = 1; j <= p_len; ++j)
    {
        F[0][j] = j > 1 && p[j - 1] == '*' && F[0][j - 2];
    }
    
    for (i = 1; i <= s_len; ++i)
    {
        for (j = 1; j <= p_len; ++j)
        {
            if (p[j - 1] != '*')
            {
                if ((s[i - 1] == p[j - 1] || p[j - 1] == '.') &&  F[i - 1][j - 1])
                    F[i][j] = true;
            }
            else
            {
                if (F[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && F[i - 1][j])
                    F[i][j] = true;
            }
        }
    }
    bool res = F[s_len][p_len];
    for (i = 0; i < s_len; ++i)
    {
        free(F[i]);
    }
    free(F);
    return  res;
}

int main(int argc, char **argv)
{
    printf("%d\n", isMatch_dp("aa", "a"));
    printf("%d\n", isMatch_dp("aa", "aa"));
    printf("%d\n", isMatch_dp("aaa", "aa"));
    printf("%d\n", isMatch_dp("aa", "a*"));
    printf("%d\n", isMatch_dp("aa", ".*"));
    printf("%d\n", isMatch_dp("ab", ".*"));
    printf("%d\n", isMatch_dp("aab", "c*a*b*"));
    printf("%d\n", isMatch_dp("aaa", ".*a"));
    return 0;
}
