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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<pair<TreeNode*, bool>> s;

        TreeNode dummy(0);
        dummy.right = root;
        s.push({&dummy, false});

        while (!s.empty()) {
            if (s.top().second) {
                if (s.top().first != &dummy) {
                    r.push_back(s.top().first->val);
                }
                s.pop();
            }
            else {
                s.top().second = true;
                if (s.top().first->right != nullptr) {
                    s.push({s.top().first->right, false});
                    while (s.top().first->left != nullptr) {
                        s.push({s.top().first->left, false});
                    }
                }
            }
        }

        return r;
    }
};
