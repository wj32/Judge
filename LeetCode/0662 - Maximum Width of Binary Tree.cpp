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
    void recurse(TreeNode* node, int level, int index, vector<pair<int, int>>& ranges) {
        if (node == nullptr) {
            return;
        }

        if (level < ranges.size()) {
            ranges[level].first = min(ranges[level].first, index);
            ranges[level].second = max(ranges[level].second, index);
        }
        else {
            ranges.push_back({index, index});
        }

        recurse(node->left, level + 1, index * 2, ranges);
        recurse(node->right, level + 1, (index * 2) + 1, ranges);
    }

    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<int, int>> ranges;
        recurse(root, 0, 0, ranges);

        int maxWidth = 0;
        for (const auto& p : ranges) {
            maxWidth = max(maxWidth, p.second - p.first);
        }
        return maxWidth + 1;
    }
};
