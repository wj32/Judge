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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = nullptr;
        TreeNode** position = &root;
        stack<TreeNode*> s;
        int inorderIndex = 0;

        for (const int x : preorder) {
            const auto node = new TreeNode(x);
            s.push(node);
            *position = node;
            position = &node->left;

            while (!s.empty() && (s.top()->val == inorder[inorderIndex])) {
                position = &s.top()->right;
                inorderIndex++;
                s.pop();
            }
        }

        assert(s.empty());

        return root;
    }
};
