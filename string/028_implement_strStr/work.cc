#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) return 0;
        for (int i = 0; i < m; ++i)
        {
            int j = 0;
            for (; j < n; ++j)
                if (haystack[i + j] != needle[j])
                    break;
            if (j == n)
                return i;
        }
        return -1;
    }

    // m: S中匹配到W第一个字母的位置, i: 当前匹配到的W中的字母的索引
    vector<int> get_next(string str)
    {
        vector<int> next(str.size(), 0);
        next[0] = -1;
        next[1] = 0;
        int cnd = 0;
        for (int i = 2; i < str.size(); )
        {
            if (str[i - 1] == str[cnd])
            {
                next[i] = cnd + 1;
                cnd++;
                i++;
            }
            else if (cnd > 0)
                cnd = next[cnd];
            else
            {
                next[i] = 0;
                i++;
            }
        }
        return next;
    }

    int strStr_KMP(string haystack, string needle) {
        if (!needle.size())
            return 0;
        if (!haystack.size())
            return -1;
        vector<int> next = get_next(needle);
        int m = 0, i = 0;
        for (; m + i < haystack.size(); )
        {
            if (haystack[m + i] == needle[i])
            {
                if (i == needle.size() - 1)
                    return m;
                ++i;
            }
            else if (next[i] > -1)
            {
                m = m + i - next[i];
                i = next[i];
            }
            else
            {
                m = m + i + 1;
                i = 0;
            }
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.strStr_KMP("hello", "ababc") << endl;
    cout << s.strStr_KMP("hello", "hell") << endl;
    cout << s.strStr_KMP("BBCABCDABABCDABCDABDE", "ABCDABD") << endl;
    return 0;
}
