/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void recurse(TreeLinkNode* node, TreeLinkNode* prev) {
        if (node == nullptr) {
            return;
        }
        TreeLinkNode* prevRight = nullptr;
        if (prev != nullptr) {
            prev->next = node;
            prevRight = prev->right;
        }
        if (node->left != nullptr) {
            recurse(node->left, prevRight);
        }
        if (node->right != nullptr) {
            recurse(node->right, node->left);
        }
    }

    void connect(TreeLinkNode* root) {
        recurse(root, nullptr);
    }
};
