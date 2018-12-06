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
    int recurse(TreeNode* root, bool left) {
        if (root == nullptr) {
            return 0;
        }
        if ((root->left == nullptr) && (root->right == nullptr)) {
            return left ? root->val : 0;
        }
        return recurse(root->left, true) + recurse(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return recurse(root, false);
    }
};
