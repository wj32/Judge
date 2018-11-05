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
    TreeNode* recurse(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        const auto leftTail = recurse(node->left);
        const auto rightHead = node->right;
        const auto rightTail = recurse(node->right);
        TreeNode* tail = node;
        if (node->left != nullptr) {
            tail->right = node->left;
            tail = leftTail;
            node->left = nullptr;
        }
        if (rightHead != nullptr) {
            tail->right = rightHead;
            tail = rightTail;
        }
        return tail;
    }

    void flatten(TreeNode* root) {
        (void)recurse(root);
    }
};
