/*************************************************************************
	> File Name: twoSumII.cc
	> Author: uangyy
	> Mail:uangyy@gmail.com 
	> Created Time: Wed 03 Jun 2015 12:45:00 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        map<int, int> m;
        map<int,int>::iterator ite1, ite2;
        for(int i = 0; i < nums.size(); i++)
        {
            if((ite1 = m.find(nums[i])) == m.end())
            {
                ite1 = (m.insert(make_pair(nums[i], i+1))).first;
            }
            else
            {
                if(nums[i] * 2 == target)
                {
                    ret.push_back(ite1->second);
                    ret.push_back(i+1);
                    return ret;
                }
            }
            if((ite2 = m.find(target - nums[i])) != m.end() && ite2 != ite1)
            {
                if(ite1->second < ite2->second)
                {
                    ret.push_back(ite1->second);
                    ret.push_back(ite2->second);
                }
                else
                {
                    ret.push_back(ite2->second);
                    ret.push_back(ite1->second);
                }
                return ret;
            }
        }
        ret.push_back(0);
        return ret;
    }
};
