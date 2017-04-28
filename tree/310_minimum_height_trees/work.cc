#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    /*
     * 如果是个链表那么中点就是最低的树，
     * 如果是个图(最小连通)，那么要找最中心的点。
     * 思路：
     *      每次去掉叶子节点，当剩余节点小于等于两个是，则为结果
     */
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> > &edges) {
        map<int, pair<int, set<int> > > graph;
        vector<int> res;
        for (int i = 0; i < n - 1; ++i)
        {
            int k = edges[i].first, l = edges[i].second;
            if (graph.find(k) == graph.end())
            {
                graph[k].first = 1;
                graph[k].second.insert(l);
            }
            else
            {
                graph[k].first++;
                graph[k].second.insert(l);
            }

            if (graph.find(l) == graph.end())
            {
                graph[l].first = 1;
                graph[l].second.insert(k);
            }
            else
            {
                graph[l].first++;
                graph[l].second.insert(k);
            }
        }

        while (1)
        {
            if (graph.size() <= 2)
                break;
            map<int, int> all_neightbor;
            for (map<int, pair<int, set<int> > >::iterator it = graph.begin(); it != graph.end();)
            {
                if (it->second.first == 1)
                {
                    for (set<int>::iterator it_set = it->second.second.begin(); it_set != it->second.second.end(); ++it_set)
                    {
                        graph[*it_set].second.erase(it->first);
                        if (all_neightbor.find(*it_set) == all_neightbor.end())
                        {
                            all_neightbor[*it_set] = 1;
                        }
                        else
                            all_neightbor[*it_set]++;
                    }
                    graph.erase(it++);
                }
                else
                    ++it;
            }
            for (map<int, int>::iterator it_n = all_neightbor.begin(); it_n != all_neightbor.end(); ++it_n)
            {
                graph[it_n->first].first -= it_n->second;
            }
        }

        for (map<int, pair<int, set<int> > >::iterator it = graph.begin(); it != graph.end(); ++it)
        {
            res.push_back(it->first);
        }

        return res;
    }
};

int main(int argc, char **argv)
{
    vector<pair<int, int> > input;
    /*
    input.push_back(make_pair(1,0));
    input.push_back(make_pair(1,2));
    input.push_back(make_pair(1,3));
    */
    input.push_back(make_pair(0,1));
    input.push_back(make_pair(1,5));
    input.push_back(make_pair(1,2));
    input.push_back(make_pair(1,3));
    input.push_back(make_pair(2,4));
    input.push_back(make_pair(3,6));

    Solution s;

    vector<int> res = s.findMinHeightTrees(7, input);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
