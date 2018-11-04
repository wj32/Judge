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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<pair<TreeNode*, bool>> s;

        if (root != nullptr) {
            s.push({root, false});
        }

        while (!s.empty()) {
            if (!s.top().second) {
                const auto left = s.top().first->left;
                s.top().second = true;
                if (left != nullptr) {
                    s.push({left, false});
                }
            }
            else {
                r.push_back(s.top().first->val);

                const auto right = s.top().first->right;
                s.pop();
                if (right != nullptr) {
                    s.push({right, false});
                }
            }
        }

        return r;
    }
};
