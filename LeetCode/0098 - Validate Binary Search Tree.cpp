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
    const int minInt = numeric_limits<int>::min();
    const int maxInt = numeric_limits<int>::max();

    bool recurse(TreeNode* node, int low, int high) {
        if ((node->val < low) || (node->val > high)) {
            return false;
        }

        if (node->left != nullptr) {
            if (node->val == minInt) {
                return false;
            }
            if (!recurse(node->left, low, node->val - 1)) {
                return false;
            }
        }

        if (node->right != nullptr) {
            if (node->val == maxInt) {
                return false;
            }
            if (!recurse(node->right, node->val + 1, high)) {
                return false;
            }
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return recurse(root, minInt, maxInt);
    }
};
