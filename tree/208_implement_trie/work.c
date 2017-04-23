#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define false 0
#define true 1

typedef struct Trie{
    char val;
    int count;
    struct Trie *child[26];
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {

    Trie *trie = malloc(sizeof(Trie));
    if (!trie)
        return NULL;
    memset(trie, 0, sizeof(Trie));
    return trie;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
    while (*word)
    {
        if (!obj->child[*word - 'a'])
            break;
        obj = obj->child[*word - 'a'];
        ++word;
    }

    while (*word)
    {
        Trie *node = malloc(sizeof(Trie));
        if (!node)
            return;
        memset(node, 0, sizeof(Trie));
        node->val = *word;
        obj->child[*word - 'a'] = node;
        obj = node;
        ++word;
    }

    obj->count++;
    return;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
    while (*word)
    {
        if (!obj->child[*word - 'a'])
            break;
        obj = obj->child[*word - 'a'];
        ++word;
    }
    if (!*word && obj->count)
        return true;
    else
        return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
    while (*prefix)
    {
        if (!obj->child[*prefix - 'a'])
            break;
        obj = obj->child[*prefix - 'a'];
        ++prefix;
    }
    if (!*prefix)
        return true;
    else
        return false;
}

void trieFree(Trie* obj) {
    if (!obj)
        return;
    int i;
    for (i = 0; i < 26; ++i)
        trieFree(obj->child[i]);
    free(obj);
}

/*
 * Your Trie struct will be instantiated and called as such:
 * struct Trie* obj = trieCreate();
 * trieInsert(obj, word);
 * bool param_2 = trieSearch(obj, word);
 * bool param_3 = trieStartsWith(obj, prefix);
 * trieFree(obj);
 */

int main(int argc, char **argv)
{
    struct Trie *obj = trieCreate();
    char *str = "hello";
    bool res;
    trieInsert(obj, str);
    res = trieSearch(obj, "hello");
    printf("%d\n", res);
    res = trieSearch(obj, "helloa");
    printf("%d\n", res);
    res = trieStartsWith(obj, "hello");
    printf("%d\n", res);
    trieFree(obj);
    return 0;
}
