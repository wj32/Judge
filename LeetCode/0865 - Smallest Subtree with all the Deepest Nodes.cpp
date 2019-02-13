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
    pair<TreeNode*, int> recurse(TreeNode* node, int depth) {
        if ((node->left == nullptr) && (node->right == nullptr)) {
            return {node, depth};
        }
        else if (node->left == nullptr) {
            return recurse(node->right, depth + 1);
        }
        else if (node->right == nullptr) {
            return recurse(node->left, depth + 1);
        }
        else {
            const auto l = recurse(node->left, depth + 1);
            const auto r = recurse(node->right, depth + 1);
            if (l.second < r.second) {
                return r;
            }
            else if (l.second > r.second) {
                return l;
            }
            else {
                return {node, l.second};
            }
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return recurse(root, 0).first;
    }
};
