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
    int recurse(TreeNode* node, int greaterSum) {
        if (node == nullptr) {
            return 0;
        }
        const auto rightSum = recurse(node->right, greaterSum);
        const auto val = node->val;
        node->val += greaterSum + rightSum;
        const auto leftSum = recurse(node->left, node->val);
        return leftSum + val + rightSum;
    }

    TreeNode* convertBST(TreeNode* root) {
        recurse(root, 0);
        return root;
    }
};
