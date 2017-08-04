#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "", last = "1";
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < last.size(); )
            {
                if (last[j] == '1')
                {
                    if (j + 2 < last.size() && last[j + 2] == '1' && last[j + 1] == '1')
                    {
                        res += "31";
                        j += 3;
                    }
                    else if(j + 1 < last.size() && last[j + 1] == '1')
                    {
                        res += "21";
                        j += 2;
                    }
                    else
                    {
                        res += "11";
                        j += 1;
                    }
                }
                else if(last[j] == '2')
                {
                    if (j + 2 < last.size() && last[j + 2] == '2' && last[j + 1] == '2')
                    {
                        res += "32";
                        j += 3;
                    }
                    else if(j + 1 < last.size() && last[j + 1] == '2')
                    {
                        res += "22";
                        j += 2;
                    }
                    else
                    {
                        res += "12";
                        j += 1;
                    }
                }
                else
                {
                    if (j + 2 < last.size() && last[j + 2] == '3' && last[j + 1] == '3')
                    {
                        res += "33";
                        j += 3;
                    }
                    else if(j + 1 < last.size() && last[j + 1] == '3')
                    {
                        res += "23";
                        j += 2;
                    }
                    else
                    {
                        res += "13";
                        j += 1;
                    }
                }
            }
            last = res;
            res = "";
        }
        return last;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    for (int i = 1; i <= 6; ++i)
    {
        cout << i << ". " << s.countAndSay(i) << endl;
    }
    return 0;
}
