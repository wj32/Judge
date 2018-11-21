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
    pair<bool, int> recurse(TreeNode* root, int k) {
        if (root == nullptr) {
            return {false, 0};
        }

        const auto l = recurse(root->left, k);
        if (l.first) {
            return l;
        }

        const auto j = k - l.second;
        if (j == 0) {
            return {true, root->val};
        }

        const auto r = recurse(root->right, j - 1);
        if (r.first) {
            return r;
        }

        return {false, l.second + 1 + r.second};
    }

    int kthSmallest(TreeNode* root, int k) {
        const auto result = recurse(root, k - 1);
        assert(result.first);
        return result.second;
    }
};
