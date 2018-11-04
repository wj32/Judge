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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> r;
        queue<pair<int, TreeNode*>> q;

        if (root != nullptr) {
            q.push({0, root});
        }

        while (!q.empty()) {
            const auto d = q.front().first;
            const auto t = q.front().second;
            q.pop();

            if (d == r.size()) {
                r.push_back({});
            }
            r.back().push_back(t->val);

            if (t->left != nullptr) {
                q.push({d + 1, t->left});
            }
            if (t->right != nullptr) {
                q.push({d + 1, t->right});
            }
        }

        return r;
    }
};
