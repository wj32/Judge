/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root != nullptr) {
            s.push(root);

            while (s.top()->left != nullptr) {
                s.push(s.top()->left);
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        const auto current = s.top();
        s.pop();

        if (current->right != nullptr) {
            s.push(current->right);

            while (s.top()->left != nullptr) {
                s.push(s.top()->left);
            }
        }

        return current->val;
    }

private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
