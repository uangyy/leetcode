#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int n, vector<pair<int, int> > &edges)
    {
        vector<vector<int> > res;
        for (int i = 0; i < n; ++i)
        {
            vector<int> row(n, 0);
            res.push_back(row);
        }

        for (int i = 0; i < edges.size(); ++i)
        {
            res[edges[i].first][edges[i].second] = 1;
            res[edges[i].second][edges[i].first] = 1;
        }
        return res;
    }

    int get_height(vector<vector<int> > &graph, int l, int k, int n)
    {
        if (l == n)
            return 1;
        vector<int> child_height;
        for (int i = 0; i < n; ++i)
        {
            if (graph[k][i] && i != l)
            {
                child_height.push_back(get_height(graph, k, i, n));
            }
        }
        int m = 0;
        for (int i = 0; i < child_height.size(); ++i)
        {
            if (child_height[i] > m)
                m = child_height[i];
        }
        return 1 + m;
    }

    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<int> res, trees;
        vector<vector<int> > graph = generate(n, edges);
        for (int i = 0; i < n; ++i)
        {
            int height = get_height(graph, -1, i, n);
            trees.push_back(height);
        }

        int this_height = n;
        for (int i = 0; i < trees.size(); ++i)
        {
            if (trees[i] < this_height)
            {
                res.clear();
                res.push_back(i);
                this_height = trees[i];
            }
            else if (trees[i] == this_height)
                res.push_back(i);
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    vector<pair<int, int> > input;
    input.push_back(make_pair(1,0));
    input.push_back(make_pair(1,2));
    input.push_back(make_pair(1,3));

    Solution s;

    vector<int> res = s.findMinHeightTrees(4, input);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
