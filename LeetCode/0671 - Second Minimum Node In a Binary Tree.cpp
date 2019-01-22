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
    void merge(pair<int, int>& p, int x) {
        if (x != -1) {
            if ((p.first == -1) || (p.first >= x)) {
                if (p.first != x) {
                    p.second = p.first;
                }
                p.first = x;
            }
            else if ((p.second == -1) || (p.second >= x)) {
                p.second = x;
            }
        }
    }

    pair<int, int> recurse(TreeNode* node) {
        if (node == nullptr) {
            return {-1, -1};
        }
        pair<int, int> merged = recurse(node->left);
        const auto r = recurse(node->right);
        merge(merged, r.first);
        merge(merged, r.second);
        merge(merged, node->val);
        return merged;
    }

    int findSecondMinimumValue(TreeNode* root) {
        return recurse(root).second;
    }
};
