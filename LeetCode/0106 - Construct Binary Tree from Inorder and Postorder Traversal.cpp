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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode dummy(0);
        stack<TreeNode*> s;
        int postorderIndex = 0;

        s.push(&dummy);

        for (const int x : inorder) {
            const auto node = new TreeNode(x);
            node->left = s.top()->right;
            s.top()->right = node;
            s.push(node);

            while ((s.top() != &dummy) && (s.top()->val == postorder[postorderIndex])) {
                s.pop();
                postorderIndex++;
            }
        }

        s.pop();
        assert(s.empty());

        return dummy.right;
    }
};
