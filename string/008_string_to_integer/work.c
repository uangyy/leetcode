#include <stdio.h>

int myAtoi(char* str) {
    int flag = -1;
    int c = 0, res = 0;
    int flow = -214748364;
    if (!str || str[0] == 0)
        goto err;
    while (str[0] == ' ') ++str;
    while (str[c] && str[c] != ' ')
    {
        if (str[c] == '+' || str[c] == '-')
        {
            if (c == 0)
                flag = str[c] - 44;
            else
                goto err;
        }
        else if (str[c] >= '0' && str[c] <= '9')
        {
            int tmp = str[c] - '0';
            if (!tmp && !res)
            {
                ++c;
                continue;
            }
            if (res < flow)
                goto overflow;
            res = res * 10 - tmp;
            if (res > 0)
                goto overflow;
        }
        else
            goto err;
        ++c;
    }

    if (flag == - 1 && res == 0x80000000)
        goto overflow;
    return res * flag;
err:
    return flag * res;
overflow:
    if (flag == 1)
        return 0x80000000;
    else
        return 0x7fffffff;
}

int main(int argc, char **argv)
{
    printf("%d\n", myAtoi("2147483648"));
    printf("%d\n", myAtoi("-2147483648"));
    printf("%d\n", myAtoi("-2147483649"));
    printf("%d\n", myAtoi("+11191657170"));
    printf("%d\n", myAtoi("10522545459"));
    printf("%d\n", myAtoi("-2147483647"));
    printf("%d\n", myAtoi("1a"));
    return 0;
}
