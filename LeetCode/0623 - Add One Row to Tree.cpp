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
    void recurse(TreeNode* node, int level, int targetLevel, int newValue) {
        if (node == nullptr) {
            return;
        }
        else if (level == targetLevel) {
            const auto newLeft = new TreeNode(newValue);
            newLeft->left = node->left;
            node->left = newLeft;

            const auto newRight = new TreeNode(newValue);
            newRight->right = node->right;
            node->right = newRight;
        }
        else {
            recurse(node->left, level + 1, targetLevel, newValue);
            recurse(node->right, level + 1, targetLevel, newValue);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode dummy(0);
        dummy.left = root;
        recurse(&dummy, 1, d, v);
        return dummy.left;
    }
};
