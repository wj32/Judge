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
    void recurse(TreeLinkNode* node, TreeLinkNode* first) {
        if (node == nullptr) {
            return;
        }

        if (first == nullptr) {
            first = node;
        }

        if (first != node) {
            TreeLinkNode* last = first;
            while (last->next != nullptr) {
                last = last->next;
            }
            last->next = node;
        }

        if ((node->left != nullptr) || (node->right != nullptr)) {
            TreeLinkNode* firstDown = nullptr;
            TreeLinkNode* next = first;
            while (true) {
                firstDown = next->left;
                if (firstDown != nullptr) {
                    break;
                }
                firstDown = next->right;
                if (firstDown != nullptr) {
                    break;
                }
                next = next->next;
            }

            recurse(node->left, firstDown);
            recurse(node->right, firstDown);
        }
    }

    void connect(TreeLinkNode *root) {
        recurse(root, root);
    }
};
