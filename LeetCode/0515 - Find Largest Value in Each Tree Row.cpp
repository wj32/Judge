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
    void recurse(TreeNode* node, int level, vector<int>& r) {
        if (node == nullptr) {
            return;
        }

        if (r.size() <= level) {
            r.push_back(node->val);
        }
        else {
            r[level] = max(r[level], node->val);
        }

        recurse(node->left, level + 1, r);
        recurse(node->right, level + 1, r);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> r;
        recurse(root, 0, r);
        return r;
    }
};
