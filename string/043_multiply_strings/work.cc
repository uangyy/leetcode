#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res(num1.size() + num2.size(), 0), n1(num1.size()), n2(num2.size());
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            n1[i] = num1[i] - '0';
        }
        for (int i = num2.size() - 1; i >= 0; --i)
        {
            n2[i] = num2[i] - '0';
        }
        for (int i = n2.size() - 1; i >= 0; --i)
        {
            vector<int> tmp(n1.size(), 0);
            for (int j = n1.size() - 1; j >= 0; --j)
            {
                tmp[j] = n1[j] * n2[i];
            }
            int jump = n2.size() - 1 - i;
            for (int j = tmp.size() - 1; j >= 0; --j)
            {
                res[res.size() - 1 - jump - (tmp.size() - 1 - j)] += tmp[j];
            }
            tmp.clear();
        }
        int up = 0;
        for (int i = res.size() - 1; i >= 0; --i)
        {
            res[i] += up;
            up = res[i] / 10;
            res[i] = res[i] % 10;
        }
        string output = "";
        int flag = 0;
        for (int i = 0; i < res.size(); ++i)
        {
            if (res[i] == 0 && flag == 0)
                continue;
            else
                flag = 1;
            output += res[i] + '0';
        }
        return output.size() == 0 ? "0" : output;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.multiply("4232321", "31321329") << endl;;
    cout << s.multiply("4232321", "31321329") << endl;;
    return 0;
}
