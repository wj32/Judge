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
    void recurse(vector<vector<int>>* r, vector<int>* v, TreeNode* t, int x) {
        if (t == nullptr) {
            return;
        }

        v->push_back(t->val);

        if ((t->left == nullptr) && (t->right == nullptr)) {
            if (t->val == x) {
                r->push_back(*v);
            }
        }
        else {
            recurse(r, v, t->left, x - t->val);
            recurse(r, v, t->right, x - t->val);
        }

        v->pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> r;
        vector<int> v;
        recurse(&r, &v, root, sum);
        return r;
    }
};
