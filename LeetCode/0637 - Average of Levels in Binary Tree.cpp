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
    void recurse(TreeNode* node, int level, vector<pair<double, int>>& levels) {
        if (node == nullptr) {
            return;
        }

        recurse(node->left, level + 1, levels);
        recurse(node->right, level + 1, levels);

        if (level >= levels.size()) {
            levels.resize(level + 1, {0, 0});
        }
        levels[level].first += node->val;
        levels[level].second++;
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<double, int>> levels;
        recurse(root, 0, levels);

        vector<double> r(levels.size());
        for (int i = 0; i < r.size(); i++) {
            r[i] = levels[i].first / levels[i].second;
        }
        return r;
    }
};
