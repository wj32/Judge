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
    pair<int, int> recurse(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        const auto l = recurse(root->left);
        const auto r = recurse(root->right);
        return {
            root->val + l.second + r.second,
            max(l.first, l.second) + max(r.first, r.second)
        };
    }

    int rob(TreeNode* root) {
        const auto r = recurse(root);
        return max(r.first, r.second);
    }
};
