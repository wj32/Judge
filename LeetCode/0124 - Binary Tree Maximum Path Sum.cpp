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
    pair<int, int> recurse(TreeNode* node) {
        if (node == nullptr) {
            return {0, numeric_limits<int>::min()};
        }
        const auto l = recurse(node->left);
        const auto r = recurse(node->right);
        return {
            node->val + max(max(l.first, 0), max(r.first, 0)),
            max(l.second, max(r.second, node->val + max(l.first, 0) + max(r.first, 0)))
        };
    }

    int maxPathSum(TreeNode* root) {
        return recurse(root).second;
    }
};
