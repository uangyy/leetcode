#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    /*
     *  利用后序遍历，将根节点到目标节点的路径保存下来
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> stack1, stack2;
        TreeNode *current = root, *last;
        if (!root)
            return NULL;
        bool flag1 = false, flag2 = false;

        last = NULL;
        while (current)
        {
            stack1.push_back(current);
            if (current->val == p->val)
                break;
            current = current->left;
        }
        if (!current)
        {
            while (!stack1.empty())
            {
                current = *stack1.rbegin();
                if (!current->right || current->right == last)
                {
                    stack1.pop_back();
                    last = current;
                }
                else
                {
                    current = current->right;
                    while (current)
                    {
                        stack1.push_back(current);
                        if (current->val == p->val)
                            break;
                        current = current->left;
                    }
                    if (current)
                        break;
                }
            }
        }

        current = root;
        last = NULL;
        while (current)
        {
            stack2.push_back(current);
            if (current->val == q->val)
                break;
            current = current->left;
        }
        if (!current)
        {
            while (!stack2.empty())
            {
                current = *stack2.rbegin();
                if (!current->right || current->right == last)
                {
                    stack2.pop_back();
                    last = current;
                }
                else
                {
                    current = current->right;
                    while (current)
                    {
                        stack2.push_back(current);
                        if (current->val == q->val)
                            break;
                        current = current->left;
                    }
                    if (current)
                        break;
                }
            }
        }
        if (stack1.size() < stack2.size())
        {
            for (int i = 0; i < stack1.size(); ++i)
            {
                if (stack1[i] != stack2[i])
                    return stack1[i - 1];
                else if (i == stack1.size() - 1)
                    return stack1[i];
            }
        }
        else
        {
            for (int i = 0; i < stack2.size(); ++i)
            {
                if (stack2[i] != stack1[i])
                    return stack2[i - 1];
                else if (i == stack2.size() - 1)
                    return  stack2[i];
            }
        }
    }
};

int main(int argc, char **argv)
{
    TreeNode n6(6),
             n2(2),
             n8(8),
             n0(0),
             n4(4),
             n3(3),
             n5(5),
             n7(7),
             n9(9),
             n1(1),
             *res;
    /*
    n6.left = &n2;
    n6.right = &n8;
    n2.left = &n0;
    n2.right = &n4;
    n4.left = &n3;
    n4.right = &n5;
    n8.left = &n7;
    n8.right = &n9;

    Solution s;
    res = s.lowestCommonAncestor(&n6, &n2, &n8);
    cout << res->val << endl;
    res = s.lowestCommonAncestor(&n6, &n2, &n4);
    cout << res->val << endl;
    */
    n5.left = &n3;
    n5.right = &n6;
    n3.left = &n2;
    n3.right = &n4;
    n2.left = &n1;
    Solution s;
    res = s.lowestCommonAncestor(&n5, &n1, &n3);
    cout << res->val << endl;
    return 0;
}
