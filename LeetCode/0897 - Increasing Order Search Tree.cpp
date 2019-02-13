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
    pair<TreeNode*, TreeNode*> recurse(TreeNode* node) {
        if (node == nullptr) {
            return {nullptr, nullptr};
        }

        const auto left = node->left;
        const auto right = node->right;

        node->left = nullptr;
        node->right = nullptr;

        TreeNode dummy(0);
        TreeNode* tail = &dummy;

        const auto l = recurse(left);
        if (l.first != nullptr) {
            tail->right = l.first;
            tail = l.second;
        }

        tail->right = node;
        tail = tail->right;

        const auto r = recurse(right);
        if (r.first != nullptr) {
            tail->right = r.first;
            tail = r.second;
        }

        return {dummy.right, tail};
    }

    TreeNode* increasingBST(TreeNode* root) {
        return recurse(root).first;
    }
};
