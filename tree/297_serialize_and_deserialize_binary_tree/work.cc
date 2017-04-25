#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

    int get_heigh(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(get_heigh(root->left), get_heigh(root->right));
    }

    void fix_res(string &res)
    {
        while (res[res.size() - 1] == 'n' || res[res.size() - 1] == ',')
            res.resize(res.size() - 1);
        res += "]";
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> level_nodes;
        string res = "[";
        int heigh = get_heigh(root), level = 0;
        if (!root)
        {
            res += "]";
            return res;
        }

        level_nodes.push(root);
        ostringstream os;
        os << root->val;
        res += os.str() + ",";
        while (!level_nodes.empty())
        {
            level++;
            int level_size = level_nodes.size();
            TreeNode *node;
            if (level < heigh)
                while (level_size--)
                {
                    node = level_nodes.front();
                    level_nodes.pop();
                    if (node->left)
                    {
                        level_nodes.push(node->left);
                        os.str("");
                        os << node->left->val;
                        res += os.str() + ",";
                    }
                    else
                    {
                        res += "n,";
                    }

                    if (node->right)
                    {
                        level_nodes.push(node->right);
                        os.str("");
                        os << node->right->val;
                        res += os.str() + ",";
                    }
                    else
                    {
                        res += "n,";
                    }
                }
            else
                break;
        }

        fix_res(res);

        return res;
    }

    string get_token(string &str)
    {
        string res;
        int start = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == '[')
                ++start;
            else if (str[i] == ',' || str[i] == ']')
            {
                ++start;
                break;
            }
            else
            {
                res += str[i];
                ++start;
            }
        }
        str = str.substr(start, str.size() - start);
        return res;
    }

    int str_to_int(const string str)
    {
        istringstream is(str);
        int val;
        is >> val;
        return val;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]")
            return NULL;
        queue<TreeNode *> last_level_nodes;
        string token = get_token(data);
        int val, size_count;
        val = str_to_int(token);
        TreeNode *root = new TreeNode(val);
        last_level_nodes.push(root);
        while (data.size())
        {
            size_count = last_level_nodes.size();
            int del = 0;
            while (size_count)
            {
                token = get_token(data);
                if (token == "n")
                {
                    if (del % 2)
                    {
                        size_count--;
                        last_level_nodes.pop();
                    }
                    ++del;
                }
                else if (token == "")
                {
                    break;
                }
                else
                {
                    val = str_to_int(token);
                    TreeNode *tmp = last_level_nodes.front();
                    TreeNode *new_node = new TreeNode(val);
                    last_level_nodes.push(new_node);
                    if (del % 2)
                    {
                        tmp->right = new_node;
                        size_count--;
                        last_level_nodes.pop();
                    }
                    else
                    {
                        tmp->left = new_node;
                    }
                    ++del;
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, char **argv)
{
    TreeNode n1(11), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.left = &n5;

    Codec codec;
    string res = codec.serialize(&n1);
    cout << res << endl;
    TreeNode *tree = codec.deserialize(res);
    return 0;
}
