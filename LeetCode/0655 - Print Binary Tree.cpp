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
    int height(TreeNode* node) {
        return (node == nullptr) ? 0 : (max(height(node->left), height(node->right)) + 1);
    }

    void fill(TreeNode* node, vector<vector<string>>& r, int row, int col, int quarterSpan) {
        if (node == nullptr) {
            return;
        }
        r[row][col] = to_string(node->val);
        fill(node->left, r, row + 1, col - 1 - quarterSpan, quarterSpan / 2);
        fill(node->right, r, row + 1, col + 1 + quarterSpan, quarterSpan / 2);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        const int h = height(root);
        vector<vector<string>> r(h, vector<string>((1 << h) - 1));
        const int halfSpan = (1 << (h - 1)) - 1;
        fill(root, r, 0, halfSpan, halfSpan / 2);
        return r;
    }
};
