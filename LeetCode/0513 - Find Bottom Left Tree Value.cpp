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
    struct Result {
        int val;
        int level;
    };

    Result recurse(TreeNode* node, int level) {
        if (node->left == nullptr) {
            if (node->right == nullptr) {
                return {node->val, level};
            }
            else {
                return recurse(node->right, level + 1);
            }
        }
        else {
            const auto l = recurse(node->left, level + 1);
            if (node->right == nullptr) {
                return l;
            }
            else {
                const auto r = recurse(node->right, level + 1);
                return (l.level >= r.level) ? l : r;
            }
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        return recurse(root, 0).val;
    }
};
