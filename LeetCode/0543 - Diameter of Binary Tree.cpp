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
        int depth;
        int diameter;
    };

    Result recurse(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        const auto l = recurse(root->left);
        const int leftDepth = l.depth + ((root->left != nullptr) ? 1 : 0);
        const auto r = recurse(root->right);
        const int rightDepth = r.depth + ((root->right != nullptr) ? 1 : 0);
        return {max(leftDepth, rightDepth), max(max(leftDepth + rightDepth, l.diameter), r.diameter)};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return recurse(root).diameter;
    }
};
