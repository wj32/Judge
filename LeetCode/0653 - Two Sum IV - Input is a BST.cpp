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
    bool recurse(TreeNode* node, int k, vector<int>& v) {
        if (node == nullptr) {
            return false;
        }

        if (recurse(node->left, k, v)) {
            return true;
        }

        if (binary_search(v.begin(), v.end(), k - node->val)) {
            return true;
        }
        v.push_back(node->val);

        if (recurse(node->right, k, v)) {
            return true;
        }

        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        return recurse(root, k, v);
    }
};
