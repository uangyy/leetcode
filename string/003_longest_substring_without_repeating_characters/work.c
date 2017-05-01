#include <stdio.h>
#include <string.h>

#include <inttypes.h>

int lengthOfLongestSubstring(char* s) {
    int m = 0, tmp = 0, start = 0, current;
    long long arr[256];
    for (current = 0; current < 256; ++current)
        arr[current] = -1;

    for (current = 0; s[current]; ++current)
    {
        if (arr[s[current]] == -1 || arr[s[current]] < start)
        {
            arr[s[current]] = current;
            tmp++;
            if (tmp > m)
                m = tmp;
        }
        else
        {
            start = arr[s[current]] + 1;
            arr[s[current]] = current;
            tmp = current - start + 1;
        }
    }
    return m;
}

#define max(a, b)\
    (a) > (b) ? (a) : (b)

int lengthOfLongestSubstring_2(char *s)
{
    int i, j, set[256], res = 0;
    memset(set, 0, sizeof(set));
    for (i = 0, j = 0; s[j];)
    {
        if (!set[s[j]])
        {
            set[s[j]] = 1;
            ++j;
            res = max(j - i, res);
        }
        else
        {
            for (; s[i] != s[j]; ++i)
            {
                set[s[i]] = 0;
            }
            set[s[i++]] = 0;
        }
    }
    return res;
}

int main(int argc, char **argv)
{
    char *str = "abcabcbb";
    int res = lengthOfLongestSubstring_2(str);
    printf("%d\n", res);
    return 0;
}
