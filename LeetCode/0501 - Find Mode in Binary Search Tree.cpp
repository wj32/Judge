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
    pair<int, int> recurse(TreeNode* node, long long prev, long long next, int& frequency, unordered_set<int>& modes) {
        if (node == nullptr) {
            return {0, 0};
        }
        const auto l = recurse(node->left, prev, node->val, frequency, modes);
        const auto r = recurse(node->right, node->val, next, frequency, modes);
        const int n = l.second + r.first + 1;
        if ((node->val != prev) && (node->val != next)) {
            if (frequency < n) {
                frequency = n;
                modes.clear();
            }
            if (frequency == n) {
                modes.insert(node->val);
            }
        }
        return {(node->val == prev) ? n : l.first, (node->val == next) ? n : r.second};
    }

    vector<int> findMode(TreeNode* root) {
        int frequency = 0;
        unordered_set<int> modes;
        recurse(root, numeric_limits<long long>::min(), numeric_limits<long long>::max(), frequency, modes);
        return vector<int>(modes.begin(), modes.end());
    }
};
