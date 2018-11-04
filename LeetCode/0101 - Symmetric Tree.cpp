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
    bool isMirrorTree(TreeNode* p, TreeNode* q) {
        if ((p == nullptr) || (q == nullptr)) {
            return p == q;
        }
        return (p->val == q->val) && isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirrorTree(root->left, root->right);
    }
};
