#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Trie{
    char val;
    int count;
    int refer;
    struct Trie *child[26];
};

struct Trie *createTrie(void)
{
    struct Trie *root = malloc(sizeof(struct Trie));
    if (!root)
        return NULL;
    memset(root, 0, sizeof(struct Trie));
    return root;
}

int trieInsert(struct Trie *obj, char *word)
{
    int res = 0;
    while (*word)
    {
        if (obj->child[*word - 'a'])
        {
            obj = obj->child[*word - 'a'];
            obj->refer++;
        }
        else
            break;
        ++word;
        ++res;
    }

    while (*word)
    {
        struct Trie *node = malloc(sizeof(struct Trie));
        memset(node, 0, sizeof(struct Trie));
        node->val = *word;
        node->refer++;
        obj->child[*word - 'a'] = node;
        obj = node;
        ++word;
        ++res;
    }
    obj->count++;
    return res;
}

char *get_longest(struct Trie *obj, int strsSize, char *word)
{
    int length = 0;
    char *res;
    char *str = word;
    while (*word)
    {
        if (obj->child[*word - 'a']->refer == strsSize)
        {
            obj = obj->child[*word - 'a'];
            length++;
        }
        else
            break;
        ++word;
    }

    res = malloc(length + 1);
    memset(res, 0, length + 1);
    memcpy(res, str, length);
    return res;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";
    if (strsSize == 1)
        return strs[0];
    struct Trie *root = createTrie();
    int i, m = 0;
    char *res, *long_str;
    for (i = 0; i < strsSize; ++i)
    {
        int tmp = trieInsert(root, strs[i]);
        if (tmp == 0)
            return "";
        if (tmp > m)
        {
            m = tmp;
            long_str = strs[i];
        }
    }

    res = get_longest(root, strsSize, long_str);
    return res;
}


int main(int argc, char **argv)
{
    char *input[2] = {
        "",
        "",
        //"hiw"
    };
    char *res = longestCommonPrefix(input, 2);
    printf("%s\n", res);
    return 0;
}
