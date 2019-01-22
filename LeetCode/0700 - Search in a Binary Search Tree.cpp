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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        else if (val < root->val) {
            return searchBST(root->left, val);
        }
        else if (val > root->val) {
            return searchBST(root->right, val);
        }
        else {
            return root;
        }
     }
};
