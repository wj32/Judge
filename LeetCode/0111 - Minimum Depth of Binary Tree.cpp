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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        else if ((root->left != nullptr) && (root->right != nullptr)) {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
        else if (root->left != nullptr) {
            return 1 + minDepth(root->left);
        }
        else if (root->right != nullptr) {
            return 1 + minDepth(root->right);
        }
        else {
            return 1;
        }
    }
};
