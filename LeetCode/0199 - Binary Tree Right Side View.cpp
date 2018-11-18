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
    void recurse(vector<int>* r, TreeNode* node, int level) {
        if (r->size() <= level) {
            r->push_back(0);
        }
        (*r)[level] = node->val;
        if (node->left != nullptr) {
            recurse(r, node->left, level + 1);
        }
        if (node->right != nullptr) {
            recurse(r, node->right, level + 1);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> r;
        if (root != nullptr) {
            recurse(&r, root, 0);
        }
        return r;
    }
};
