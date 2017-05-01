#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int group = numRows * 2 - 2, len = 0, i, c = 0, turns = group / 2 + 1, k = 0;
    if (numRows == 1)
        return s;
    for (; s[len]; ++len) ;
    char *res = malloc(len + 1);
    memset(res, 0, len + 1);

    while (1)
    {
        if (k == turns)
            break;
        for (i = 0; i < len; i += group)
        {
            if (k == 0 ||  k == turns - 1)
            {
                if (i + k < len)
                    res[c++] = s[i + k];
            }
            else
            {
                if (i + k < len)
                    res[c++] = s[i + k];
                if (i + group - k < len)
                    res[c++] = s[i + group - k];
            }
        }
        ++k;
    }
    return res;
}

int main(int argc, char **argv)
{
    char *str = "PAYPALISHIRING", *res;
    res = convert(str, 3);
    printf("%s\n", res);
    return 0;
}
