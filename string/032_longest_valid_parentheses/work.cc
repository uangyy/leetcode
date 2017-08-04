#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * F[i] = 
 *      if f(i, ...,  i - m): F[i - 2] + m + 1
 *      else: 0
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> res(s.size(), 0);
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                res[i] = 0;
            }
            else
            {
                int pos = i - 1;
                while (pos && res[pos])
                {
                    pos -= res[pos];
                }
                if (s[pos] == '(')
                    res[i] = i - pos + 1;
            }
        }
        // for (int i = 0; i < s.size(); ++i)
        //     cout << s[i] << " ";
        // cout << endl;
        // for (int i = 0; i < res.size(); ++i)
        //     cout << res[i] << " ";
        // cout << endl;

        int max = 0, sum = 0;
        for (int i = res.size() - 1; i >= 0; )
        {
            if (res[i] == 0)
            {
                sum = 0;
                --i;
            }
            else
            {
                sum += res[i];
                i -= res[i];
                if (sum > max)
                    max = sum;
            }
        }
        return max;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    string str = "()(())";
    str = "())";
    cout << s.longestValidParentheses("()") << endl;
    cout << s.longestValidParentheses(")()())") << endl;
    cout << s.longestValidParentheses("()()") << endl;
    cout << s.longestValidParentheses("(()())") << endl;
    return 0;
}
