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
    long long recurse(TreeNode* node, long long prev, long long next) {
        if (node == nullptr) {
            return numeric_limits<long long>::max();
        }
        return min(min(recurse(node->left, prev, node->val),
                       recurse(node->right, node->val, next)),
                   min(node->val - prev,
                       next - node->val));
    }

    int minDiffInBST(TreeNode* root) {
        return static_cast<int>(recurse(root, numeric_limits<long long>::min() / 2, numeric_limits<long long>::max() / 2));
    }
};
