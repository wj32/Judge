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
    bool areSame(TreeNode* s, TreeNode* t) {
        if ((s == nullptr) || (t == nullptr)) {
            return s == t;
        }
        else {
            return (s->val == t->val) && areSame(s->left, t->left) && areSame(s->right, t->right);
        }
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) {
            return t == nullptr;
        }
        if (areSame(s, t)) {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
