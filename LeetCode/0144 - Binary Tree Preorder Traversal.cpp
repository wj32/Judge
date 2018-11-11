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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<TreeNode*> s;

        if (root != nullptr) {
            s.push(root);
        }

        while (!s.empty()) {
            root = s.top();
            s.pop();
            do {
                r.push_back(root->val);
                if (root->right != nullptr) {
                    s.push(root->right);
                }
                root = root->left;
            } while (root != nullptr);
        }

        return r;
    }
};
