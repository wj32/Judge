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
    TreeNode* recurse(TreeNode* node, int prev, int next, int L, int R) {
        if (node == nullptr) {
            return nullptr;
        }
        else if ((next < L) || (R < prev)) {
            return nullptr;
        }
        else if ((L <= prev) && (next <= R)) {
            return node;
        }

        node->left = recurse(node->left, prev, node->val, L, R);
        node->right = recurse(node->right, node->val, next, L, R);

        if (node->val < L) {
            return node->right;
        }
        else if (node->val > R) {
            return node->left;
        }
        else {
            return node;
        }
    }

    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return recurse(root, numeric_limits<int>::min(), numeric_limits<int>::max(), L, R);
    }
};
