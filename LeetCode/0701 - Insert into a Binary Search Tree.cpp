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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode** node = &root;
        while (*node != nullptr) {
            if (val < (*node)->val) {
                node = &(*node)->left;
            }
            else if (val > (*node)->val) {
                node = &(*node)->right;
            }
            else {
                assert(false);
            }
        }
        *node = new TreeNode(val);
        return root;
    }
};
