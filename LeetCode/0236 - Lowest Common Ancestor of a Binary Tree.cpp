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
    bool exists(TreeNode* root, TreeNode* p) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == p->val) {
            return true;
        }
        if (exists(root->left, p)) {
            return true;
        }
        if (exists(root->right, p)) {
            return true;
        }
        return false;
    }

    enum class Result {
        None,
        LCA,
        P,
        Q,
    };

    pair<Result, TreeNode*> lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return {Result::None, nullptr};
        }
        else if (root->val == p->val) {
            if (exists(root->left, q) || exists(root->right, q)) {
                return {Result::LCA, root};
            }
            else {
                return {Result::P, nullptr};
            }
        }
        else if (root->val == q->val) {
            if (exists(root->left, p) || exists(root->right, p)) {
                return {Result::LCA, root};
            }
            else {
                return {Result::Q, nullptr};
            }
        }
        else {
            const auto l = lca(root->left, p, q);
            switch (l.first) {
            case Result::LCA:
                return l;
            case Result::P:
            case Result::Q:
                if (exists(root->right, (l.first == Result::P) ? q : p)) {
                    return {Result::LCA, root};
                }
                else {
                    return l;
                }
            default:
                break;
            }

            return lca(root->right, p, q);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        const auto result = lca(root, p, q);
        assert(result.first == Result::LCA);
        return result.second;
    }
};
