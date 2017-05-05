#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> num = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.size() == 0)
            return res;
        res.push_back("");
        for (int i = 0; i < digits.size(); ++i)
        {
            string tmp = num[digits[i] - '0'];
            if (tmp.size() == 0)
                continue;
            vector<string> now;
            for (int j = 0; j < res.size(); ++j)
            {
                for (int k = 0; k < tmp.size(); ++k)
                {
                    now.push_back(res[j] + tmp[k]);
                }
            }
            swap(now, res);
        }
        for (int i = 0; i < res.size(); ++i)
            cout << res[i] << " ";
        cout << endl;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    s.letterCombinations("23");
    return 0;
}
