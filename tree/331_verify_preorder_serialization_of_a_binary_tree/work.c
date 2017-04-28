#include <stdio.h>

#define bool int
#define true 1
#define false 0

bool isValidSerialization(char* preorder) {
    int i = 0, j = 0;
    char l = ',';
    for (; *preorder; l = *preorder, ++preorder){
        if (*preorder == '#') ++j;
        else if (*preorder == ',') ;
        else if (l == ',' || l == '#') ++i;
        if (j - 1 == i) break;
    }
    return j - 1 == i && *preorder && !*(preorder + 1) ? true : false;
}

int main(int argc, char **argv)
{
    //char *str = "9##";
    //char *str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    char *str = "9,#,92,#,#";
    bool res;
    res = isValidSerialization(str);
    printf("%d\n", res);
    return 0;
}
