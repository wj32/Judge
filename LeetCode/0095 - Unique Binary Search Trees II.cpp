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
    vector<TreeNode*> recurse(int m, int n) {
        if (m > n) {
            return {nullptr};
        }
        else if (m == n) {
            return {new TreeNode(m)};
        }

        vector<TreeNode*> r;

        for (int i = m; i <= n; i++) {
            for (const auto t1 : recurse(m, i - 1)) {
                for (const auto t2 : recurse(i + 1, n)) {
                    const auto t = new TreeNode(i);
                    t->left = t1;
                    t->right = t2;
                    r.push_back(t);
                }
            }
        }

        return r;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        return recurse(1, n);
    }
};
