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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode b(0);
        b.right = root;
        auto link = &b.right;

        while (*link != nullptr) {
            if (key < (*link)->val) {
                link = &(*link)->left;
            }
            else if (key > (*link)->val) {
                link = &(*link)->right;
            }
            else {
                break;
            }
        }

        if (*link == nullptr) {
            return b.right;
        }

        if ((*link)->left == nullptr) {
            *link = (*link)->right;
        }
        else {
            auto link2 = &(*link)->left;
            while ((*link2)->right != nullptr) {
                link2 = &(*link2)->right;
            }

            const auto node2 = *link2;
            node2->right = (*link)->right;
            *link2 = node2->left;
            node2->left = (*link)->left;
            *link = node2;
        }

        return b.right;
    }
};
