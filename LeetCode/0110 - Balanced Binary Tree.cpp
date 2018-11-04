/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int recurse(TreeNode* t) {
        if (t == nullptr) {
            return 0;
        }
        const int d1 = recurse(t->left);
        const int d2 = recurse(t->right);
        if ((d1 == -1) || (d2 == -1)) {
            return -1;
        }
        if ((d1 < d2 - 1) || (d2 < d1 - 1)) {
            return -1;
        }
        return 1 + max(d1, d2);
    }

    bool isBalanced(TreeNode* root) {
        return recurse(root) != -1;
    }
};
