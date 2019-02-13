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
    void leafSequence(TreeNode* node, vector<int>& sequence) {
        if (node == nullptr) {
            return;
        }
        if ((node->left == nullptr) && (node->right == nullptr)) {
            sequence.push_back(node->val);
        }
        else {
            leafSequence(node->left, sequence);
            leafSequence(node->right, sequence);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1;
        leafSequence(root1, s1);
        vector<int> s2;
        leafSequence(root2, s2);
        return s1 == s2;
    }
};
