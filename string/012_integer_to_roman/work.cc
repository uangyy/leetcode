#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> u_map;
        u_map[1] = "IV";
        u_map[2] = "XL";
        u_map[3] = "CD";
        u_map[4] = "M";
        int base = 1;
        string res;
        while (num)
        {
            string unit = u_map[base], h_unit = u_map[base + 1];
            int one = num % 10;
            if (one == 9)
            {
                res += h_unit[0];
                res += unit[0];
            }
            else if (one >= 5)
            {
                while (one-- > 5)
                {
                    res += unit[0];
                }
                res += unit[1];
            }
            else if (one == 4)
            {
                res += unit[1];
                res += unit[0];
            }
            else
                while (one-- > 0)
                {
                    res += unit[0];
                }
            num /= 10;
            ++base;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    string res = s.intToRoman(3684);
    cout << res << endl;
    res = s.intToRoman(9);
    cout << res << endl;
    return 0;
}
