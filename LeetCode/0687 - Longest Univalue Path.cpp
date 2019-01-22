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
    struct Result {
        int longest;
        int length;
    };

    Result recurse(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }
        const auto l = recurse(node->left);
        const auto r = recurse(node->right);
        const int leftLength = ((node->left != nullptr) && (node->left->val == node->val)) ? (l.length + 1) : 0;
        const int rightLength = ((node->right != nullptr) && (node->right->val == node->val)) ? (r.length + 1) : 0;
        return {
            max(max(l.longest, r.longest), leftLength + rightLength),
            max(leftLength, rightLength)
        };
    }

    int longestUnivaluePath(TreeNode* root) {
        return recurse(root).longest;
    }
};
