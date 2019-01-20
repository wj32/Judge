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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> s;
        const auto up = [&](int x) {
            TreeNode* child = nullptr;
            while (!s.empty() && (s.top()->val <= x)) {
                s.top()->right = child;
                child = s.top();
                s.pop();
            }
            return child;
        };
        for (const auto x : nums) {
            const auto node = new TreeNode(x);
            node->left = up(x);
            s.push(node);
        }
        return up(numeric_limits<int>::max());
    }
};
