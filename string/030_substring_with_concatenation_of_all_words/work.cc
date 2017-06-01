#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() == 0 || s.size() == 0)
            return res;
        int w_len = words[0].size();
        //unordered_set<string> w_set(words.begin(), words.end());
        unordered_map<string, int> word_map, word_store;
        for (string w : words)
        {
            word_store[w] = 0;
        }
        for (string w : words)
        {
            word_store[w]++;
        }
        word_map = word_store;
        string word;
        for (int i = 0; i + (w_len * words.size()) - 1 < s.size(); ++i)
        {
            int j;
            for (j = 0; j < words.size(); ++j)
            {
                word = s.substr(i + w_len * j, w_len);
                if (word_map.find(word) == word_map.end() || word_map[word] == 0)
                    break;
                else
                {
                    word_map[word]--;
                }
            }
            if (j == words.size())
                res.push_back(i);
            if (j)
                word_map = word_store;
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    string str = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> res;
    res = s.findSubstring(str, words);
    return 0;
}
