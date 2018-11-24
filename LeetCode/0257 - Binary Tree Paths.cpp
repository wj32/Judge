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
    void recurse(vector<string>* r, string* s, TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        size_t k = s->size();
        if (k != 0) {
            s->append("->");
        }
        s->append(to_string(node->val));

        if ((node->left == nullptr) && (node->right == nullptr)) {
            r->push_back(*s);
        }
        else {
            recurse(r, s, node->left);
            recurse(r, s, node->right);
        }

        s->erase(k);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> r;
        string s;
        recurse(&r, &s, root);
        return r;
    }
};
