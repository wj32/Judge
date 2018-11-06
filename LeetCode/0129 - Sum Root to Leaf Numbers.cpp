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
            return {0, 0};
        }
        if ((node->left == nullptr) && (node->right == nullptr)) {
            return {1, node->val};
        }
        const auto l = recurse(node->left);
        const auto r = recurse(node->right);
        const auto p = (l.first + r.first) * 10;
        return {p, l.second + r.second + (node->val * p)};
    }

    int sumNumbers(TreeNode* root) {
        return recurse(root).second;
    }
};
