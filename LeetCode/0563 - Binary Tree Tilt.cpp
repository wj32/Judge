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
        int tiltSum;
        int valSum;
    };

    Result recurse(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }
        const auto l = recurse(node->left);
        const auto r = recurse(node->right);
        return {l.tiltSum + r.tiltSum + abs(l.valSum - r.valSum), l.valSum + r.valSum + node->val};
    }

    int findTilt(TreeNode* root) {
        return recurse(root).tiltSum;
    }
};
