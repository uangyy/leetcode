#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
    vector<TreeNode *> stack;
    TreeNode *current;
    BSTIterator(TreeNode *root) {
        current = root;
        while (current)
        {
            stack.push_back(current);
            current = current->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty() || current;
    }

    /** @return the next smallest number */
    int next() {
        current = *stack.rbegin();
        stack.pop_back();
        int res = current->val;
        current = current->right;
        while (current)
        {
            stack.push_back(current);
            current = current->left;
        }
        return res;
    }
};

/*
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(4);
    n2.left = &n1;
    n2.right = &n3;
    n3.right = &n4;
    BSTIterator i = BSTIterator(&n2);
    while (i.hasNext())
        cout << i.next() << " ";
    cout << endl;
    return 0;
}
