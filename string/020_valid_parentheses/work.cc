#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0)
            return true;
        if (s.size() % 2 == 1)
            return false;
        stack<char> st;

        for (int i = 0; i < s.size(); ++i)
        {
            switch(s[i])
            {
                case '(':
                case '[':
                case '{': st.push(s[i]); break;
                case ')': if (st.empty() || st.top() != '(') return false; else st.pop(); break;
                case ']': if (st.empty() || st.top() != '[') return false; else st.pop(); break;
                case '}': if (st.empty() || st.top() != '{') return false; else st.pop(); break;
                default: ;
            }
        }
        return st.empty();
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("([)]") << endl;
    return 0;
}
