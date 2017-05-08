#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void work(vector<string> &res, string tmp, int i, int j, int n)
    {
        if (i == n)
        {
            while (j < n)
            {
                tmp += ')';
                ++j;
            }
            res.push_back(tmp);
            return;
        }
        
        work(res, tmp + "(", i + 1, j, n);
        if (j < i)
            work(res, tmp + ")", i, j + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        int i = 0, j = 0;
        vector<string> res;
        string tmp = "";
        work(res, tmp, i, j, n);
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
