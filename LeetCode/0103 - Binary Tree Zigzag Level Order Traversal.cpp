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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> r;
        bool alt = false;
        vector<TreeNode*> u;
        vector<TreeNode*> v;

        if (root != nullptr) {
            u.push_back(root);
        }

        while (!u.empty()) {
            r.push_back({});

            for (const auto t : u) {
                r.back().push_back(t->val);
                if (t->left != nullptr) {
                    v.push_back(t->left);
                }
                if (t->right != nullptr) {
                    v.push_back(t->right);
                }
            }

            u.clear();
            swap(u, v);

            if (alt) {
                reverse(r.back().begin(), r.back().end());
            }
            alt = !alt;
        }

        return r;
    }
};
