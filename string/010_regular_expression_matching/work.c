#include <stdio.h>
#define bool int
#define true 1
#define false 0

bool isMatch(char* s, char* p) {
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

int main(int argc, char **argv)
{
    printf("%d\n", isMatch("aa", "a"));
    printf("%d\n", isMatch("aa", "aa"));
    printf("%d\n", isMatch("aaa", "aa"));
    printf("%d\n", isMatch("aa", "a*"));
    printf("%d\n", isMatch("aa", ".*"));
    printf("%d\n", isMatch("ab", ".*"));
    printf("%d\n", isMatch("aab", "c*a*b*"));
    return 0;
}
