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

    vector<int> get_next(string str)
    {
        vector<int> next(str.size(), -1);
        for (int i = 1; i < str.size(); ++i)
        {
            int tmp = next[i - 1];
            while (1)
            {
                if (str[i] == str[tmp + 1])
                {
                    next[i] = tmp + 1;
                    break;
                }
                if (tmp == -1)
                    break;
                tmp = next[tmp];
            }
        }
        return next;
    }

    int strStr_KMP(string haystack, string needle) {
        vector<int> next = get_next(needle);
        int i = 0, j = 0;
        for (; i < haystack.size() && j < needle.size();)
        {
            if (haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                if (j == 0)
                    i++;
                else
                    j = next[j - 1] + 1;
            }
        }
        if (j == needle.size())
            return i - j;
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
