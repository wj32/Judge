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
    string tree2str(TreeNode* t) {
        if (t == nullptr) {
            return "";
        }
        const auto s = to_string(t->val);
        const auto l = tree2str(t->left);
        const auto r = tree2str(t->right);
        if (!r.empty()) {
            return s + "(" + l + ")(" + r + ")";
        }
        else {
            if (!l.empty()) {
                return s + "(" + l + ")";
            }
            else {
                return s;
            }
        }
    }
};
